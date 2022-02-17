//
//  calculations.hpp
//  Lab6
//
//  Created by Ruxandra Ciortea on 10.11.2021.
//

#ifndef calculations_hpp
#define calculations_hpp

#include <stdio.h>
#include "operations.hpp"

#endif /* calculations_hpp */

long double averageEffortFound(Entry *hash[], int IDs[], float fillingFactor);
long double averageEffortNotFound(Entry *hash[], int IDs[], float fillingFactor);
int maxEffortFound(Entry *hash[], int IDs[], float fillingFactor, int effort[]);
int maxEffortNotFound(Entry *hash[], int IDs[], float fillingFactor, int effort[]);
