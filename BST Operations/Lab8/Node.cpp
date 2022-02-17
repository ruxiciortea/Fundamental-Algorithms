//
//  BST.cpp
//  Lab8
//
//  Created by Ruxandra Ciortea on 20.11.2021.
//

#include "Node.hpp"

Profiler p("BinarySearchTree");

// MARK: - Divide
Node* divide(int left, int right, Node *parent) {
  if (left > right) {
    return NULL;
  }
  
  Node *middle = (Node*)calloc(1, sizeof(Node));
  middle -> value = (left + right) / 2;
  middle -> size = right - left + 1;
  
  middle -> left = divide(left, middle -> value - 1, middle);
  if (middle -> left != NULL) {
    middle -> left -> parent = middle;
  }
  
  middle -> right = divide(middle -> value + 1, right, middle);
  if (middle -> right != NULL) {
    middle -> right -> parent = middle;
  }
  
  return middle;
}

// MARK: - Build
Node* buildTree(int n) {
  return divide(1, n, NULL);
}

// MARK: - Select
// Returns the i-th node from the tree
Node* OSSelect(Node *root, int i) {
  if (i > root -> size) {
    return  NULL;
  }
  
  int rank = (root -> size);
  
  if (root -> right) {
    rank -= (root -> right -> size);
  }
  
  if (rank > i) {
    return OSSelect(root -> left, i);
  } else if (rank < i) {
    return OSSelect(root -> right, i - rank);
  }

  return root;
}

// MARK: - Delete
// Returns the root of a tree with the given node deleted
void BSTDelete(Node *node) {
  if (node == NULL) {
    return;
  }
  
  Node *parent = node -> parent;

  // The node is a leaf
  if (node -> left == NULL && node -> right == NULL) {
    if (parent -> value > node -> value) {
      parent -> left = NULL;
    } else if (parent -> value < node -> value) {
      parent -> right = NULL;
    }
    
    return;
  }
  
  // Node has one child
  if (node -> left != NULL && node -> right == NULL) {
    if (parent -> value > node -> value) {
      parent -> left = node -> left;
    } else {
      parent -> right = node -> left;
    }

    return;
  } else if (node -> left == NULL && node -> right != NULL) {
    if (parent -> value > node -> value) {
      parent -> left = node -> right;
    } else {
      parent -> right = node -> right;
    }

    return;
  }
  
  // Node has two children
  if (node -> left != NULL && node -> right != NULL) {
    Node *target = node -> right;
    node -> value = target -> value;
    
    BSTDelete(target);
  }
}

void OSDelete(Node *root, int i) {
  Node *node = OSSelect(root, i);
  BSTDelete(node);
  
  if (node == NULL || node -> parent == NULL) {
    return;
  }
  
  Node *parent = node -> parent;
  
  while (parent) {
    (parent -> size)--;
    parent = parent -> parent;
  }
}

// MARK: - Print
void prettyPrint(Node* root, int space) {
  if (root == NULL) {
    return;
  }

  space += 10;
  prettyPrint(root -> right, space);
  cout << "\n";
  
  for (int i = 10; i < space; i++) {
    cout << " ";
  }

  cout << root -> value << "\n";
  
  prettyPrint(root -> left, space);
}
