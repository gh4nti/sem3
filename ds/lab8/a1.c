/*
Write a C program to implement a queue using two stacks. Simulate the queue operations (enqueue, dequeue, and optionally peek) using the stack data structure. Use either:
• Two stacks and recursion
• Or two stacks and iterative logic
Demonstrate FIFO behavior using LIFO structures.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int s1[MAX], s2[MAX];
int top1 = -1, top2 = -1;

int isEmpty(int *top);
int isFull(int *top);
void push(int *stack, int *top, int val);
int pop(int *stack, int *top);
void enqueue(int val);
int dequeue();
int peek();

int main()
{
	int c, val;

	while (1)
	{
		printf("\nQueue Operations:\n");
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Peek\n");
		printf("4. Exit\n");
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
			val = peek();
			if (val != -1)
				printf("Front element: %d\n", val);
			break;
		case 4:
			printf("Exiting...\n");
			exit(0);
		default:
			printf("Invalid choice! Try again.\n");
		}
	}

	return 0;
}

int isEmpty(int *top) { return *top == -1; }
int isFull(int *top) { return *top == MAX - 1; }

void push(int *stack, int *top, int val)
{
	if (isFull(top))
		return;
	stack[++(*top)] = val;
}

int pop(int *stack, int *top)
{
	if (isEmpty(top))
		return -1;
	return stack[(*top)--];
}

void enqueue(int val)
{
	push(s1, &top1, val);
	printf("%d enqueued to queue\n", val);
}

int dequeue()
{
	if (isEmpty(&top2))
	{
		while (!isEmpty(&top1))
		{
			push(s2, &top2, pop(s1, &top1));
		}
	}
	int val = pop(s2, &top2);
	if (val != -1)
		printf("%d dequeued from queue\n", val);
	return val;
}

int peek()
{
	if (isEmpty(&top2))
	{
		while (!isEmpty(&top1))
		{
			push(s2, &top2, pop(s1, &top1));
		}
	}
	if (!isEmpty(&top2))
		return s2[top2];
	else
	{
		printf("Queue is empty\n");
		return -1;
	}
}