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
	struct Node *link;
} Node;

Node *create(int data);
void trav(Node *head);

int main()
{
	Node *head = create(10);
	head->link = create(20);
	head->link->link = create(30);
	head->link->link->link = NULL;

	printf("Traversing the list recursively:\n");
	trav(head);
	free(head->link->link);
	free(head->link);
	free(head);
	return 0;
}

// create a linked list recursively
Node *create(int data)
{
	if (data <= 0)
	{
		return NULL;
	}

	Node *temp = (Node *)malloc(sizeof(Node));
	if (!temp)
	{
		printf("Memory allocation failed.\n");
		exit(1);
	}

	printf("Enter data for node: ");
	scanf("%d", &temp->data);

	temp->link = create(data - 1);
	return temp;
}

// traverse the linked list recursively
void trav(Node *head)
{
	if (head == NULL)
	{
		printf("NULL\n");
		return;
	}
	printf("%d ", head->data);
	trav(head->link);
}