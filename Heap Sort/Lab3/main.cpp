//
//  main.cpp
//  Lab3
//
//  Created by Ruxandra Ciortea on 14.10.2021.
//

/* Build heap (Bottom-up and Top-down) -> 3 grafice (op, assig and comp) -> best, average and worst
    Heap sort - just DEMO */

#include <iostream>
#include "Profiler.h"

using namespace std;

Profiler p("HeapSort");

//MARK: - Heapify and Swim
void heapify(int array[], int size, int root) {
    Operation assignment = p.createOperation("assign_heapify", size);
    Operation comparison = p.createOperation("comp_heapify", size);
    
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;
    
    // if the left chiled is bigger
    if ((left < size) && array[left] > array[largest]) {
        comparison.count();
        largest = left;
    }
    
    if (left >= size) {
        comparison.count();
    }
    
    // if the right child is bigger
    if ((right < size) && array[right] > array[largest]) {
        comparison.count();
        largest = right;
    }
    
    if (right >= size) {
        comparison.count();
    }
    
    // now largest contains the index of the max between the root and the two children and
    // if the maximum is not the root, we swap them and repeat the process
    if (largest != root) {
        swap(array[root], array[largest]);
        assignment.count(3);
        
        heapify(array, size, largest);
    }
}

void swim(int array[100], int &size, int position) {
    Operation assignment = p.createOperation("assign_swim", size);
    Operation comparison = p.createOperation("comp_swim", size);
    
    int index = position; // we keep the index of the element we are swimming
    
    // now we can swim it to the right place
    int parent = (index - 1) / 2;
    while (index > 0 && (array[index] > array[parent])) {
        comparison.count();
        // while the new element is not the root and it is smaller than its parent
        swap(array[index], array[(index - 1) / 2]);
        assignment.count(3);
        
        index = (index - 1) / 2; // the index goes to the parent;
        parent = (index - 1) / 2;
    }
    
    if (index > 0) {
        comparison.count();
    }
}

// MARK: - Build Heap
void bottomUp(int array[], int numberElements) {
    for (int i = numberElements / 2; i >= 0; i--) {
        heapify(array, numberElements, i);
    }
}

void topDown(int array[], int numberElements) {
    for (int i = 1; i < numberElements; i++) {
        swim(array, numberElements, i);
    }
}

// MARK: - Heap Sort
void heapSort(int array[], int numberElements) {
    bottomUp(array, numberElements);
    
    for (int i = numberElements - 1; i > 0; i--) {
        swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}

// MARK: - Functions
void insertNewElement(int array[], int &numberElements, int newElement) {
    numberElements++;
    array[numberElements - 1] = newElement;
}

void swap(int &first, int &second) {
    int aux = first;
    first = second;
    second = aux;
}

void printArray(int array[], int numberElements) {
    for (int i = 0; i < numberElements; i++) {
        cout << array[i] << " ";
    }
    
    cout << "\n";
}

// MARK: - Profiler
void generateAverage() {
    int randomArray[10000];
    int randomArrayCopy[10000];

    for (int n = 100; n < 10000; n += 100) {
        for (int i = 0; i < 20; i++) {
            FillRandomArray(randomArray, n, 10, 50000, false, UNSORTED);
            CopyArray(randomArrayCopy, randomArray, n);

            bottomUp(randomArray, n);
            topDown(randomArrayCopy, n);
        }
    }

    p.divideValues("assign_heapify", 20);
    p.divideValues("comp_heapify", 20);
    p.divideValues("assign_swim", 20);
    p.divideValues("comp_swim", 20);

    p.addSeries("BottomUpAverage", "assign_heapify", "comp_heapify");
    p.addSeries("TopDownAverage", "assign_swim", "comp_swim");
    
    p.createGroup("TotalAverage", "BottomUpAverage", "TopDownAverage");
    p.createGroup("AssignmentsAverage", "assign_heapify", "assign_swim");
    p.createGroup("ComparisonsAverage", "comp_heapify", "comp_swim");

    p.reset();
}

// MARK: - Main
int main(int argc, const char * argv[]) {
 
    int size = 11;
    int heap[100] = {5, 16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
    cout << "Initial array:\n";
    printArray(heap, size);

    cout << "\nWe put the root in place using heapify:\n";
    heapify(heap, size, 0);
    printArray(heap, size);

    cout << "\nWe add the element 19 at the end oh the array and we swim it to its place:\n";
    insertNewElement(heap, size, 19);
    swim(heap, size, size - 1);
    printArray(heap, size);

    cout << "\nBuilding the heap bottum up:\n";
    int bottomUpSize = 11;
    int bottomUpHeap[100] = {5, 14, 2, 4, 10, 8, 9, 1, 7, 3, 16};
    printArray(bottomUpHeap, bottomUpSize);
    bottomUp(bottomUpHeap, bottomUpSize);
    printArray(bottomUpHeap, bottomUpSize);

    cout << "\nBuilding the heap top down:\n";
    int topDownSize = 11;
    int topDownHeap[100] = {5, 14, 2, 4, 10, 8, 9, 1, 7, 3, 16};
    printArray(topDownHeap, topDownSize);
    topDown(topDownHeap, topDownSize);
    printArray(topDownHeap, topDownSize);

    cout << "\nHeap sort the array:\n";
    int randomArray[100];
    FillRandomArray(randomArray, 20, 0, 100, false, UNSORTED);
    printArray(randomArray, 20);
    heapSort(randomArray, 20);
    printArray(randomArray, 20);
    
    generateAverage();
    
}
