// Merge two sorted linked lists (X and Y in non-decreasing order) into a new sorted list Z. After merge, X and Y should not exist separately. Do not use new nodes.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *link;
} Node;

Node *createNode(int data);
void printList(Node *head);
Node *mergeList(Node *x, Node *y);
void freeList(Node *head);

int main()
{
	// example list X: 1 -> 3 -> 5
	Node *x = createNode(1);
	x->link = createNode(3);
	x->link->link = createNode(5);

	// example list Y: 2 -> 4 -> 6
	Node *y = createNode(2);
	y->link = createNode(4);
	y->link->link = createNode(6);

	printf("X: ");
	printList(x);
	printf("Y: ");
	printList(y);

	Node *z = mergeList(x, y);
	printf("Z: ");
	printList(z);

	freeList(z); // free merged list
	return 0;
}

// create a new node
Node *createNode(int data)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	if (!temp)
	{
		printf("Memory allocation failed!\n");
		exit(1);
	}
	temp->data = data;
	temp->link = NULL;
	return temp;
}

// print the list
void printList(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->link;
	}
	printf("\n");
}

// free the list
void freeList(Node *head)
{
	while (head)
	{
		Node *temp = head;
		head = head->link;
		free(temp);
	}
}

// merge two sorted lists without creating new nodes
Node *mergeList(Node *x, Node *y)
{
	if (!x)
		return y;
	if (!y)
		return x;

	Node *head = NULL;
	Node *tail = NULL;

	// Initialize head and tail
	if (x->data <= y->data)
	{
		head = tail = x;
		x = x->link;
	}
	else
	{
		head = tail = y;
		y = y->link;
	}

	// Merge process
	while (x && y)
	{
		if (x->data <= y->data)
		{
			tail->link = x;
			x = x->link;
		}
		else
		{
			tail->link = y;
			y = y->link;
		}
		tail = tail->link;
	}

	// Append remaining nodes
	if (x)
		tail->link = x;
	if (y)
		tail->link = y;

	return head;
}
