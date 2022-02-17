//
//  BST.hpp
//  Lab8
//
//  Created by Ruxandra Ciortea on 20.11.2021.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include <iostream>
#include "Profiler.h"

using namespace std;

#endif /* Node_hpp */

extern Profiler p;

typedef struct node {
  int value;
  int size; // how many nodes are in total below the current node (and including the current node)
  node *left;
  node *right;
  node *parent;
} Node;

Node* buildTree(int n);

Node* OSSelect(Node *root, int i);
void OSDelete(Node *root, int i);

void prettyPrint(Node* root, int space);
