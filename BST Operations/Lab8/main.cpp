//
//  main.cpp
//  Lab8
//
//  Created by Ruxandra Ciortea on 20.11.2021.
//

#include "Node.hpp"
#include "Profiler.h"

int main(int argc, const char * argv[]) {
    
  Node *root = buildTree(10);
  OSDelete(root, 10);
  prettyPrint(root, 0);

}
