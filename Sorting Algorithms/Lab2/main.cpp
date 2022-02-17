//
//  main.cpp
//  Lab2
//
//  Created by Ruxandra Ciortea on 07.10.2021.
//

/*
 You are required to implement correctly and efficiently 3 direct sorting methods (Bubble Sort, Insertion Sort – using either linear or binary insertion and Selection Sort)
 Use p.createGroup to display more functions in the same graphic
*/

#include <iostream>
#include "Profiler.h"
using namespace std;

Profiler p("sorting_methods");

// MARK: - Sorting Methods

void insertionSort(int array[], int numberElements) {
    Operation assignment = p.createOperation("assign_insertion", numberElements);
    Operation comparison = p.createOperation("comp_insertion", numberElements);
    
    for (int i = 1; i < numberElements; i++) {
        // we save the first element from the unsorted part of the array
        int elementToBePlaced = array[i];
        assignment.count();
        
        int j = i - 1;
        
        while (j >= 0 && elementToBePlaced < array[j]) {
            comparison.count();
            
            array[j + 1] = array[j];
            assignment.count();
            
            j--;
        }
        
        if (j >= 0) {
            comparison.count();
        }
        
        /* We check this because in the case that our element was in the right spot to begin with. In that case, we don't want to move it anymore so we just get to the next one without doing anything. */
        if (j != i - 1) {
            // array[j + 1] because j was decremented one more time in the while
            array[j + 1] = elementToBePlaced;
            assignment.count();
        }
    }
}

void selectionSort(int array[], int numberElements) {
    /* worst case: 2, 3, 4, 5, 6, 7, 8, ..., n, 1 */
    Operation assignment = p.createOperation("assign_selection", numberElements);
    Operation comparison = p.createOperation("comp_selection", numberElements);
    
    int index;
    
    for (int i = 0; i < numberElements - 1; i++) {
        // we use the index to remember the location of the minimum element;
        index = i;
        
        for (int j = i + 1; j < numberElements; j++) {
            comparison.count();
            if (array[j] < array[index]) {
                index = j;
            }
        }
        
        // if the minimum is already at the right place, we don't need to swap
        if (index != i) {
            int aux = array[index];
            array[index] = array[i];
            array[i] = aux;
            
            assignment.count(3);
        }
    }
}

void bubbleSort(int array[], int numberElements) {
    Operation assignment = p.createOperation("assign_bubble", numberElements);
    Operation comparison = p.createOperation("comp_bubble", numberElements);
    
    bool swapped = false;
    /* this index counts the number of steps we made so far (how many sprted elemetns we have at the end of the array) */
    int i = 0;
    
    do {
        swapped = false;
        
        for (int j = 0; j < numberElements - 1 - i; j++) {
            comparison.count();
            if (array[j] > array[j + 1]) {
                int aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
                assignment.count(3);
                
                swapped = true;
            }
        }
        
        /* We use this index so we can ignore the elemnts at the end of the array because we already know they are sorted. */
        i++;
    } while (swapped); // when no swaps are performed anymore, we can stop
}

// MARK: - Array Operations

void printArray(int array[], int numberElements) {
    for (int i = 0; i < numberElements; i++) {
        cout << array[i] << " ";
    }
    
    cout << "\n";
}

void copyArray(int source[], int destination[], int numberElements) {
    for (int i = 0; i < numberElements; i++) {
        destination[i] = source[i];
    }
}

// MARK: - Profiler Operations

void generateBest() {
    int sortedArray[10000];
    
    for (int n = 100; n < 5000; n += 100) {
        for (int i = 0; i < 5; i++) {
            FillRandomArray(sortedArray, n, 10, 50000, false, ASCENDING);
            insertionSort(sortedArray, n);
            selectionSort(sortedArray, n);
            bubbleSort(sortedArray, n);
        }
    }
    
    p.divideValues("assign_insertion", 5);
    p.divideValues("comp_insertion", 5);
    p.divideValues("assign_selection", 5);
    p.divideValues("comp_selection", 5);
    p.divideValues("assign_bubble", 5);
    p.divideValues("comp_bubble", 5);

    p.addSeries("insertion_best", "assign_insertion", "comp_insertion");
    p.addSeries("selection_best", "assign_selection", "comp_selection");
    p.addSeries("bubble_best", "assign_bubble", "comp_bubble");

    p.createGroup("best_assign", "assign_insertion", "assign_selection", "assign_bubble");
    p.createGroup("best_comp", "comp_insertion", "comp_selection", "comp_bubble");
    p.createGroup("best_total", "insertion_best", "selection_best", "bubble_best");
    
    p.reset();
}

void generateAverage() {
    int randomArray[10000];
    int copyOfRanodmArray[10000];

    for (int n = 100; n < 5000; n += 100) {
        for (int i = 0; i < 5; i++) {
            FillRandomArray(randomArray, n, 10, 50000, false, UNSORTED);
            copyArray(randomArray, copyOfRanodmArray, n);

            insertionSort(randomArray, n);

            copyArray(copyOfRanodmArray, randomArray, n);
            selectionSort(randomArray, n);

            copyArray(copyOfRanodmArray, randomArray, n);
            bubbleSort(randomArray, n);
        }
    }

    p.divideValues("assign_insertion", 5);
    p.divideValues("comp_insertion", 5);
    p.divideValues("assign_selection", 5);
    p.divideValues("comp_selection", 5);
    p.divideValues("assign_bubble", 5);
    p.divideValues("comp_bubble", 5);

    p.addSeries("insertion_average", "assign_insertion", "comp_insertion");
    p.addSeries("selection_average", "assign_selection", "comp_selection");
    p.addSeries("bubble_average", "assign_bubble", "comp_bubble");

    p.createGroup("average_assign", "assign_insertion", "assign_selection", "assign_bubble");
    p.createGroup("average_comp", "comp_insertion", "comp_selection", "comp_bubble");
    p.createGroup("average_total", "insertion_average", "selection_average", "bubble_average");

    p.reset();
}

void generateWorst() {
    int reversedArray[10000];
    int reversedArrayCopy[10000];
    int worstSelection[10000];

    for (int n = 100; n < 10000; n += 100) {
        for (int i = 0; i < 20; i++) {
            FillRandomArray(reversedArray, n, 10, 50000, false, DESCENDING);
            copyArray(reversedArray, reversedArrayCopy, n);
            FillRandomArray(worstSelection, n, 10, 50000, false, ASCENDING);
            worstSelection[0] = 2;
            worstSelection[n-1] = 1;
            
            insertionSort(reversedArray, n);
            selectionSort(worstSelection, n);
            bubbleSort(reversedArrayCopy, n);
        }
    }

    p.divideValues("assign_insertion", 5);
    p.divideValues("comp_insertion", 5);
    p.divideValues("assign_selection", 5);
    p.divideValues("comp_selection", 5);
    p.divideValues("assign_bubble", 5);
    p.divideValues("comp_bubble", 5);
    
    p.addSeries("insertion_worst", "assign_insertion", "comp_insertion");
    p.addSeries("selection_worst", "assign_selection", "comp_selection");
    p.addSeries("bubble_worst", "assign_bubble", "comp_bubble");

    p.createGroup("worst_assign", "assign_insertion", "assign_selection", "assign_bubble");
    p.createGroup("worst_comp", "comp_insertion", "comp_selection", "comp_bubble");
    p.createGroup("worst_total", "insertion_worst", "selection_worst", "bubble_worst");
    
    p.reset();
}

// MARK: - Main

int main(int argc, const char * argv[]) {
    
    int array[5] = {3, 3, 1, 2, 5};
    int arrayCopy1[5] = {3, 3, 1, 2, 5};
    int arrayCopy2[5] = {3, 3, 1, 2, 5};
    
    insertionSort(array, 5);
    selectionSort(arrayCopy1, 5);
    bubbleSort(arrayCopy2, 5);
    
    printf("insertion: ");
    printArray(array, 5);
    printf("\nselection: ");
    printArray(arrayCopy1, 5);
    printf("\nbubble: ");
    printArray(arrayCopy2, 5);
    printf("\n");
    
    generateBest();
    generateAverage();
    generateWorst();
    
}
