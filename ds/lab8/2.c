// Write a C program to implement a circular queue using arrays.

#include <stdio.h>
#define SIZE 100

int queue[SIZE];
int front = -1, rear = -1;

int isEmpty();
int isFull();
void enqueue(int val);
void dequeue();
void peek();
void display();

int main()
{
	int c, val;

	while (1)
	{
		printf("\nCircular queue menu:\n");
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Peek\n");
		printf("4. Display\n");
		printf("5. Exit\n");
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
	return front == -1;
}

int isFull()
{
	return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
}

void enqueue(int val)
{
	if (isFull())
		return;

	if (front == -1)
		front = 0;

	rear = (rear + 1) % SIZE;
	queue[rear] = val;

	printf("Enqueued %d\n", val);
}

void dequeue()
{
	if (isEmpty())
		return;

	int val = queue[front];

	if (front == rear)
		front = rear = -1;
	else
		front = (front + 1) % SIZE;

	printf("Dequeued %d\n", val);
}

void peek()
{
	if (isEmpty())
		return;

	printf("Front element: %d\n", queue[front]);
}

void display()
{
	if (isEmpty())
		return;

	int i = front;
	while (1)
	{
		printf("%d ", queue[i]);
		if (i == rear)
			break;
		i = (i + 1) % SIZE;
	}
}