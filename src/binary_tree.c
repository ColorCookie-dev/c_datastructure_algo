#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *left, *right;
} Node;

Node *create_node(int data) {
	Node *node = malloc(sizeof(Node));
	node->data = data;
	node->right = NULL;
	node->left = NULL;
	return node;
}

Node *insert(Node *root, int data) {
	if (root == NULL) return create_node(data);
	if (data < root->data) root->left = insert(root->left, data);
	else root->right = insert(root->right, data);
	return root;
}

Node *merge_tree(Node *t1, Node *t2) {
	if (t2 == NULL) return t1;
	t1 = merge_tree(t1, t2->left);
	t1 = merge_tree(t1, t2->right);
	t1 = insert(t1, t2->data);
	free(t2);
	return t1;
}

Node *free_node(Node *node) {
	Node *left = node->left;
	left = merge_tree(left, node->right);
	free(node);
	return left;
}

Node *delete(Node *root, int data) {
	if (data < root->data) root->left = delete(root->left, data);
	else if (root->data < data) root->right = delete(root->right, data);
	else root = free_node(root);
	return root;
}

void print_tree(Node *root) {
	if (root == NULL) return;
	print_tree(root->left);
	print_tree(root->right);
	printf("%d ", root->data);
}

void free_tree(Node *root) {
	if (root == NULL) return;
	free_tree(root->left);
	free_tree(root->right);
	free(root);
}

int main() {
	int i;
	Node *root = NULL;

	for (i = 1; i <= 5; i++) {
		root = insert(root, i);
		print_tree(root);
		puts("");
	}

	for (i = 1; i <= 5; i++) {
		root = delete(root, i);
		print_tree(root);
		puts("");
	}

	free_tree(root);
}
