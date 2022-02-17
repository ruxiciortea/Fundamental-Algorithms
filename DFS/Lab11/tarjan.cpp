//
//  tarjan.cpp
//  Lab11
//
//  Created by Ruxandra Ciortea on 11.12.2021.
//

#include "tarjan.hpp"

int currnetIndex = 1;
list<NodeT*> stack;

NodeT* initNodeT(int value) {
  NodeT *node = (NodeT*)calloc(1, sizeof(NodeT));
  node -> value = value;
  node -> parent = NULL;
  node -> color = white;
  node -> neighboursSize = 0;
  
  node -> printed = false;
    
  return node;
}

void dfs(NodeT *node, NodeT *parent) {
  stack.push_back(node);

  node -> color = grey;
  node -> parent = parent;
  node -> index = currnetIndex;
  node -> lowlink = currnetIndex;
  currnetIndex++;
  
  for (int i = 0; i < node -> neighboursSize; i++) {
    NodeT *neightbour = node -> neighbours[i];
    
    if (neightbour -> color == white) {
      dfs(neightbour, node);
      node -> lowlink = min(node -> lowlink, neightbour -> lowlink);
    }
    
    if (neightbour -> color == grey) {
      node -> lowlink = min(node -> lowlink, neightbour -> index);
    }
  }
  
  node -> color = black;
  
  if (node -> index == node -> lowlink) {
    NodeT *p = (NodeT*)calloc(1, sizeof(NodeT));
    do {
      p = stack.back();
      stack.pop_back();
      cout << p -> value << " ";
    } while (p != node);
    
    cout << endl;
  }
}

void tarjan(NodeT *nodes[], int numberNodes) {
  for (int i = 1; i <= numberNodes; i++) {
    if (nodes[i] -> color == white) {
      dfs(nodes[i], NULL);
    }
  }
}

void printResultTarjan(NodeT *nodes[], int numberNodes) {
  for (int i = numberNodes; i >= 1; i--) {
    bool needsNewLine = false;
    NodeT *currentNode = nodes[i];
    
    while (currentNode != NULL) {
      if (currentNode -> printed == false) {
        cout << currentNode -> value << " ";
        currentNode -> printed = true;
        needsNewLine = true;
      }
      
      currentNode = currentNode -> parent;
    }
    
    if (needsNewLine) {
      cout << endl;
    }
  }
}
