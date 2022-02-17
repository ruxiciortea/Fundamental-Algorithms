//
//  operations.cpp
//  Lab6
//
//  Created by Ruxandra Ciortea on 04.11.2021.
//

#include "operations.hpp"

Entry* initEntry(int id, char name[]) {
  Entry *entry = (Entry*)malloc(sizeof(Entry));
  
  entry -> id = id;
  strcpy(entry -> name, name);
  
  return entry;
}

int hashing(int id, int size, int i) {
  int c1 = 3;
  int c2 = 5;
  int hash = (id + (c1 * i) + (c2 * i * i)) % size;
  return hash;
}

void insert(Entry *hash[], int sizeHash, Entry *entry) {
  for (int i = 0; i < sizeHash; i++) {
    int index = hashing(entry -> id, sizeHash, i);
    
    if (hash[index] == NULL) {
      hash[index] = entry;
      return;
    } else if (hash[index] -> id == entry -> id) {
      // the element at the position in the array has the same index as the entry, in this case we consider we just want to update the existing element with the new entry
      hash[index] = entry;
      return;
    }
  }
}

int search(Entry *hash[], int sizeHash, int id) {
  int i = 0;
  int index = hashing(id, sizeHash, i);
  int accessCount = 1;

  while (i < sizeHash && hash[index] != NULL) {
    if (hash[index] -> id == id) {
      break;
    }

    index = hashing(id, sizeHash, i);
    accessCount++;
    i++;
  }

  return accessCount;
}

Entry* search2(Entry *hash[], int sizeHash, int id) {
  int i = 0;
  int index = hashing(id, sizeHash, i);

  while (i < sizeHash && hash[index] != NULL) {
    if (hash[index] -> id == id) {
      return hash[index];
    }

    index = hashing(id, sizeHash, i);
    i++;
  }

  return NULL;
}

int numberElementsFor(float fillingFactor, int hashSize) {
  return int(fillingFactor * hashSize);
}

void generate(Entry *hash[], int hashSize, float fillingFactor, int IDs[]) {
  // inserting the random elements in the hash
  int numberElements = numberElementsFor(fillingFactor, hashSize);
  // we generate double the number of elements so that we can know that from numberElements + 1 to 2 * numberElements we won't find the entries in the hash
  FillRandomArray(IDs, numberElements + 1500, 0, maxID, true, UNSORTED);
  
  for (int i = 0; i < numberElements; i++) {
    Entry *newEntry = initEntry(IDs[i], "");
    insert(hash, hashSize, newEntry);
  }
}

int maxArray(int array[], int numberElements) {
  int max = 0;
  
  for (int i = 0; i < numberElements; i++) {
    if (array[i] > max) {
      max = i;
    }
  }
  
  return array[max];
}

void demo() {
  Entry *hash[101] = {NULL};
  
  Entry *person1 = initEntry(1, "Ana");
  Entry *person2 = initEntry(2, "Vasile");
  Entry *person3 = initEntry(3, "Teodora");
  Entry *person4 = initEntry(4, "Alexia");
  Entry *person5 = initEntry(4, "Marin");
  Entry *person6 = initEntry(5, "Cristian");
  
  insert(hash, 101, person1);
  insert(hash, 101, person2);
  insert(hash, 101, person3);
  insert(hash, 101, person4);
  insert(hash, 101, person5);
  insert(hash, 101, person6);
  
  Entry *foundPerson1 = search2(hash, 101, 1);
  Entry *foundPerson2 = search2(hash, 101, 2);
  Entry *foundPerson3 = search2(hash, 101, 3);
  Entry *foundPerson4 = search2(hash, 101, 7);
  Entry *foundPerson5 = search2(hash, 101, 8);
}

