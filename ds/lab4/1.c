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
	struct Node *next;
} Node;

void swap(int *x, int *y);
Node *createNode(int data);
void insertBeforeNode(Node **head, int data, int key);
void insertAfterNode(Node **head, int data, int key);
void deleteNode(Node **head, int data);
void traverseList(Node *head);
void reverseList(Node **head);
void bubbleSortList(Node **head);
void deleteAlternateNodes(Node **head);
void insertIntoSortedList(Node **head, int data);

int main()
{
	Node *head = NULL, *tail = NULL;
	int n, val, c, data, key;

	printf("Enter number of elements: ");
	scanf("%d", &n);

	printf("Enter %d elements: ", n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &val);
		Node *newNode = createNode(val);
		if (head == NULL)
		{
			head = tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
	}

	printf("Initial list: ");
	traverseList(head);

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
			insertBeforeNode(&head, data, key);
			break;
		case 2:
			printf("Enter data to insert and key to insert after: ");
			scanf("%d %d", &data, &key);
			insertAfterNode(&head, data, key);
			break;
		case 3:
			printf("Enter data to delete: ");
			scanf("%d", &data);
			deleteNode(&head, data);
			break;
		case 4:
			traverseList(head);
			break;
		case 5:
			reverseList(&head);
			break;
		case 6:
			bubbleSortList(&head);
			break;
		case 7:
			deleteAlternateNodes(&head);
			break;
		case 8:
			printf("Enter data to insert into sorted list: ");
			scanf("%d", &data);
			insertIntoSortedList(&head, data);
			break;
		case 9:
			// Free memory before exiting
			while (head != NULL)
			{
				Node *temp = head;
				head = head->next;
				free(temp);
			}
			return 0;
		default:
			printf("Invalid choice! Please try again.\n");
		}
	}
}

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

Node *createNode(int data)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	if (temp == NULL)
	{
		printf("Memory allocation failed!\n");
		return NULL;
	}
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void insertBeforeNode(Node **head, int data, int key)
{
	Node *temp = createNode(data);
	if (temp == NULL)
		return;

	if (*head == NULL || (*head)->data == key)
	{
		temp->next = *head;
		*head = temp;
		return;
	}

	Node *current = *head;
	while (current->next != NULL && current->next->data != key)
		current = current->next;

	if (current->next == NULL)
	{
		printf("Key %d not found in the list.\n", key);
		free(temp);
		return;
	}

	temp->next = current->next;
	current->next = temp;
}

void insertAfterNode(Node **head, int data, int key)
{
	Node *temp = createNode(data);
	if (temp == NULL)
		return;

	Node *current = *head;
	while (current != NULL && current->data != key)
		current = current->next;

	if (current == NULL)
	{
		printf("Key %d not found in the list.\n", key);
		free(temp);
		return;
	}

	temp->next = current->next;
	current->next = temp;
}

void deleteNode(Node **head, int data)
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
		temp = temp->next;
	}

	if (temp == NULL)
	{
		printf("Node with data %d not found.\n", data);
		return;
	}

	if (prev == NULL)
		*head = temp->next;
	else
		prev->next = temp->next;

	free(temp);
}

void traverseList(Node *head)
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
		current = current->next;
	}
	printf("\n");
}

void reverseList(Node **head)
{
	if (*head == NULL || (*head)->next == NULL)
		return;

	Node *prev = NULL, *curr = *head, *next = NULL;

	while (curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	*head = prev;
}

void bubbleSortList(Node **head)
{
	if (*head == NULL || (*head)->next == NULL)
		return;

	int swapped;
	Node *ptr1;
	Node *lptr = NULL;

	do
	{
		swapped = 0;
		ptr1 = *head;

		while (ptr1->next != lptr)
		{
			if (ptr1->data > ptr1->next->data)
			{
				swap(&ptr1->data, &ptr1->next->data);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	} while (swapped);
}

void deleteAlternateNodes(Node **head)
{
	if (*head == NULL || (*head)->next == NULL)
		return;

	Node *temp = *head;
	Node *next;

	while (temp != NULL && temp->next != NULL)
	{
		next = temp->next;
		temp->next = next->next;
		free(next);
		temp = temp->next;
	}
}

void insertIntoSortedList(Node **head, int data)
{
	Node *temp = createNode(data);
	if (temp == NULL)
		return;

	if (*head == NULL || (*head)->data >= data)
	{
		temp->next = *head;
		*head = temp;
		return;
	}

	Node *current = *head;
	while (current->next != NULL && current->next->data < data)
		current = current->next;

	temp->next = current->next;
	current->next = temp;
}
