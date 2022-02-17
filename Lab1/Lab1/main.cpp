//
//  main.cpp
//  Lab1
//
//  Created by Ruxandra Ciortea on 30.09.2021.
//

#include <stdio.h>
#include <iostream>
#include "Profiler.h"

using namespace std;

Profiler p("min_vector");

int minimum(int v[], int n) {
    Operation assignment = p.createOperation("assign", n);
    Operation comparison = p.createOperation("comp", n);
    
    int min = v[0];
    assignment.count();
    
    for (int i = 1; i < n-1; i++) {
        comparison.count();
        if (v[i] < min) {
            min = v[i];
            assignment.count();
        }
    }
    
    return min;
}

void generate() {
    int v[2000];
    
    for (int n = 100; n < 2000; n += 100) {
        for (int i = 0; i < 20; i++) {
            FillRandomArray(v, n, 10, 50000, false, UNSORTED);
            minimum(v, n);
        }
    }
    
    p.divideValues("assign", 20);
    p.divideValues("comp", 20);
    p.addSeries("op", "assign", "comp");
    p.showReport();
}

int main(int argc, const char * argv[]) {
    
    int v[10] = {5, 7, 8, -3, 2};
    int n = 5;
    int min;
    
    min = minimum(v, n);
    
    cout << min << "\n";
    
    generate();
}
