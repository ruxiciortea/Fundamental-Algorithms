//
//  transformations.hpp
//  Lab7
//
//  Created by Ruxandra Ciortea on 17.11.2021.
//

#ifndef transformations_hpp
#define transformations_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

#endif /* transformations_hpp */

typedef struct Node2 {
  int value;
  int childrenSize;
  struct Node2 *children[10];
} Node2;

typedef struct Node3 {
  int value;
  struct Node3 *leftChild;
  struct Node3 *rightSibling;
} Node3;

Node2* createNode2(int value);
void addChild(Node2 *r2tree, int parent, int child);
Node2* transformationR2(int parents[], int size);
Node3* transformationFromNode2ToNode3(Node2 *r2tree);
