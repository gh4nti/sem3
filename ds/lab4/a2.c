// Merge two sorted linked lists (X and Y in non-decreasing order) into a new sorted list Z. After merge, X and Y should not exist separately. Do not use new nodes.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *link;
} Node;

Node *new(int data);
void print(Node *head);
Node *merge(Node *x, Node *y);

int main()
{
	// example list X: 1 -> 3 -> 5
	Node *x = new(1);
	x->link = new(3);
	x->link->link = new(5);

	// example list Y: 2 -> 4 -> 6
	Node *y = new(2);
	y->link = new(4);
	y->link->link = new(6);

	printf("X: ");
	print(x);
	printf("Y: ");
	print(y);

	Node *z = merge(x, y);
	printf("Z: ");
	print(z);

	free(x);
	free(y);
	free(z);
	return 0;
}

// create a new node
Node *new(int data)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->data = data;
	temp->link = NULL;
	return temp;
}

// print the list
void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->link;
	}
	printf("\n");
}

Node *merge(Node *x, Node *y)
{
	if (!x)
		return y;
	if (!y)
		return x;

	Node *head = NULL;
	Node *tail = NULL;

	if (x->data <= y->data)
	{
		head = x;
		x = x->link;
	}
	else
	{
		head = y;
		y = y->link;
	}

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

	if (x)
		tail->link = x;
	if (y)
		tail->link = y;

	return head;
}