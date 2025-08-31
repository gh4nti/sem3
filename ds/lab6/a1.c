/*
Write a menu-driven C program to perform the following operations on a Circular Doubly Linked List:
i) Insert an element into the list
ii) Delete an element from the list
iii) Display the elements of the list
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *prev, next;
} Node;

Node *createNode(int data);
Node *insertNode(Node *head, int data);
Node *deleteNode(Node *head, int data);
void printList(Node *head);
void freeList(Node **head);

int main()
{
	Node *head = NULL;
	int c, data;

	while (1)
	{
		printf("\nCircular Doubly Linked List Operations:\n");
		printf("1. Insert an element\n");
		printf("2. Delete an element\n");
		printf("3. Display the list\n");
		printf("4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &c);

		switch (c)
		{
		case 1:
			printf("Enter the element to insert: ");
			scanf("%d", &data);
			head = insertNode(head, data);
			printf("Element %d inserted successfully.\n", data);
			break;

		case 2:
			printf("Enter the element to delete: ");
			scanf("%d", &data);
			head = deleteNode(head, data);
			break;

		case 3:
			displayList(head);
			break;

		case 4:
			freeList(&head);
			printf("List freed and program exiting.\n");
			return 0;

		default:
			printf("Invalid choice! Please try again.\n");
		}
	}
}

Node *createNode(int data)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	if (temp == NULL)
	{
		printf("Memory allocation failed!\n");
		exit(1);
	}
	temp->data = data;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

Node *insertNode(Node *head, int data)
{
	Node *temp = createNode(data);
	if (head == NULL)
	{
		head = temp;
		head->next = head;
		head->prev = head;
	}
	else
	{
		Node *last = head->prev;

		temp->next = head;
		temp->prev = last;
		last->next = temp;
		head->prev = temp;
	}
	return head;
}

Node *deleteNode(Node *head, int data)
{
	if (head == NULL)
	{
		printf("List is empty!\n");
		return head;
	}

	Node *current = head;
	Node *toDelete = NULL;

	do
	{
		if (current->data == data)
		{
			toDelete = current;
			break;
		}
		current = current->next;
	} while (current != head);

	if (toDelete == NULL)
	{
		printf("Element %d not found in the list!\n", data);
		return head;
	}

	if (toDelete->next == toDelete)
	{
		free(toDelete);
		return NULL;
	}

	toDelete->prev->next = toDelete->next;
	toDelete->next->prev = toDelete->prev;

	if (toDelete == head)
	{
		head = toDelete->next;
	}

	free(toDelete);
	return head;
}

void freeList(Node **head)
{
	if (*head == NULL)
		return;

	Node *current = *head;
	Node *next;

	current->prev->next = NULL;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	*head = NULL;
}