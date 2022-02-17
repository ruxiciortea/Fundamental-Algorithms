//
//  graphOperations.cpp
//  Lab9
//
//  Created by Ruxandra Ciortea on 29.11.2021.
//

#include "graphOperations.hpp"

void selectionSort(Edge *array[], int numberElements) {
    int index;
    
    for (int i = 0; i < numberElements - 1; i++) {
        // we use the index to remember the location of the minimum element;
        index = i;
        
        for (int j = i + 1; j < numberElements; j++) {
            if (array[j] -> cost < array[index] -> cost) {
                index = j;
            }
        }
        
        // if the minimum is already at the right place, we don't need to swap
        if (index != i) {
            Edge *aux = array[index];
            array[index] = array[i];
            array[i] = aux;
        }
    }
}

// MARK: - Graph Functions
Edge* makeEdge(int source, int target, int cost) {
  Edge *edge = (Edge*)calloc(1, sizeof(Edge));
  edge -> source = source;
  edge -> target = target;
  edge -> cost = cost;
  
  return edge;
}

void kruskal(int numberNodes, Edge *edges[], int numberEdges, Edge *solution[], int &solutionSize, Operation operation) {
  Node *nodes[10001];
  for (int i = 1; i <= numberNodes; i++) {
    nodes[i] = makeSet(i);
  }
  
  solutionSize = 0;
  selectionSort(edges, numberEdges);
  
  for (int i = 0; i < numberEdges; i++) {
    Edge *currentEdge = edges[i];
    Node *source = findSet(nodes[currentEdge -> source], operation);
    Node *destination = findSet(nodes[currentEdge -> target], operation);
    operation.count(3);
    
    operation.count();
    if (source != destination) {
      unite(nodes[currentEdge -> source], nodes[currentEdge -> target], operation);
      solutionSize++;
      solution[solutionSize - 1] = currentEdge;
      operation.count();
      
      if (solutionSize == numberNodes - 1) {
        break;
      }
    }
  }
}
