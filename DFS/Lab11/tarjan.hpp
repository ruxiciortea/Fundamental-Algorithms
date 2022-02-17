//
//  tarjan.hpp
//  Lab11
//
//  Created by Ruxandra Ciortea on 11.12.2021.
//

#ifndef tarjan_hpp
#define tarjan_hpp

#include <stdio.h>
#include <iostream>
#include <list>
#include "Colors.h"

using namespace std;

#endif /* tarjan_hpp */

typedef struct NodeT {
  int value;
  NodeT *neighbours[500];
  int neighboursSize;
  NodeT *parent;
  Color color;
  
  int index;
  int lowlink;
  
  bool printed;
} NodeT;

NodeT* initNodeT(int value);
void tarjan(NodeT *nodes[], int numberNodes);
void printResultTarjan(NodeT *nodes[], int numberNodes);
