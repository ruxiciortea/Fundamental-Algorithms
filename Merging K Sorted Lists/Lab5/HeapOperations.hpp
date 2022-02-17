//
//  HeapOperations.hpp
//  Lab5
//
//  Created by Ruxandra Ciortea on 31.10.2021.
//

#ifndef HeapOperations_hpp
#define HeapOperations_hpp

#include <stdio.h>
#include <iostream>
#include <list>
#include "Profiler.h"

using namespace std;

#endif /* HeapOperations_hpp */

extern Profiler p;

void heapify(list<int> heap[], int size, int root, Operation operation);
void bottomUpBuild(list<int> heap[], int size, Operation operation);
void printHeap(list<int> heap[], int heapSize);
