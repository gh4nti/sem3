/*
Write a menu-driven C program using structures to implement the following operations on a doubly linked list.
- Insert an element at the rear end of the list
(Append a new node to the end of the list)
- Delete an element from the rear end of the list
(Remove the last node in the list)
- Insert an element at a given position in the list
(e.g., Insert at position 3. Positioning starts from 1.)
- Delete an element from a given position in the list
- Insert an element after a node containing a specific value
(e.g., Insert 40 after 25)
- Insert an element before a node containing a specific value
(e.g., Insert 10 before 25)
- Traverse the list in forward direction
(From head to tail)
- Traverse the list in reverse direction
(From tail to head – i.e., reverse traversal)
*/

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
void deleteAtRear(Node **head, Node **tail);
void insertAtPos(Node **head, Node **tail, int pos, int data);
void deleteAtPos(Node **head, Node **tail, int pos);
void insertBeforeNode(Node **head, Node **tail, int key, int data);
void insertAfterNode(Node **head, Node **tail, int key, int data);
void traverseForward(Node *head);
void traverseReverse(Node *tail);
void freeList(Node **head, Node **tail);

int main()
{
	Node *head = NULL, *tail = NULL;
	int n, val, c, data, pos, key;

	printf("Enter number of initial elements: ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		printf("Enter element %d: ", i + 1);
		scanf("%d", &val);
		insertAtRear(&head, &tail, val);
	}

	printf("\nInitial list:\n");
	traverseForward(head);

	while (1)
	{
		printf("\n--- Doubly Linked List Menu ---\n");
		printf("1. Insert at Rear\n");
		printf("2. Delete at Rear\n");
		printf("3. Insert at Position\n");
		printf("4. Delete at Position\n");
		printf("5. Insert After Value\n");
		printf("6. Insert Before Value\n");
		printf("7. Traverse Forward\n");
		printf("8. Traverse Reverse\n");
		printf("9. Exit\n");
		printf("Enter your choice: ");
		if (scanf("%d", &c) != 1)
		{
			printf("Invalid input.\n");
			exit(1);
		}

		switch (c)
		{
		case 1:
			printf("Enter value: ");
			scanf("%d", &data);
			insertAtRear(&head, &tail, data);
			break;
		case 2:
			deleteAtRear(&head, &tail);
			break;
		case 3:
			printf("Enter position and value: ");
			scanf("%d %d", &pos, &data);
			insertAtPos(&head, &tail, pos, data);
			break;
		case 4:
			printf("Enter position: ");
			scanf("%d", &pos);
			deleteAtPos(&head, &tail, pos);
			break;
		case 5:
			printf("Enter key and value: ");
			scanf("%d %d", &key, &data);
			insertAfterNode(&head, &tail, key, data);
			break;
		case 6:
			printf("Enter key and value: ");
			scanf("%d %d", &key, &data);
			insertBeforeNode(&head, &tail, key, data);
			break;
		case 7:
			traverseForward(head);
			break;
		case 8:
			traverseReverse(tail);
			break;
		case 9:
			printf("Exiting program.\n");
			freeList(&head, &tail);
			return 0;
		default:
			printf("Invalid choice! Try again.\n");
		}
	}
}

Node *createNode(int data)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	if (!temp)
	{
		printf("Memory allocation failed.\n");
		exit(1);
	}
	temp->data = data;
	temp->prev = temp->next = NULL;
	return temp;
}

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
	printf("Inserted %d at the rear.\n", data);
}

void deleteAtRear(Node **head, Node **tail)
{
	if (*tail == NULL)
	{
		printf("List is empty.\n");
		return;
	}
	Node *temp = *tail;
	if (*head == *tail)
	{
		*head = *tail = NULL;
	}
	else
	{
		*tail = (*tail)->prev;
		(*tail)->next = NULL;
	}
	printf("Deleted %d from the rear.\n", temp->data);
	free(temp);
}

void insertAtPos(Node **head, Node **tail, int pos, int data)
{
	if (pos < 1)
	{
		printf("Invalid position.\n");
		return;
	}
	Node *newNode = createNode(data);
	if (pos == 1)
	{
		newNode->next = *head;
		if (*head)
			(*head)->prev = newNode;
		*head = newNode;
		if (*tail == NULL)
			*tail = newNode;
		printf("Inserted %d at position 1.\n", data);
		return;
	}
	Node *temp = *head;
	for (int i = 1; i < pos - 1 && temp; i++)
	{
		temp = temp->next;
	}
	if (temp == NULL)
	{
		printf("Position out of range.\n");
		free(newNode);
		return;
	}
	newNode->next = temp->next;
	newNode->prev = temp;
	if (temp->next)
		temp->next->prev = newNode;
	temp->next = newNode;
	if (newNode->next == NULL)
		*tail = newNode;
	printf("Inserted %d at position %d.\n", data, pos);
}

void deleteAtPos(Node **head, Node **tail, int pos)
{
	if (pos < 1 || *head == NULL)
	{
		printf("Invalid position or empty list.\n");
		return;
	}
	Node *temp = *head;
	if (pos == 1)
	{
		*head = temp->next;
		if (*head)
			(*head)->prev = NULL;
		else
			*tail = NULL;
		printf("Deleted %d from position 1.\n", temp->data);
		free(temp);
		return;
	}
	for (int i = 1; i < pos && temp; i++)
	{
		temp = temp->next;
	}
	if (temp == NULL)
	{
		printf("Position out of range.\n");
		return;
	}
	if (temp->prev)
		temp->prev->next = temp->next;
	if (temp->next)
		temp->next->prev = temp->prev;
	else
		*tail = temp->prev;
	printf("Deleted %d from position %d.\n", temp->data, pos);
	free(temp);
}

void insertAfterNode(Node **head, Node **tail, int key, int data)
{
	Node *temp = *head;
	while (temp && temp->data != key)
	{
		temp = temp->next;
	}
	if (!temp)
	{
		printf("Value %d not found.\n", key);
		return;
	}
	Node *newNode = createNode(data);
	newNode->next = temp->next;
	newNode->prev = temp;
	if (temp->next)
		temp->next->prev = newNode;
	else
		*tail = newNode;
	temp->next = newNode;
	printf("Inserted %d after %d.\n", data, key);
}

void insertBeforeNode(Node **head, Node **tail, int key, int data)
{
	Node *temp = *head;
	while (temp && temp->data != key)
	{
		temp = temp->next;
	}
	if (!temp)
	{
		printf("Value %d not found.\n", key);
		return;
	}
	Node *newNode = createNode(data);
	newNode->next = temp;
	newNode->prev = temp->prev;
	if (temp->prev)
		temp->prev->next = newNode;
	else
		*head = newNode;
	temp->prev = newNode;
	printf("Inserted %d before %d.\n", data, key);
}

void traverseForward(Node *head)
{
	if (!head)
	{
		printf("List is empty.\n");
		return;
	}
	printf("List (Forward): ");
	for (Node *t = head; t; t = t->next)
	{
		printf("%d ", t->data);
	}
	printf("\n");
}

void traverseReverse(Node *tail)
{
	if (!tail)
	{
		printf("List is empty.\n");
		return;
	}
	printf("List (Reverse): ");
	for (Node *t = tail; t; t = t->prev)
	{
		printf("%d ", t->data);
	}
	printf("\n");
}

void freeList(Node **head, Node **tail)
{
	Node *temp = *head;
	while (temp)
	{
		Node *next = temp->next;
		free(temp);
		temp = next;
	}
	*head = *tail = NULL;
}
