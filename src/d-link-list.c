#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next, *prev;
} Node;

void insert_begin(Node **head, int data) {
	Node *new = malloc(sizeof(Node));
	new->data = data;
	new->next = *head;
	new->prev = NULL;

	*head = new;
	if (new->next != NULL) new->next->prev = new;
}

void insert_end(Node **head, int data) {
	Node *new = malloc(sizeof(Node)), *cur = *head;
	new->data = data;
	new->next = NULL;
	new->prev = NULL;

	if (*head == NULL) {
		*head = new;
		return;
	}

	while (cur->next != NULL) cur = cur->next;
	cur->next = new;
	new->prev = cur;
}

void delete_key(Node **head, int key) {
	Node *cur = *head;
	if (cur != NULL && cur->data == key) {
		*head = cur->next;
		cur->next->prev = NULL;
		free(cur);
		return;
	}

	while (cur != NULL && cur->data != key) cur = cur->next;
	if (cur == NULL) return;
	if (cur->next != NULL) cur->next->prev = cur->prev;
	cur->prev->next = cur->next;
	free(cur);
}

void print_list(Node *head) {
	printf("List: [ ");
	while (head != NULL) {
		printf("%d, ", head->data);
		head = head->next;
	}
	puts("]");
}

void free_list(Node *head) {
	Node *temp;
	while (head != NULL) {
		temp = head;
		head = head->next;
		free(temp);
	}
}

int main() {
	Node *head = NULL;
	print_list(head);

	insert_begin(&head, 1);
	print_list(head);

	insert_end(&head, 10);
	print_list(head);

	insert_end(&head, 3);
	print_list(head);

	delete_key(&head, 3);
	print_list(head);

	delete_key(&head, 1);
	print_list(head);

	free_list(head);
}
