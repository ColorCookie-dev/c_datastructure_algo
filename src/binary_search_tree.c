#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *left, *right;
} Node;

void insert(Node **root, int data) {
  if (*root == NULL) {
    *root = malloc(sizeof(Node));
    (*root)->data = data;
    (*root)->left = NULL;
    (*root)->right = NULL;
    return;
  }
  if ((*root)->data >= data) {
    return insert(&((*root)->left), data);
  }
  return insert(&((*root)->right), data);
}

void merge(Node **root1, Node *root2) {
  if (root2 == NULL) {
    return;
  }
  insert(root1, root2->data);
  merge(root1, root2->left);
  merge(root1, root2->right);
  free(root2);
}

void delete(Node **root, int data) {
  Node *node = *root;
  if (node == NULL)
    return;
  if (node->data == data) {
    *root = NULL;
    merge(root, node->left);
    merge(root, node->right);
    free(node);
    return;
  } else if (node->data > data) {
    delete (&((*root)->left), data);
  } else {
    delete (&((*root)->right), data);
  }
}

void show_bst(Node *root) {
  if (root == NULL) {
    return;
  }

  show_bst(root->left);
  printf("%d ", root->data);
  show_bst(root->right);
}

int main() {
  Node *root = NULL;
  Node *root2 = NULL;

  insert(&root, 1);
  insert(&root, 1);
  insert(&root, 3);
  insert(&root, 30);
  insert(&root, 4);
  insert(&root, 2);
  show_bst(root);
  puts("");

  insert(&root2, 1);
  insert(&root2, 1);
  insert(&root2, 3);
  insert(&root2, 30);
  insert(&root2, 4);
  insert(&root2, 2);
  show_bst(root2);
  puts("");

  merge(&root, root2);
  show_bst(root);
  puts("");

  delete (&root, 2);
  show_bst(root);
  puts("");

  return 0;
}
