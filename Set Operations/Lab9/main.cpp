//
//  main.cpp
//  Lab9
//
//  Created by Ruxandra Ciortea on 28.11.2021.
//

#include "graphOperations.hpp"

void generateEdges(Edge *edges[], int &numberEdges, int numberNodes) {
  int edgePosition = 0;
  int maxNumberEdges = 4 * numberNodes;
  
  // First we make edges from the first node to all the other nodes, to make sure the graph is connexted
  for (int i = 2; i <= numberNodes; i++) {
    edges[edgePosition] = makeEdge(1, i, rand() % 500 + 1);
    edgePosition++;
    maxNumberEdges--;
  }
  
  for (int i = 2; i <= numberNodes; i++) {
    for (int j = i + 1; j <= numberNodes; j++) {
      Edge *currentEdge = makeEdge(i, j, rand() % 500 + 1);
      edges[edgePosition] = currentEdge;
      edgePosition++;
      maxNumberEdges--;
      
      if (maxNumberEdges == 0) {
        break;
      }
    }
    
    if (maxNumberEdges == 0) {
      break;
    }
  }
  
  numberEdges = edgePosition;
}

void printParents(Node *nodes[], int size) {
  for (int i = 1; i <= size; i++) {
    if (nodes[i] -> parent) {
      cout << "The parent of the node " << nodes[i] -> value << " is " << nodes[i] -> parent -> value << endl;
    } else {
      cout << "The node " << nodes[i] -> value << " has no parent :(" << endl;
    }
  }
  
  cout << endl;
}

void generate() {
  Edge *edges[40000];
  
  Edge *solution[10];
  int numberEdges;
  int solutionSize = 0;
  
  for (int n = 100; n < 10000; n += 100) {
    Operation operation = p.createOperation("operation", n);
    
    generateEdges(edges, numberEdges, n);
    kruskal(n, edges, numberEdges, solution, solutionSize, operation);
  }
  
  p.createGroup("operations", "operation");
  p.reset();
}

int main(int argc, const char * argv[]) {
  
  Node *nodes[20];
  Operation demoOperation = p.createOperation("DemoOperation", 10);
  
  for (int i = 1; i <= 20; i++) {
    nodes[i] = makeSet(i);
  }

  for (int i = 1; i < 6; i++) {
    unite(nodes[1], nodes[i], demoOperation);
  }
  
  for (int i = 7; i < 11; i++) {
    unite(nodes[6], nodes[i], demoOperation);
  }
  
  for (int i = 12; i < 20; i++) {
    unite(nodes[1], nodes[i], demoOperation);
  }
  
  printParents(nodes, 20);
  
  Edge *edges[10];
  Edge *solution[10];

  int solutionSize = 0;

  edges[0] = makeEdge(1, 2, 1);
  edges[1] = makeEdge(1, 5, 4);
  edges[2] = makeEdge(1, 3, 2);
  edges[3] = makeEdge(2, 3, 1);
  edges[4] = makeEdge(2, 4, 9);
  edges[5] = makeEdge(4, 5, 8);
  edges[6] = makeEdge(5, 3, 3);

  kruskal(5, edges, 7, solution, solutionSize, demoOperation);
  
//  generate();
  printf("DONE\n");

}
