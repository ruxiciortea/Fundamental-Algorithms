//
//  prints.hpp
//  Lab7
//
//  Created by Ruxandra Ciortea on 17.11.2021.
//

#ifndef prints_hpp
#define prints_hpp

#include <stdio.h>
#include <list>
#include <iostream>
#include "transformations.hpp"

using namespace std;

#endif /* prints_hpp */

void printFromParentVector(int parents[], int size, int level, int root);
void printFromNode2(Node2 *r2tree, int level);
void printFromNode3(Node3 *r3tree, int level);
