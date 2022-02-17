//
//  operations.hpp
//  Lab6
//
//  Created by Ruxandra Ciortea on 04.11.2021.
//

#ifndef operations_hpp
#define operations_hpp

#include <stdio.h>
#include <iostream>
#include <string.h>
#include "Profiler.h"

using namespace std;

#endif /* operations_hpp */

#define maxHashSize 10007
#define maxID 1999999
#define maxIDsize 15000
#define nrSearchedElements 1500

typedef struct {
  int id;
  char name[100];
} Entry;

Entry* initEntry(int id, char name[]);
int hashing(int id, int size, int i);
void insert(Entry *hash[], int sizeHash, Entry *entry);
int search(Entry *hash[], int sizeHash, int id);
Entry* search2(Entry *hash[], int sizeHash, int id);
int numberElementsFor(float fillingFactor, int hashSize);
void generate(Entry **hash, int hashSize, float fillingFactor, int IDs[]);

int maxArray(int array[], int numberElements);
void demo();
