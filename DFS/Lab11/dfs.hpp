//
//  dfs.hpp
//  Lab11
//
//  Created by Ruxandra Ciortea on 09.12.2021.
//

#ifndef dfs_hpp
#define dfs_hpp

#include <stdio.h>
#include <iostream>
#include "Colors.h"
#include "Profiler.h"

using namespace std;

#endif /* dfs_hpp */

extern Profiler p;

typedef struct Node {
  int value;
  Node *neighbours[10000];
  int neighboursSize;
  Node *parent;
  Color color;
  
  bool printed;
} Node;

typedef struct edge {
  int source;
  int target;
} Edge;

Node* initNode(int value);

void dfsInit(Node *nodes[], int numberNodes, Operation operation);
void printResultDfs(Node *nodes[], int numberNodes);
void generateGraphs1();
void generateGraphs2();
