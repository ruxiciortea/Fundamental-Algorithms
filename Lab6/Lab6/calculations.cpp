//
//  calculations.cpp
//  Lab6
//
//  Created by Ruxandra Ciortea on 10.11.2021.
//

#include "calculations.hpp"

long double averageEffortFound(Entry *hash[], int IDs[], float fillingFactor) {
  int numberElements = numberElementsFor(fillingFactor, maxHashSize);
  float uniformityFactor = numberElements / nrSearchedElements;
  
  int index = 0;
  long double countSum = 0;
  
  for (int i = 0; i < nrSearchedElements; i++) {
    int count = search(hash, maxHashSize, IDs[index]);
    countSum += count;
    index += uniformityFactor;
  }
  
  return countSum / nrSearchedElements;
}

long double averageEffortNotFound(Entry *hash[], int IDs[], float fillingFactor) {
  int numberElements = numberElementsFor(fillingFactor, maxHashSize);
  
  long double countSum = 0;
  
  for (int i = numberElements; i < numberElements + 1500; i++) {
    int count = search(hash, maxHashSize, IDs[i]);
    countSum += count;
  }
  
  return countSum / nrSearchedElements;
}

int maxEffortFound(Entry *hash[], int IDs[], float fillingFactor, int effort[]) {
  int numberElements = numberElementsFor(fillingFactor, maxHashSize);
  float uniformityFactor = numberElements / nrSearchedElements + 1;
  
  int step = rand() % (int)uniformityFactor;
  int index = step;
  
  for (int i = 0; i < nrSearchedElements; i++) {
    int count = search(hash, maxHashSize, IDs[index]);
    effort[i] = count;
    index += uniformityFactor - step;
    index += rand() % (int)uniformityFactor;
  }
  
  return maxArray(effort, nrSearchedElements);
}

int maxEffortNotFound(Entry *hash[], int IDs[], float fillingFactor, int effort[]) {
  int numberElements = numberElementsFor(fillingFactor, maxHashSize);
  
  int index = 0;
  
  for (int i = numberElements; i < numberElements + 1500; i++) {
    int count = search(hash, maxHashSize, IDs[i]);
    effort[index] = count;
    index++;
  }
  
  return maxArray(effort, nrSearchedElements);
}
