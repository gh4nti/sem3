/*
Write a menu-driven C program using structures to implement the following operations on a singly linked list:
- Insert an element before another specified element in the list
(Example: Insert 10 before 25)
- Insert an element after another specified element in the list
(Example: Insert 40 after 25)
- Delete a specified element from the list
(Example: Delete node containing 15)
- Traverse the list and display all elements
- Reverse the linked list
(Modify the links such that the list is reversed)
- Sort the list in ascending order
(Using Bubble Sort or any appropriate algorithm on linked list)
- Delete every alternate node in the list
(Starting from the second node)
- Insert an element into a sorted linked list while maintaining the sorted order
(Example: Insert 28 into a list that is already sorted)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *link;
} Node;

void swap(int *x, int *y);
Node *new(int data);
void insB(Node **head, int data, int key);
void insA(Node **head, int data, int key);
void del(Node **head, int data);
void trav(Node *head);
void rev(Node **head);
void sort(Node **head);
void delAlt(Node **head);
void insSorted(Node **head, int data);

int main()
{
	// sample list
	Node *head = NULL;
	head = new(45);
	if (head == NULL)
	{
		printf("Memory allocation failed!\n");
		return -1;
	}
	head->link = new(50);
	if (head->link == NULL)
	{
		printf("Memory allocation failed!\n");
		free(head);
		return -1;
	}
	head->link->link = new(12);
	if (head->link->link == NULL)
	{
		printf("Memory allocation failed!\n");
		free(head->link);
		free(head);
		return -1;
	}
	head->link->link->link = NULL;

	int c, data, key;

	while (1)
	{
		printf("\nMenu:\n");
		printf("1. Insert before an element\n");
		printf("2. Insert after an element\n");
		printf("3. Delete an element\n");
		printf("4. Traverse the list\n");
		printf("5. Reverse the list\n");
		printf("6. Sort the list\n");
		printf("7. Delete every alternate node\n");
		printf("8. Insert into sorted list\n");
		printf("9. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &c);

		switch (c)
		{
		case 1:
			printf("Enter data to insert and key to insert before: ");
			scanf("%d %d", &data, &key);
			insB(&head, data, key);
			break;
		case 2:
			printf("Enter data to insert and key to insert after: ");
			scanf("%d %d", &data, &key);
			insA(&head, data, key);
			break;
		case 3:
			printf("Enter data to delete: ");
			scanf("%d", &data);
			del(&head, data);
			break;
		case 4:
			trav(head);
			break;
		case 5:
			rev(&head);
			break;
		case 6:
			sort(&head);
			break;
		case 7:
			delAlt(&head);
			break;
		case 8:
			printf("Enter data to insert into sorted list: ");
			scanf("%d", &data);
			insSorted(&head, data);
			break;
		case 9:
			exit(0);
		default:
			printf("Invalid choice! Please try again.\n");
		}
	}
	free(head);
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

// insert a node before a key
void insB(Node **head, int data, int key)
{
	Node *temp = new(data);
	if (temp == NULL)
	{
		printf("Memory allocation failed!\n");
		return;
	}

	if (*head == NULL || (*head)->data == key)
	{
		temp->link = *head;
		*head = temp;
		return;
	}

	Node *current = *head;
	while (current->link != NULL && current->link->data != key)
	{
		current = current->link;
	}

	if (current->link == NULL)
	{
		printf("Key %d not found in the list.\n", key);
		free(temp);
		return;
	}

	temp->link = current->link;
	current->link = temp;
}

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

// insert a node after a key
void insA(Node **head, int data, int key)
{
	Node *temp = new(data);
	if (temp == NULL)
	{
		printf("Memory allocation failed!\n");
		return;
	}

	Node *current = *head;
	while (current != NULL && current->data != key)
	{
		current = current->link;
	}

	if (current == NULL)
	{
		printf("Key %d not found in the list.\n", key);
		free(temp);
		return;
	}

	temp->link = current->link;
	current->link = temp;
}

// delete a node
void del(Node **head, int data)
{
	if (*head == NULL)
	{
		printf("List is empty.\n");
		return;
	}

	Node *temp = *head, *prev = NULL;

	while (temp != NULL && temp->data != data)
	{
		prev = temp;
		temp = temp->link;
	}

	if (temp == NULL)
	{
		printf("Node with data %d not found.\n", data);
		return;
	}

	if (prev == NULL)
	{
		*head = temp->link;
	}
	else
	{
		prev->link = temp->link;
	}

	free(temp);
}

// traverse the list and display elements
void trav(Node *head)
{
	if (head == NULL)
	{
		printf("List is empty.\n");
		return;
	}

	Node *current = head;
	printf("List elements: ");
	while (current != NULL)
	{
		printf("%d ", current->data);
		current = current->link;
	}
	printf("\n");
}

// reverse the list
void rev(Node **head)
{
	if (*head == NULL || (*head)->link == NULL)
	{
		return;
	}

	Node *prev = NULL, *temp = *head, *next = NULL;

	while (temp != NULL)
	{
		next = temp->link;
		temp->link = prev;
		prev = temp;
		temp = next;
	}

	*head = prev;
}

// sort the list using bubble sort
void sort(Node **head)
{
	if (*head == NULL || (*head)->link == NULL)
	{
		return;
	}

	int swapped;
	Node *ptr1;
	Node *lptr = NULL;

	for (swapped = 1; swapped;)
	{
		swapped = 0;
		ptr1 = *head;

		while (ptr1->link != lptr)
		{
			if (ptr1->data > ptr1->link->data)
			{
				swap(&ptr1->data, &ptr1->link->data);
				swapped = 1;
			}
			ptr1 = ptr1->link;
		}
		lptr = ptr1;
	}
}

// delete every alternate node
void delAlt(Node **head)
{
	if (*head == NULL || (*head)->link == NULL)
	{
		return;
	}

	Node *temp = *head;
	Node *next;

	while (temp != NULL && temp->link != NULL)
	{
		next = temp->link;
		temp->link = next->link;
		free(next);
		temp = temp->link;
	}
}

// insert into a sorted list
void insSorted(Node **head, int data)
{
	Node *temp = new(data);
	if (temp == NULL)
	{
		printf("Memory allocation failed!\n");
		return;
	}

	if (*head == NULL || (*head)->data >= data)
	{
		temp->link = *head;
		*head = temp;
		return;
	}

	Node *curr = *head;
	while (curr->link != NULL && curr->link->data < data)
	{
		curr = curr->link;
	}

	temp->link = curr->link;
	curr->link = temp;
}