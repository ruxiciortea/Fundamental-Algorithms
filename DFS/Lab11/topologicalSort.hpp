//
//  topologicalSort.hpp
//  Lab11
//
//  Created by Ruxandra Ciortea on 13.12.2021.
//

#ifndef topologicalSort_hpp
#define topologicalSort_hpp

#include <stdio.h>
#include <iostream>
#include <list>
#include "Colors.h"

using namespace std;

#endif /* topologicalSort_hpp */

typedef struct NodeTopo {
  int value;
  NodeTopo *neighbours[500];
  int neighboursSize;
  NodeTopo *parent;
  Color color;
  
  bool printed;
} NodeTopo;

NodeTopo* initNodeTopo(int value);

void topologicalSort(NodeTopo *nodes[], int numberNodes);
void printResultDfs(NodeTopo *nodes[], int numberNodes);
