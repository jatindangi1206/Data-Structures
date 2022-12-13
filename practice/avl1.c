#include <stdio.h>
#include <stdlib.h>

/* Define a node in the AVL tree */
typedef struct node {
  int data;  /* The value stored in the node */
  int height;  /* The height of the node in the tree */
  struct node* left;  /* Pointer to the left child */
  struct node* right;  /* Pointer to the right child */
} Node;

/* Helper function to create a new node with the given data */
Node* create_node(int data) {
  Node* new_node = (Node*)malloc(sizeof(Node));
  new_node->data = data;
  new_node->height = 1;  /* Height of a new node is always 1 */
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

/* Helper function to calculate the height of a given node */
int height(Node* node) {
  if (node == NULL) {
    return 0;
  }
  return node->height;
}

/* Helper function to get the maximum of two integers */
int max(int a, int b) {
  return (a > b) ? a : b;
}

/* Helper function to perform a left-left rotation on the given tree */
Node* left_left_rotate(Node* root) {
  /* Set the left child of the root as the new root of the tree */
  Node* new_root = root->left;

  /* Set the old root of the tree as the right child of the new root */
  root->left = new_root->right;
  new_root->right = root;

  /* Update the heights of the nodes */
  root->height = max(height(root->left), height(root->right)) + 1;
  new_root->height = max(height(new_root->left), height(new_root->right)) + 1;

  return new_root;  /* Return the new root of the tree */
}

/* Helper function to perform a left-right rotation on the given tree */
Node* left_right_rotate(Node* root) {
  /* Set the right child of the left child of the root as the new root of the tree */
  root->left = left_left_rotate(root->left);

  /* Perform a left-left rotation on the root */
  return left_left_rotate(root);
}

/* Helper function to perform a right-left rotation on the given tree */
Node* right_left_rotate(Node* root) {
  /* Set the left child of the right child of the root as the new root of the tree */
  root->right = left_left_rotate(root->right);

  /* Perform a right-right rotation on the root */
  return right_right_rotate(root);
}

/* Helper function to perform a right-right rotation on the given tree */
Node* right_right_rotate(Node* root) {
  /* Set the right child of the root as the new root of the tree */
