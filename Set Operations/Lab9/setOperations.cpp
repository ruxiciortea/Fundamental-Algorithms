//
//  setOperations.cpp
//  Lab9
//
//  Created by Ruxandra Ciortea on 29.11.2021.
//

#include "setOperations.hpp"

Profiler p("operations");

void link(Node *x, Node *y, Operation operation) {
  // We eant to link the node with the smallest depth to the one with bigger depth
  operation.count();
  if (x -> depth > y -> depth) {
    y -> parent = x;
  } else if (y -> depth > x -> depth) {
    operation.count();
    x -> parent = y;
  } else {
    operation.count(2);
    // if they are equal the depth increases with 1
    y -> parent = x;
    (x -> depth)++;
  }
}

// MARK: - Set functions
Node* makeSet(int i) {
  Node *node = (Node*)calloc(1, sizeof(Node));
  
  node -> parent = NULL;
  node -> value = i;
  node -> depth = 1;
  
  return node;
}

Node* findSet(Node *x, Operation operation) {
  operation.count();
  if (x -> parent == NULL) {
    return x;
  } else {
    operation.count();
    Node *parent = findSet(x -> parent, operation);
    x -> parent = parent;
    return parent;
  }
}

void unite(Node *x, Node *y, Operation operation) {
  operation.count();
  if (x == y) {
    return;
  }
  
  link(findSet(x, operation), findSet(y, operation), operation);
}

