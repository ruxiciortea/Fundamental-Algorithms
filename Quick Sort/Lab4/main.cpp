//
//  main.cpp
//  Lab4
//
//  Created by Ruxandra Ciortea on 21.10.2021.
//

/* QuickSelect only DEMO
 Comparison between QuickSort and HeapSort
 Best(when the array is sorted and we always choose the middle element) + worst(array is sorted and the pivot is always the last element) + average for QuickSort
 */

#include <iostream>
#include "Profiler.h"
using namespace std;

Profiler p("QuickSort");

// MARK: - Functions
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

// We can take the last element as the pivto but that would make it very inneficinet for the case where the array is sorted. To avoid that, we select the pivot randomly and we move that element at the end of the array.
int partition(int array[], int left, int right, int position, int initialSize) {
    Operation assignment = p.createOperation("assign_partition", initialSize);
    Operation comparison = p.createOperation("comp_partition", initialSize);
    
    if (position != right) {
        swap(array[position], array[right]);
        assignment.count(3);
    }
    
    int separator = left - 1;
    
    for (int j = left; j < right - 1; j++) {
        //if the currnet element is smaller than the pivot
        comparison.count();
        if (array[j] < array[right]) {
            separator++;
            swap(array[separator], array[j]);
            assignment.count(3);
        }
    }
    
    comparison.count();
    if (array[right - 1] < array[right]) {
        separator++;
        swap(array[separator], array[right - 1]);
        assignment.count(3);
    }
    
    separator++;
    swap(array[separator], array[right]);
    assignment.count(3);
    
    return separator;
}

// MARK: - Quick Sort
void quickSortBest(int array[], int left, int right, int initialSize) {
    if (left < right) {
        int pivot = partition(array, left, right, (right + left + 1) / 2, initialSize);
        
        quickSortBest(array, pivot + 1, right, initialSize);
        quickSortBest(array, left, pivot - 1, initialSize);
    }
}

void quickSortAverage(int array[], int left, int right, int initialSize) {
    if (left < right) {
        int position = rand() % (right - left) + left;
        int pivot = partition(array, left, right, position, initialSize);
        
        quickSortAverage(array, pivot + 1, right, initialSize);
        quickSortAverage(array, left, pivot - 1, initialSize);
    }
}

void quickSortWorst(int array[], int left, int right, int initialSize) {
    if (left < right) {
        int pivot = partition(array, left, right, right, initialSize);
        
        quickSortWorst(array, pivot + 1, right, initialSize);
        quickSortWorst(array, left, pivot - 1, initialSize);
    }
}

// MARK: - Quick Select
//algorithm used to fing the i-th smallest element in the array
int quickSelect(int array[], int left, int right, int i, int initialSize) {
    if (left == right) {
        return array[left];
    }
    
    //we check if the position is in our array
    if (i > 0 && i <= (right - left + 1)) {
        int randomIndex = rand() % (right - left) + left;
        int pivot = partition(array, left, right, randomIndex, initialSize);
        int q = pivot - left + 1;
        
        if (q == i) {
            return array[pivot];
        } else if (q < i) {
            return quickSelect(array, pivot + 1, right, i - q, initialSize);
        } else if (q > i) {
            return quickSelect(array, left, pivot - 1, i, initialSize);
        }
    }
    
    return -1;
}

// MARK: - Heap Sort
void heapify(int array[], int size, int root, int initialSize) {
    Operation assignment = p.createOperation("assign_heapify", initialSize);
    Operation comparison = p.createOperation("comp_heapify", initialSize);
    
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
        
        heapify(array, size, largest, initialSize);
    }
}

void bottomUp(int array[], int numberElements) {
    for (int i = numberElements / 2; i >= 0; i--) {
        heapify(array, numberElements, i, numberElements);
    }
}

void heapSort(int array[], int numberElements, int initialSize) {
    bottomUp(array, numberElements);
    
    for (int i = numberElements - 1; i > 0; i--) {
        swap(array[0], array[i]);
        heapify(array, i, 0, initialSize);
    }
}

// MARK: - Generate Functions
void generateBest() {
    int sortedArray[10000];
    
    for (int n = 100; n < 5000; n += 100) {
        for (int i = 0; i < 10; i++) {
            FillRandomArray(sortedArray, n, 10, 50000, false, ASCENDING);
            
            quickSortBest(sortedArray, 0, n - 1, n);
        }
    }
    
    p.divideValues("assign_partition", 10);
    p.divideValues("comp_partition", 10);
    
    p.addSeries("QuickSortBest", "assign_partition", "comp_partition");
    
    p.reset();
}

void generateAverage() {
    int randomArray[10000];
    int randomArrayCopy[10000];
    
    for (int n = 100; n < 5000; n += 100) {
        for (int i = 0; i < 10; i++) {
            FillRandomArray(randomArray, n, 10, 50000, false, UNSORTED);
            CopyArray(randomArrayCopy, randomArray, n);
            
            quickSortAverage(randomArray, 0, n - 1, n);
            heapSort(randomArrayCopy, n, n);
        }
    }
    
    p.divideValues("assign_partition", 10);
    p.divideValues("comp_partition", 10);
    
    p.divideValues("assign_heapify", 10);
    p.divideValues("comp_heapify", 10);
    
    p.addSeries("QuickSortAverage", "assign_partition", "comp_partition");
    p.addSeries("HeapSortAverage", "assign_heapify", "comp_heapify");
    
    p.createGroup("QuickVSHeap", "QuickSortAverage", "HeapSortAverage");
    
    p.reset();
}

void generateWorst() {
    int sortedArray[10000];
    
    for (int n = 100; n < 5000; n += 100) {
        for (int i = 0; i < 10; i++) {
            FillRandomArray(sortedArray, n, 10, 50000, false, ASCENDING);
            
            quickSortWorst(sortedArray, 0, n - 1, n);
        }
    }
    
    p.divideValues("assign_partition", 10);
    p.divideValues("comp_partition", 10);
    
    p.addSeries("QuickSortWorst", "assign_partition", "comp_partition");
    
    p.reset();
}

// MARK: - Main
int main(int argc, const char * argv[]) {
    
    int array[10] = {4, 6, 7, 2, 1, 10 ,9, 13, 21, 5};
    int arrayCopy[10];
    CopyArray(arrayCopy, array, 10);
    
    cout << "Initial array: ";
    printArray(array, 10);
    
    quickSortAverage(array, 0, 9, 10);
    cout << "\nSorted array: ";
    printArray(array, 10);
    
    int i = 10;
    cout << "\nthe " << i << "th element from initial array is: " << quickSelect(arrayCopy, 0, 9, i, 10) << "\n\n";
    
    generateBest();
    generateAverage();
    generateWorst();
}
