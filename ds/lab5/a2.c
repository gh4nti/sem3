// Addition of Long Integers: Write a program to implement the addition of two long positive integers using doubly linked lists. (Each digit can be stored in one node; addition is done from the least significant digit using reverse traversal.)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	int digit;
	struct Node *prev;
	struct Node *next;
} Node;

Node *createNode(int digit);
void insertAtRear(Node **head, Node **tail, int digit);
void insertAtFront(Node **head, Node **tail, int digit);
void printList(Node *head);
void freeList(Node **head);
void convertStringToList(Node **head, Node **tail, const char *str);
Node *addLists(Node *tail1, Node *tail2);

int main()
{
	Node *head1 = NULL, *tail1 = NULL;
	Node *head2 = NULL, *tail2 = NULL;
	Node *sumHead = NULL;

	char *num1 = malloc(1000 * sizeof(char));
	char *num2 = malloc(1000 * sizeof(char));

	if (!num1 || !num2)
	{
		printf("Memory allocation failed!\n");
		return 1;
	}

	printf("Enter first long positive integer: ");
	scanf("%999s", num1);

	printf("Enter second long positive integer: ");
	scanf("%999s", num2);

	// Build linked lists
	convertStringToList(&head1, &tail1, num1);
	convertStringToList(&head2, &tail2, num2);

	printf("First number : ");
	printList(head1);
	printf("Second number: ");
	printList(head2);

	// Add numbers
	sumHead = addLists(tail1, tail2);

	printf("Sum: ");
	printList(sumHead);

	// Free memory
	freeList(&head1);
	freeList(&head2);
	freeList(&sumHead);
	free(num1);
	free(num2);

	return 0;
}

// create a node
Node *createNode(int digit)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	if (!temp)
	{
		printf("Memory allocation failed!\n");
		exit(1);
	}
	temp->digit = digit;
	temp->prev = temp->next = NULL;
	return temp;
}

// insert at rear
void insertAtRear(Node **head, Node **tail, int digit)
{
	Node *newNode = createNode(digit);
	if (*head == NULL)
	{
		*head = *tail = newNode;
	}
	else
	{
		(*tail)->next = newNode;
		newNode->prev = *tail;
		*tail = newNode;
	}
}

// insert at front
void insertAtFront(Node **head, Node **tail, int digit)
{
	Node *newNode = createNode(digit);
	if (*head == NULL)
	{
		*head = *tail = newNode;
	}
	else
	{
		newNode->next = *head;
		(*head)->prev = newNode;
		*head = newNode;
	}
}

// print list
void printList(Node *head)
{
	Node *temp = head;
	while (temp)
	{
		printf("%d", temp->digit);
		temp = temp->next;
	}
	printf("\n");
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

// convert string to list
void convertStringToList(Node **head, Node **tail, const char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		insertAtRear(head, tail, str[i] - '0');
	}
}

// add two lists
Node *addLists(Node *tail1, Node *tail2)
{
	Node *headSum = NULL, *tailSum = NULL;
	int carry = 0;

	while (tail1 != NULL || tail2 != NULL || carry > 0)
	{
		int d1 = (tail1 != NULL) ? tail1->digit : 0;
		int d2 = (tail2 != NULL) ? tail2->digit : 0;
		int sum = d1 + d2 + carry;

		carry = sum / 10;
		sum = sum % 10;

		insertAtFront(&headSum, &tailSum, sum);

		if (tail1)
			tail1 = tail1->prev;
		if (tail2)
			tail2 = tail2->prev;
	}
	return headSum;
}
