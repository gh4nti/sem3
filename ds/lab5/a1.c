// Union and Intersection: Write a program to implement the union and intersection of two doubly linked lists.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *prev;
	struct Node *next;
} Node;

Node *createNode(int data);
void insertAtRear(Node **head, Node **tail, int data);
void printList(Node *head);
Node *unionLists(Node *head1, Node *head2);
Node *intersectionLists(Node *head1, Node *head2);

int main()
{
	Node *head1 = NULL, *tail1 = NULL;
	Node *head2 = NULL, *tail2 = NULL;

	int n1, n2, data;

	printf("Enter number of elements in List 1: ");
	scanf("%d", &n1);
	printf("Enter elements of List 1: ");
	for (int i = 0; i < n1; i++)
	{
		scanf("%d", &data);
		insertAtRear(&head1, &tail1, data);
	}

	printf("Enter number of elements in List 2: ");
	scanf("%d", &n2);
	printf("Enter elements of List 2: ");
	for (int i = 0; i < n2; i++)
	{
		scanf("%d", &data);
		insertAtRear(&head2, &tail2, data);
	}

	printf("\nList 1: ");
	printList(head1);
	printf("List 2: ");
	printList(head2);

	printf("\nUnion: ");
	printList(unionLists(head1, head2));

	printf("Intersection: ");
	printList(intersectionLists(head1, head2));

	// Free all memory
	freeList(&head1);
	freeList(&head2);

	return 0;
}

// create a new node
Node *createNode(int value)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->data = value;
	temp->prev = NULL;
	temp->next = NULL;
	return temp;
}

// insert at rear
void insertAtRear(Node **head, Node **tail, int data)
{
	Node *temp = createNode(data);
	if (*head == NULL)
	{
		*head = *tail = temp;
	}
	else
	{
		(*tail)->next = temp;
		temp->prev = *tail;
		*tail = temp;
	}
}

// print list
void printList(Node *head)
{
	if (!head)
	{
		printf("List is empty.\n");
		return;
	}
	Node *temp = head;
	while (temp)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

// union of two lists
Node *unionLists(Node *head1, Node *head2)
{
	Node *unionHead = NULL, *tailU = NULL;
	Node *temp = head1;

	// Add all elements of first list
	while (temp)
	{
		if (!search(unionHead, temp->data))
			insertAtRear(&unionHead, &tailU, temp->data);
		temp = temp->next;
	}

	// Add elements of second list if not already present
	temp = head2;
	while (temp)
	{
		if (!search(unionHead, temp->data))
			insertAtRear(&unionHead, &tailU, temp->data);
		temp = temp->next;
	}
	return unionHead;
}

// intersection of two lists
Node *intersectionLists(Node *head1, Node *head2)
{
	Node *intersectionHead = NULL, *tailI = NULL;
	Node *temp = head1;

	// Add elements present in both lists
	while (temp)
	{
		if (search(head2, temp->data) && !search(intersectionHead, temp->data))
			insertAtRear(&intersectionHead, &tailI, temp->data);
		temp = temp->next;
	}
	return intersectionHead;
}

// free list
void freeList(Node **head)
{
	Node *temp = *head;
	while (temp)
	{
		Node *next = temp->next;
		free(temp);
		temp = next;
	}
	*head = NULL;
}
