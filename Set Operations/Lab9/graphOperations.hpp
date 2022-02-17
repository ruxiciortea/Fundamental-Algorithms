//
//  graphOperations.hpp
//  Lab9
//
//  Created by Ruxandra Ciortea on 29.11.2021.
//

#ifndef graphOperations_hpp
#define graphOperations_hpp

#include "setOperations.hpp"

#endif /* graphOperations_hpp */

typedef struct edge {
  int source;
  int target;
  int cost;
} Edge;

Edge* makeEdge(int source, int target, int cost);
void kruskal(int numberNodes, Edge *edges[], int numberEdges, Edge *solution[], int &solutionSize, Operation operation);
