/*
Recursive functions:
i) Create a linked list recursively
ii) Traverse a linked list recursively
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
} Node;

Node *createRecursive(int n);
void traverseRecursive(Node *head);
void freeListRecursive(Node *head);

int main()
{
	int n;
	printf("Enter number of nodes: ");
	scanf("%d", &n);

	Node *head = createRecursive(n);

	printf("Traversing the list recursively:\n");
	traverseRecursive(head);
	printf("NULL\n");

	freeListRecursive(head); // Free memory recursively
	return 0;
}

// Create linked list recursively
Node *createRecursive(int n)
{
	if (n <= 0)
		return NULL;

	Node *temp = (Node *)malloc(sizeof(Node));
	if (!temp)
	{
		printf("Memory allocation failed.\n");
		exit(1);
	}

	printf("Enter data for node: ");
	scanf("%d", &temp->data);

	temp->next = createRecursive(n - 1); // recursive call for the rest
	return temp;
}

// Traverse linked list recursively
void traverseRecursive(Node *head)
{
	if (head == NULL)
		return;

	printf("%d -> ", head->data);
	traverseRecursive(head->next);
}

// Free linked list recursively
void freeListRecursive(Node *head)
{
	if (head == NULL)
		return;

	freeListRecursive(head->next);
	free(head);
}
