//
//  transformations.cpp
//  Lab7
//
//  Created by Ruxandra Ciortea on 17.11.2021.
//

#include "transformations.hpp"

// MARK: - Node2 operations
Node2* createNode2(int value) {
  Node2 *node = (Node2*)malloc(sizeof(Node2));
  node -> value = value;
  node -> childrenSize = 0;
  
  return node;
}

void addChild(Node2 *r2tree, int parent, int child) {
  if (r2tree -> value == parent) {
    (r2tree -> children)[r2tree -> childrenSize] = createNode2(child);
    r2tree -> childrenSize++;
    
    return;
  }
  
  for (int i = 0; i < r2tree -> childrenSize; i++) {
    addChild((r2tree -> children)[i], parent, child);
  }
}

void addChildForTransformationToNode2(Node2 *parent, Node2 *child) {
  (parent -> children)[parent -> childrenSize] = child;
  parent -> childrenSize++;
}

Node2* transformationR2(int parents[], int size) {
  Node2 *nodesArray[10];
  int rootIndex;
  
  for (int i = 0; i < size; i++) {
    nodesArray[i] = createNode2(i);
  }
  
  for (int i = 0; i < size; i++) {
    if (parents[i] != -1) {
      addChildForTransformationToNode2(nodesArray[parents[i]], nodesArray[i]);
    } else {
      rootIndex = i;
    }
  }
  
  return nodesArray[rootIndex];
}

// MARK: - Node3 operations
Node3* transformationFromNode2ToNode3(Node2 *r2tree) {
  Node3 *tree = (Node3*)calloc(1, sizeof(Node3));
  tree -> value = r2tree -> value; // the root
  
  if (r2tree -> childrenSize != 0) {
    tree -> leftChild = transformationFromNode2ToNode3((r2tree -> children)[0]);
    Node3 *brothers = tree -> leftChild;
    
    for (int i = 1; i < r2tree -> childrenSize; i++) {
      brothers -> rightSibling = transformationFromNode2ToNode3((r2tree -> children)[i]);
      brothers = brothers -> rightSibling;
    }
  }
  
  return tree;
}
