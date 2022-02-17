//
//  dfs.cpp
//  Lab11
//
//  Created by Ruxandra Ciortea on 09.12.2021.
//

#include "dfs.hpp"

Profiler p("operations");

Node* initNode(int value) {
  Node *node = (Node*)calloc(1, sizeof(Node));
  node -> value = value;
  node -> parent = NULL;
  node -> color = white;
  node -> neighboursSize = 0;
  
  node -> printed = false;
  
  return node;
}

void dfs(Node *node, Node *parent, Operation operation) {
  node -> color = grey;
  node -> parent = parent;
  operation.count();
  
  for (int i = 0; i < node -> neighboursSize; i++) {
    operation.count();
    if (node -> neighbours[i] -> color == white) {
      dfs(node -> neighbours[i], node, operation);
    }
  }
  
  node -> color = black;
}

void dfsInit(Node *nodes[], int numberNodes, Operation operation) {
  for (int i = 1; i <= numberNodes; i++) {
    operation.count();
    if (nodes[i] -> color == white) {
      dfs(nodes[i], NULL, operation);
    }
  }
}

void printResultDfs(Node *nodes[], int numberNodes) {
  for (int i = numberNodes; i >= 1; i--) {
    bool needsNewLine = false;
    Node *currentNode = nodes[i];
    
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

// MARK: - Graphs
void addNeighbour(Node *node, Node *neighbour) {
  node -> neighboursSize++;
  node -> neighbours[(node -> neighboursSize) - 1] = neighbour;
}

Edge* makeEdge(int source, int target) {
  Edge *edge = (Edge*)calloc(1, sizeof(Edge));
  edge -> source = source;
  edge -> target = target;
  
  return edge;
}

void generateEdges(Edge *edges[], int &numberEdges, int maxEdges, int numberNodes) {
  int edgePosition = 0;
  int edgePerNode = maxEdges / numberNodes;
  int restEdges = maxEdges % numberNodes;
  
  for (int i = 1; i <= numberNodes; i++) {
    for (int j = 0; j < edgePerNode; j++) {
      int target = rand() % numberNodes + 1;
      Edge *currentEdge = makeEdge(i, target);
      edges[edgePosition] = currentEdge;
      edgePosition++;
      maxEdges--;
    }
    
    if (maxEdges == 0) {
      break;
    }
  }
  
  for (int i = 0; i < restEdges; i++) {
    int source = rand() % numberNodes + 1;
    int target = rand() % numberNodes + 1;
    
    Edge *currentEdge = makeEdge(source, target);
    edges[edgePosition] = currentEdge;
    edgePosition++;
    maxEdges--;
    
    if (maxEdges == 0) {
      break;
    }
  }
  
  numberEdges = edgePosition;
}


void generateGraphs1() {
  for (int i = 1000; i <= 4500; i += 100) {
    Node *nodes[101];
    
    for (int i = 1; i <= 100; i++) {
      nodes[i] = initNode(i);
    }
    
    Edge *edges[5000];
    int numberEdges;
    
    generateEdges(edges, numberEdges, i, 100);
    
    for (int i = 0; i < numberEdges; i++) {
      addNeighbour(nodes[edges[i] -> source], nodes[edges[i] -> target]);
    }
    
    Operation operation = p.createOperation("operation", i);
    dfsInit(nodes, 100, operation);
  }
  
  p.createGroup("operations 100 vertices", "operation");
  p.reset();
}

void generateGraphs2() {
  for (int i = 100; i <= 200; i += 10) {
    Node *nodes[201];
    
    for (int j = 1; j <= i; j++) {
      nodes[j] = initNode(j);
    }
    
    Edge *edges[4500];
    int numberEdges = 4500;
    
    generateEdges(edges, numberEdges, numberEdges, i);
    
    for (int j = 0; j < numberEdges; j++) {
      addNeighbour(nodes[edges[i] -> source], nodes[edges[i] -> target]);
    }
    
    Operation operation = p.createOperation("operation", i);
    dfsInit(nodes, i, operation);
  }
  
  p.createGroup("operations 4500 edges", "operation");
  p.reset();
}
