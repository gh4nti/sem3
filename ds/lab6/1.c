/*
Write a C program to implement a Circular Singly Linked List using First and Last pointers.
Implement the following operations:
i. Insertion at the end of the list using First and Last pointers.
ii. Deletion from the beginning or end using First and Last pointers.
iii. Display the list after each operation.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
} Node;

Node *createNode(int data);
void insertAtEnd(Node **first, Node **last, int data);
void deleteAtBeginning(Node **first, Node **last);
void deleteAtEnd(Node **first, Node **last);
void printList(Node *first, Node *last);
void freeList(Node **first, Node **last);

int main()
{
	Node *first = NULL;
	Node *last = NULL;
	int choice, data;

	while (1)
	{
		printf("\nCircular Singly Linked List Operations:\n");
		printf("1. Insert at end\n");
		printf("2. Delete from beginning\n");
		printf("3. Delete from end\n");
		printf("4. Display list\n");
		printf("5. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("Enter the element to insert: ");
			scanf("%d", &data);
			insertAtEnd(&first, &last, data);
			printList(first, last);
			break;

		case 2:
			deleteAtBeginning(&first, &last);
			printList(first, last);
			break;

		case 3:
			deleteAtEnd(&first, &last);
			printList(first, last);
			break;

		case 4:
			printList(first, last);
			break;

		case 5:
			freeList(&first, &last);
			printf("List freed and program exiting.\n");
			return 0;

		default:
			printf("Invalid choice! Please try again.\n");
		}
	}
	return 0;
}

Node *createNode(int data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		printf("Memory allocation failed!\n");
		exit(1);
	}
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void insertAtEnd(Node **first, Node **last, int data)
{
	Node *newNode = createNode(data);

	if (*first == NULL)
	{
		*first = newNode;
		*last = newNode;
		newNode->next = *first;
	}
	else
	{
		newNode->next = *first;
		(*last)->next = newNode;
		*last = newNode;
	}
	printf("Inserted %d at the end.\n", data);
}

void deleteAtBeginning(Node **first, Node **last)
{
	if (*first == NULL)
	{
		printf("List is empty! Cannot delete.\n");
		return;
	}

	Node *temp = *first;

	if (*first == *last)
	{
		*first = NULL;
		*last = NULL;
	}
	else
	{
		*first = (*first)->next;
		(*last)->next = *first;
	}

	printf("Deleted %d from the beginning.\n", temp->data);
	free(temp);
}

void deleteAtEnd(Node **first, Node **last)
{
	if (*first == NULL)
	{
		printf("List is empty! Cannot delete.\n");
		return;
	}

	if (*first == *last)
	{
		printf("Deleted %d from the end.\n", (*first)->data);
		free(*first);
		*first = NULL;
		*last = NULL;
		return;
	}

	Node *current = *first;
	while (current->next != *last)
	{
		current = current->next;
	}

	printf("Deleted %d from the end.\n", (*last)->data);
	free(*last);
	*last = current;
	(*last)->next = *first;
}

void printList(Node *first, Node *last)
{
	if (first == NULL)
	{
		printf("List is empty!\n");
		return;
	}

	Node *current = first;
	printf("List elements: ");
	do
	{
		printf("%d ", current->data);
		current = current->next;
	} while (current != first);
	printf("\n");
}

void freeList(Node **first, Node **last)
{
	if (*first == NULL)
		return;

	Node *current = *first;
	Node *next;
	(*last)->next = NULL;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	*first = NULL;
	*last = NULL;
}
