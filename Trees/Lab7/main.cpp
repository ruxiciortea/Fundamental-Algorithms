//
//  main.cpp
//  Lab7
//
//  Created by Ruxandra Ciortea on 11.11.2021.
//

#include "prints.hpp"

int main(int argc, const char * argv[]) {
  
  int parentsVector[10] = {8, 2, 7, 5, 2, 7, 1, -1, 5, 2};
  int parentsVectorSize = 10;
  int root = -1;
  
  for (int i = 0; i < parentsVectorSize; i++) {
    if (parentsVector[i] == -1) {
      root = i;
      break;
    }
  }
  
  cout << "Printing from the parents vector:\n";
  printFromParentVector(parentsVector, parentsVectorSize, 0, root);
  
//  Node2* r2tree = createNode2(7);
//
//  addChild(r2tree, 7, 2);
//  addChild(r2tree, 7, 5);
//  addChild(r2tree, 7, 6);
//
//  addChild(r2tree, 2, 1);
//  addChild(r2tree, 2, 4);
//  addChild(r2tree, 2, 9);
//
//  addChild(r2tree, 5, 3);
//  addChild(r2tree, 5, 8);
//
//  addChild(r2tree, 8, 0);
//
//  cout << "\nPrinting r2tree:\n";
//  printFromNode2(r2tree, 0);
  
  Node2 *treeNode2 = transformationR2(parentsVector, parentsVectorSize);
  cout << "\nPrinting the tree obtained from transforming the parents vector into a Node2:\n";
  printFromNode2(treeNode2, 0);
  
  Node3 *treeNode3 = transformationFromNode2ToNode3(treeNode2);
  cout << "\nPrinting the tree obtained from transforming the Node2 vector into a Node3:\n";
  printFromNode3(treeNode3, 0);
}
