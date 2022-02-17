//
//  main.cpp
//  Lab6
//
//  Created by Ruxandra Ciortea on 04.11.2021.
//

#include "calculations.hpp"

void displayResults(Entry *hash[], float fillingFactor) {
  int IDs[maxIDsize];
  generate(hash, maxHashSize, fillingFactor, IDs);
  
  // Average effort
  long double effortFoundAverage = 0;
  long double effortNotFoundAverage = 0;
  
  for (int i = 0; i < 5; i++) {
    effortFoundAverage += averageEffortFound(hash, IDs, fillingFactor);
    effortNotFoundAverage += averageEffortNotFound(hash, IDs, fillingFactor);
  }
  
  effortFoundAverage /= 5;
  effortNotFoundAverage /= 5;
  
  // Max effort
  int effortFound[maxIDsize];
  int effortNotFound[maxIDsize];
  int effortFoundMax = maxEffortFound(hash, IDs, fillingFactor, effortFound);
  int effortNotFoundMax = maxEffortNotFound(hash, IDs, fillingFactor, effortNotFound);
  
  cout << "Filling factor of " << fillingFactor << ":\n\n";
  cout << "Average effort found: "<< effortFoundAverage << "\n";
  cout << "Average effort not found: "<< effortNotFoundAverage << "\n";
  cout << "Max effort found: "<< effortFoundMax << "\n";
  cout << "Max effort not found: "<< effortNotFoundMax << "\n\n\n\n";
}

void display(float a, float b, int c, int d, float fillingFactor) {
  cout << "Filling factor of " << fillingFactor << ":\n\n";
  cout << "Average effort found: "<< a << "\n";
  cout << "Average effort not found: "<< b << "\n";
  cout << "Max effort found: "<< c << "\n";
  cout << "Max effort not found: "<< d << "\n\n\n\n";
}

int main(int argc, const char * argv[]) {
  
  Entry *hash8[maxHashSize] = {NULL};
  Entry *hash85[maxHashSize] = {NULL};
  Entry *hash9[maxHashSize] = {NULL};
  Entry *hash95[maxHashSize] = {NULL};
  Entry *hash99[maxHashSize] = {NULL};
  
  displayResults(hash8, 0.8);
  displayResults(hash85, 0.85);
  displayResults(hash9, 0.9);
  displayResults(hash95, 0.95);
  displayResults(hash99, 0.99);

  demo();
}

