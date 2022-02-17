//
//  main.cpp
//  Lab5
//
//  Created by Ruxandra Ciortea on 31.10.2021.
//
/*
 Merge k sorted lists
 Graphs: 1. one graph with 3 curves for N from 10 -> 10.000
            - k = 5
            - k = 10
            - k = 100
         2. one graph with 1 curve for N = 10.000 and k from 10 -> 500 (10 to 10)
 */

#include "HeapOperations.hpp"

void generate(list<int> heap[], int numberElements, int numberLists, Operation operation) {
    int array[10000];

    // the rest tells us how many lists contain n/k + 1 elements
    int rest = numberElements % numberLists;
    int numberElementsInList = numberElements / numberLists;
    
    // Generating the list that contain n/k + 1 elements
    for (int i = 0; i < rest; i++) {
        FillRandomArray(array, numberElementsInList + 1, 1, 500, false, ASCENDING);
        
        for (int j = 0; j < numberElementsInList + 1; j++) {
            heap[i].push_back(array[j]);
        }
    }
    
    // Generating the lists with n/k elements
    for (int i = rest; i < numberLists; i++) {
        FillRandomArray(array, numberElementsInList, 1, 500, false, ASCENDING);
        
        for (int j = 0; j < numberElementsInList; j++) {
            heap[i].push_back(array[j]);
        }
    }
}

list<int> mergeLists(list<int> heap[], int numberElements, int numberLists, Operation operation) {
    // We generate the lists and build the heap
    generate(heap, numberElements, numberLists, operation);
    bottomUpBuild(heap, numberLists, operation);
    printHeap(heap, numberLists);
    cout << endl;
    
    list<int> solution;
    
    while (numberLists > 1) {
        // if we are left with an empty list we do the same as above
        operation.count();
        if (heap[0].empty()) {
            swap(heap[0], heap[numberLists - 1]);
            operation.count(3);
            numberLists--;
            heapify(heap, numberLists, 0, operation);
        }
        
        // put the head of the root in the solution because that is the current smallest element
        solution.push_back(heap[0].front());
        operation.count();
        
        // remove the head of the root
        heap[0].pop_front();
        operation.count();
        
        // at the end we heapify to bring the smallest element at the top
        heapify(heap, numberLists, 0, operation);
    }
    
    // for the last list left, we just add all the elements as they appear
    if (numberLists == 1) {
        for (auto i: heap[0]) {
            solution.push_back(i);
            operation.count();
        }
    }
    
    return solution;
}

void generateGraph1() {
    list<int> heap[10000];
    int i;
    
    for (i = 100; i <= 10000; i += 100) {
        Operation op5 = p.createOperation("5 lists", i);
        Operation op10 = p.createOperation("10 lists", i);
        Operation op100 = p.createOperation("100 lists", i);
        
        for (int j = 0; j < 20; j++) {
            mergeLists(heap, i, 5, op5);
            mergeLists(heap, i, 10, op10);
            mergeLists(heap, i, 100, op100);
        }
    }
    
    p.divideValues("5 lists", 20);
    p.divideValues("10 lists", 20);
    p.divideValues("100 lists", 20);
    
    p.createGroup("k lists", "5 lists", "10 lists", "100 lists");
    p.reset();
}

void generateGraph2() {
    list<int> heap[1000];
    
    for (int i = 10; i <= 500; i += 10) {
        Operation op = p.createOperation("operations", i);
        
        for (int j = 0; j < 20; j++) {
            mergeLists(heap, 10000, i, op);
        }
    }
    
    p.divideValues("operations", 20);
    
    p.createGroup("operations", "operations");
    p.reset();
}

int main(int argc, const char * argv[]) {
    
    list<int> heap[100]; //we declare the heap as an array of lists containing ints
    list<int> solution;
    int numberElements = 22;
    int numberLists = 6; //this is also the size of the heap

    Operation demoOperation = p.createOperation("demo", numberElements);

    solution = mergeLists(heap, numberElements, numberLists, demoOperation);

    for (auto j: solution) {
        cout << j << " ";
    }

    cout << "\n";
    
//    generateGraph1();
//    generateGraph2();
    
}
