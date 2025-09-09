/*
Doubly Linked List stores the  Price of Products purchased.
1. Calculate the total price of the bill
2. Display the list before and after appending the total at the end of the list
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	float data;
	struct Node *prev, *next;
} Node;

Node *createNode(float data);
void printList(Node *head);
void freeList(Node *head);
void insertAtEnd(Node **head, float data);
float calcTotal(Node **head);

int main()
{
	Node *head = NULL;
	int n;
	float val;

	printf("Enter total number of items: ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		printf("Enter price for item %d: ", i + 1);
		scanf("%f", &val);
		insertAtEnd(&head, val);
	}

	printf("Items list: ");
	printList(head);

	insertAtEnd(&head, calcTotal(&head));

	printf("Items list with total: ");
	printList(head);

	freeList(head);
}

Node *createNode(float data)
{
	Node *new = (Node *)malloc(sizeof(Node));

	new->data = data;
	new->prev = NULL;
	new->next = NULL;

	return new;
}

void printList(Node *head)
{
	Node *temp = head;

	while (temp != NULL)
	{
		printf("%.2f ", temp->data);
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

void insertAtEnd(Node **head, float data)
{
	Node *new = createNode(data), *temp = *head;

	if (*head == NULL)
	{
		*head = new;
		return;
	}

	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->next = new;
	new->prev = temp;
}

float calcTotal(Node **head)
{
	Node *temp = *head;
	float total = 0;

	if (*head == NULL)
		return 0;

	while (temp != NULL)
	{
		total += temp->data;
		temp = temp->next;
	}

	return total;
}