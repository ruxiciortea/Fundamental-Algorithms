//
//  HeapOperations.cpp
//  Lab5
//
//  Created by Ruxandra Ciortea on 31.10.2021.
//

#include "HeapOperations.hpp"

Profiler p("profiler");

void heapify(list<int> heap[], int size, int root, Operation operation) {
    int smallest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;
    
    // if the left chiled is bigger
    if ((left < size) && heap[left].front() < heap[smallest].front()) {
        operation.count();
        smallest = left;
    }
    
    if (left >= size) {
        operation.count();
    }
    
    // if the right child is bigger
    if ((right < size) && heap[right] < heap[smallest]) {
        operation.count();
        smallest = right;
    }
    
    if (right >= size) {
        operation.count();
    }
    
    // now largest contains the index of the max between the root and the two children and
    // if the maximum is not the root, we swap them and repeat the process
    if (smallest != root) {
        swap(heap[root], heap[smallest]);
        operation.count(3);
        
        heapify(heap, size, smallest, operation);
    }
}

void bottomUpBuild(list<int> heap[], int size, Operation operation) {
    for (int i = size / 2; i >= 0; i--) {
        heapify(heap, size, i, operation);
    }
}

void printHeap(list<int> heap[], int heapSize) {
    for (int i = 0; i < heapSize; i++) {
        for (auto j: heap[i]) {
            cout << j << " ";
        }
        
        cout << endl;
    }
}
