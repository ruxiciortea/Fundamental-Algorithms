//
//  setOperations.hpp
//  Lab9
//
//  Created by Ruxandra Ciortea on 29.11.2021.
//

#ifndef setOperations_hpp
#define setOperations_hpp

#include <stdio.h>
#include <iostream>
#include "Profiler.h"

using namespace std;

#endif /* setOperations_hpp */

extern Profiler p;

typedef struct node {
  node *parent;
  int value;
  int depth;
} Node;

/** Returns a new set represented by the node with the value i
 */
Node* makeSet(int i);

/** Returns the root (representing node) of the set the node x is in
 */
Node* findSet(Node *x, Operation operation);

/** Links two sets together
 */
void unite(Node *x, Node *y, Operation operation);

