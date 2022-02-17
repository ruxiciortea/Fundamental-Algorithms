//
//  prints.cpp
//  Lab7
//
//  Created by Ruxandra Ciortea on 17.11.2021.
//

#include "prints.hpp"

int findRootFromParentsVector(int parents[], int size) {
  for (int i = 0; i < size; i++) {
    if (parents[i] == -1) {
      return i;
    }
  }
  
  return -1;
}

void printFromParentVector(int parents[], int size, int level, int root) {
  for (int i = 0; i < level; i++) {
    cout << " ";
  }
  cout << root << "\n";
  
  for (int i = 0; i < size; i++) {
    if (parents[i] == root) {
      printFromParentVector(parents, size, level + 5, i);
    }
  }
}

void printFromNode2(Node2 *r2tree, int level) {
  for (int i = 0; i < level; i++) {
    cout << " ";
  }
  cout << r2tree -> value << "\n";
  
  for (int i = 0; i < r2tree -> childrenSize; i++) {
    printFromNode2((r2tree -> children)[i], level + 5);
  }
}

void printFromNode3(Node3 *r3tree, int level) {
  for (int i = 0; i < level; i++) {
    cout << " ";
  }
  cout << r3tree -> value << "\n";
  
  if (r3tree -> leftChild) {
    printFromNode3(r3tree -> leftChild, level + 5);
  }
  
  if (r3tree -> rightSibling) {
    printFromNode3(r3tree -> rightSibling, level);
  }
}
