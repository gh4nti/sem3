/*
Make a pointer/array using dynamic memory allocation for number of patients for n days in a hospital.
1. Find the day with minimum patients using recursion
2. Display number of patients on all days
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int day, n;
	struct Node *next;
} Node;

Node *createNode(int day, int n);
void printList(Node *head);
void freeList(Node *head);
void insertAtEnd(Node **head, int day, int n);
Node *findMinNode(Node *head);
int findMinDay(Node **head);

int main()
{
	Node *head = NULL;
	int n, val;

	printf("Enter total number of days: ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		printf("Enter number of patients for day %d: ", i + 1);
		scanf("%d", &val);
		insertAtEnd(&head, i + 1, val);
	}

	printf("\n");
	printList(head);

	printf("\nDay %d had minimum number of patients.\n", findMinDay(&head));

	freeList(head);
}

Node *createNode(int day, int n)
{
	Node *new = (Node *)malloc(sizeof(Node));

	new->day = day;
	new->n = n;
	new->next = NULL;

	return new;
}

void printList(Node *head)
{
	Node *temp = head;

	while (temp != NULL)
	{
		printf("Number of patients on day %d: %d\n", temp->day, temp->n);
		temp = temp->next;
	}
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

void insertAtEnd(Node **head, int day, int n)
{
	Node *new = createNode(day, n), *temp = *head;

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
}

Node *findMinNode(Node *head)
{
	if (head == NULL)
		return NULL;
	if (head->next == NULL)
		return head;

	Node *minRest = findMinNode(head->next);

	if (minRest == NULL)
		return head;

	return (head->n <= minRest->n) ? head : minRest;
}

int findMinDay(Node **head)
{
	Node *minNode = findMinNode(*head);
	return (minNode == NULL) ? -1 : minNode->day;
}