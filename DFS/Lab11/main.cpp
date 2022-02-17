//
//  main.cpp
//  Lab11
//
//  Created by Ruxandra Ciortea on 09.12.2021.
//

#include "dfs.hpp"
#include "tarjan.hpp"
#include "topologicalSort.hpp"

void dfsDemo();
void tarjanDemo();
void topoDemo();

int main(int argc, const char * argv[]) {
  
  dfsDemo();
  tarjanDemo();
  topoDemo();
  
  generateGraphs1();
  generateGraphs2();
}

void dfsDemo() {
  Node *nodes[100];
  int numberNodes = 8;
  
  for (int i = 1; i <= 8; i++) {
    nodes[i] = initNode(i);
  }
  
  nodes[1] -> neighbours[0] = nodes[2];
  nodes[1] -> neighboursSize = 1;
  
  nodes[2] -> neighbours[0] = nodes[3];
  nodes[2] -> neighboursSize = 1;
  
  nodes[3] -> neighbours[0] = nodes[1];
  nodes[3] -> neighboursSize = 1;
  
  nodes[4] -> neighbours[0] = nodes[2];
  nodes[4] -> neighbours[1] = nodes[3];
  nodes[4] -> neighbours[2] = nodes[5];
  nodes[4] -> neighboursSize = 3;
  
  nodes[5] -> neighbours[0] = nodes[4];
  nodes[5] -> neighbours[1] = nodes[6];
  nodes[5] -> neighboursSize = 2;
  
  nodes[6] -> neighbours[0] = nodes[7];
  nodes[6] -> neighboursSize = 1;
  
  nodes[7] -> neighbours[0] = nodes[6];
  nodes[7] -> neighboursSize = 1;
  
  nodes[8] -> neighbours[0] = nodes[5];
  nodes[8] -> neighbours[1] = nodes[7];
  nodes[8] -> neighbours[2] = nodes[8];
  nodes[8] -> neighboursSize = 3;
 
  Operation demoOperation = p.createOperation("DemoOperation", numberNodes);
  dfsInit(nodes, numberNodes, demoOperation);
  cout << "DFS:\n";
  printResultDfs(nodes, numberNodes);
  cout << "\n\n";
}

void tarjanDemo() {
  NodeT *nodes[100];
  int numberNodes = 8;
  
  for (int i = 1; i <= 8; i++) {
    nodes[i] = initNodeT(i);
  }
  
  nodes[1] -> neighbours[0] = nodes[2];
  nodes[1] -> neighboursSize = 1;
  
  nodes[2] -> neighbours[0] = nodes[3];
  nodes[2] -> neighboursSize = 1;
  
  nodes[3] -> neighbours[0] = nodes[1];
  nodes[3] -> neighboursSize = 1;
  
  nodes[4] -> neighbours[0] = nodes[2];
  nodes[4] -> neighbours[1] = nodes[3];
  nodes[4] -> neighbours[2] = nodes[5];
  nodes[4] -> neighboursSize = 3;
  
  nodes[5] -> neighbours[0] = nodes[4];
  nodes[5] -> neighbours[1] = nodes[6];
  nodes[5] -> neighboursSize = 2;
  
  nodes[6] -> neighbours[0] = nodes[7];
  nodes[6] -> neighboursSize = 1;
  
  nodes[7] -> neighbours[0] = nodes[6];
  nodes[7] -> neighboursSize = 1;
  
  nodes[8] -> neighbours[0] = nodes[5];
  nodes[8] -> neighbours[1] = nodes[7];
  nodes[8] -> neighbours[2] = nodes[8];
  nodes[8] -> neighboursSize = 3;
  
  cout << "TARJAN:\n";
  tarjan(nodes, numberNodes);
//  printResultTarjan(nodes, numberNodes);
  cout << "\n\n";
}

void topoDemo() {
  NodeTopo *nodes[100];
  int numberNodes = 8;
  
  for (int i = 1; i <= 9; i++) {
    nodes[i] = initNodeTopo(i);
  }
  
  nodes[1] -> neighbours[0] = nodes[2];
  nodes[1] -> neighbours[1] = nodes[4];
  nodes[1] -> neighboursSize = 2;
  
  nodes[2] -> neighbours[0] = nodes[3];
  nodes[2] -> neighboursSize = 1;
  
  nodes[3] -> neighboursSize = 0;
  
  nodes[4] -> neighbours[0] = nodes[3];
  nodes[4] -> neighboursSize = 1;
  
  nodes[5] -> neighboursSize = 0;
  
  nodes[6] -> neighbours[0] = nodes[7];
  nodes[6] -> neighbours[1] = nodes[9];
  nodes[6] -> neighboursSize = 2;
  
  nodes[7] -> neighbours[0] = nodes[4];
  nodes[7] -> neighboursSize = 1;
  
  nodes[8] -> neighbours[0] = nodes[9];
  nodes[8] -> neighboursSize = 1;
 
  cout << "TOPOLOGICAL SORT:\n";
  topologicalSort(nodes, numberNodes);
}
