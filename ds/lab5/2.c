// Write a program to concatenate two doubly linked lists X1 and X2. After concatenation, X1 should point to the first node of the resulting list.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *prev, *next;
} Node;

Node *createNode(int data);
void insertAtRear(Node **head, int data);
void concatenateLists(Node **head1, Node **head2);
void printList(Node *head);
void freeList(Node *head);

int main()
{
	Node *x1 = NULL, *x2 = NULL;
	int n1, n2, val;

	printf("Enter number of elements in X1: ");
	scanf("%d", &n1);

	for (int i = 0; i < n1; i++)
	{
		printf("Element %d: ", i + 1);
		scanf("%d", &val);
		insertAtRear(&x1, val);
	}

	printf("Enter number of elements in X2: ");
	scanf("%d", &n2);

	for (int i = 0; i < n2; i++)
	{
		printf("Element %d: ", i + 1);
		scanf("%d", &val);
		insertAtRear(&x2, val);
	}

	printf("\nX1:\n");
	printList(x1);

	printf("\nX2:\n");
	printList(x2);

	concatenateLists(&x1, &x2);

	printf("\nConcatenated list (X1):\n");
	printList(x1);

	freeList(x1);

	return 0;
}

Node *createNode(int data)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->data = data;
	temp->prev = temp->next = NULL;
	return temp;
}

void insertAtRear(Node **head, int data)
{
	Node *newNode = createNode(data);

	if (*head == NULL)
	{
		*head = newNode;
		return;
	}

	Node *temp = *head;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = newNode;
	newNode->prev = temp;
}

void concatenateLists(Node **head1, Node **head2)
{
	if (*head1 == NULL)
	{
		*head1 = *head2;
		return;
	}
	if (*head2 == NULL)
	{
		return;
	}

	Node *temp = *head1;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *head2;
	(*head2)->prev = temp;
}

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

void freeList(Node *head)
{
	Node *temp;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}