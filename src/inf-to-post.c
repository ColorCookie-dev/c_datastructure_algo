#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100
typedef struct Node {
	char c;
	struct Node * next;
} Node;

void push(Node **top, char c) {
	Node * new = malloc(sizeof(Node));
	if (new == NULL) {
		puts("[-] Overflow");
	}

	new->c = c;
	new->next = *top;
	*top = new;
}

int is_empty(Node **top) {
	return *top == NULL;
}

char pop(Node **top) {
	Node * node = *top;
	char c;
	if (*top == NULL) {
		puts("[-] Underflow");
		exit(1);
	}
	*top = (*top)->next;
	c = node->c;
	free(node);
	return c;
}

void into_stack(char *s, int l, Node ** top) {
	int i;
	for (i = 0; i < l; i++) {
		push(top, s[i]);
	}
}

void print_stack(Node **top) {
	while (!is_empty(top)) {
		printf("%c", pop(top));
	}
}

int main() {
	Node * s1 = NULL;

	char s[MAXLEN];
	printf("input >> ");
	fgets(s, sizeof s, stdin);

	into_stack(s, sizeof s, &s1);
	print_stack(&s1);

	return 0;
}
