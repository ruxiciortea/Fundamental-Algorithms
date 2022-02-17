//
//  topologicalSort.cpp
//  Lab11
//
//  Created by Ruxandra Ciortea on 13.12.2021.
//

#include "topologicalSort.hpp"

NodeTopo* initNodeTopo(int value) {
  NodeTopo *node = (NodeTopo*)calloc(1, sizeof(NodeTopo));
  node -> value = value;
  node -> parent = NULL;
  node -> color = white;
  node -> neighboursSize = 0;
  
  node -> printed = false;
  
  return node;
}

void dfs(NodeTopo *node, NodeTopo *parent, int solution[], int &solutionSize) {
  node -> color = grey;
  node -> parent = parent;
  
  for (int i = 0; i < node -> neighboursSize; i++) {
    NodeTopo *neightbour = node -> neighbours[i];
    
    if (neightbour -> color == white) {
      dfs(neightbour, node, solution, solutionSize);
    }
  }
  
  node -> color = black;
  solutionSize++;
  solution[solutionSize] = node -> value;
}

void topologicalSort(NodeTopo *nodes[], int numberNodes) {
  int solution[numberNodes];
  int solutionSize = 0;

  for (int i = 1; i <= numberNodes; i++) {
    if (nodes[i] -> color == white) {
      dfs(nodes[i], NULL, solution, solutionSize);
    }
  }
  
  for (int i = solutionSize; i > 0; i--) {
    cout << solution[i] << endl;
  }
}
