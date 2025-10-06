// Implement a queue using a singly linked list with enqueue and dequeue operations.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	int data;
	struct Node *next;
} Node;

Node *front = NULL, *rear = NULL;

int isEmpty();
void enqueue(int val);
void dequeue();
void peek();
void display();

int main()
{
	int c, val;

	while (1)
	{
		printf("\nQueue using singly linked list: menu\n");
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Peek\n");
		printf("4. Display\n");
		printf("5. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &c);

		switch (c)
		{
		case 1:
			printf("Enter value to enqueue: ");
			scanf("%d", &val);
			enqueue(val);
			break;
		case 2:
			dequeue();
			break;
		case 3:
			peek();
			break;
		case 4:
			display();
			break;
		case 5:
			printf("Exiting...\n");
			return 0;
		default:
			printf("Invalid choice! Try again.\n");
		}
	}
}

int isEmpty()
{
	return front == NULL;
}

void enqueue(int val)
{
	Node *new = (Node *)malloc(sizeof(Node));

	if (new == NULL)
		return;

	new->data = val;
	new->next = NULL;

	if (rear == NULL)
		front = rear = new;
	else
	{
		rear->next = new;
		rear = new;
	}

	printf("Enqueued %d\n", val);
}

void dequeue()
{
	if (isEmpty())
		return;

	Node *temp = front;
	int val = temp->data;

	front = front->next;
	if (front == NULL)
		rear = NULL;

	free(temp);
	printf("Dequeued %d\n", val);
}

void peek()
{
	if (isEmpty())
		return;

	printf("First element: %d\n", front->data);
}

void display()
{
	if (isEmpty())
		return;

	Node *temp = front;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}