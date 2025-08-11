// Merge two sorted linked lists (X and Y in non-decreasing order) into a new sorted list Z. After merge, X and Y should not exist separately. Do not use new nodes.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
} Node;

Node *createNode(int data);
void printList(Node *head);
Node *mergeList(Node *x, Node *y);
void freeList(Node *head);

int main()
{
	int n1, n2;
	printf("Enter number of elements in X: ");
	scanf("%d", &n1);
	Node *x = createList(n1);

	printf("Enter number of elements in Y: ");
	scanf("%d", &n2);
	Node *y = createList(n2);

	printf("X: ");
	printList(x);
	printf("Y: ");
	printList(y);

	Node *z = mergeList(x, y);
	printf("Z (merged): ");
	printList(z);

	freeList(z);
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
	temp->next = NULL;
	return temp;
}

// print the list
void printList(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

// free the list
void freeList(Node *head)
{
	while (head)
	{
		Node *temp = head;
		head = head->next;
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
		x = x->next;
	}
	else
	{
		head = tail = y;
		y = y->next;
	}

	// Merge process
	while (x && y)
	{
		if (x->data <= y->data)
		{
			tail->next = x;
			x = x->next;
		}
		else
		{
			tail->next = y;
			y = y->next;
		}
		tail = tail->next;
	}

	// Append remaining nodes
	if (x)
		tail->next = x;
	if (y)
		tail->next = y;

	return head;
}
