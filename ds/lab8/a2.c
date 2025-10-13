/*
Design a data representation to sequentially map n queues into a single array A(1:m). Represent each queue as a circular queue within A. Write the following algorithms:
• ADDQ(i, x) – Add element x to the i-th queue
• DELETEQ(i) – Delete an element from the i-th queue
• QUEUE_FULL() – Check if the array is full and cannot accommodate further insertions
Illustrate the working of your design using a menu-driven C program with appropriate input/output operations for n queues.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_ARRAY 50
#define MAX_QUEUES 5

int A[MAX_ARRAY];
int m, n;

int front[MAX_QUEUES];
int rear[MAX_QUEUES];
int size[MAX_QUEUES];
int capacity[MAX_QUEUES];

void init(int nQ, int arrSize);
int isFull(int i);
int isEmpty(int i);
int QUEUE_FULL();
void ADDQ(int i, int x);
void DELETEQ(int i);
void display();

int main()
{
	int c, nQ, val;

	printf("Enter number of queues (n <= %d): ", MAX_QUEUES);
	scanf("%d", &n);
	printf("Enter total array size (m <= %d): ", MAX_ARRAY);
	scanf("%d", &m);

	initQueues(n, m);

	while (1)
	{
		printf("\nMenu:\n");
		printf("1. Add element to queue\n");
		printf("2. Delete element from queue\n");
		printf("3. Display all queues\n");
		printf("4. Check if array is full\n");
		printf("5. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &c);

		switch (c)
		{
		case 1:
			printf("Enter queue number (1-%d): ", n);
			scanf("%d", &nQ);
			printf("Enter value to add: ");
			scanf("%d", &val);
			ADDQ(nQ - 1, val);
			break;
		case 2:
			printf("Enter queue number (1-%d): ", n);
			scanf("%d", &nQ);
			DELETEQ(nQ - 1);
			break;
		case 3:
			display();
			break;
		case 4:
			if (QUEUE_FULL())
				printf("Array is full. No more insertions possible.\n");
			else
				printf("Array has space for more elements.\n");
			break;
		case 5:
			exit(0);
		default:
			printf("Invalid choice!\n");
		}
	}

	return 0;
}

void init(int nQ, int arrSize)
{
	n = nQ;
	m = arrSize;
	int portion = arrSize / n;

	for (int i = 0; i < n; i++)
	{
		front[i] = rear[i] = -1;
		size[i] = 0;
		capacity[i] = portion;
	}
}

int isFull(int i)
{
	return size[i] == capacity[i];
}

int isEmpty(int i)
{
	return size[i] == 0;
}

int QUEUE_FULL()
{
	int total = 0;
	for (int i = 0; i < n; i++)
		total += size[i];
	return total == m;
}

void ADDQ(int i, int x)
{
	if (i < 0 || i >= n)
		return;

	if (isFull(i))
		return;

	if (front[i] == -1)
		front[i] = 0;

	rear[i] = (rear[i] + 1) % capacity[i];
	A[i * capacity[i] + rear[i]] = x;
	size[i]++;
	printf("%d added to queue %d\n", x, i + 1);
}

void DELETEQ(int i)
{
	if (i < 0 || i >= n)
		return;

	if (isEmpty(i))
		return;

	int val = A[i * capacity[i] + front[i]];
	if (size[i] == 1)
		front[i] = rear[i] = -1;
	else
		front[i] = (front[i] + 1) % capacity[i];

	size[i]--;
	printf("%d deleted from queue %d\n", val, i + 1);
}

void display()
{
	for (int i = 0; i < n; i++)
	{
		printf("Queue %d: ", i + 1);
		if (isEmpty(i))
		{
			printf("Empty\n");
			continue;
		}
		int idx = front[i];
		for (int cnt = 0; cnt < size[i]; cnt++)
		{
			printf("%d ", A[i * capacity[i] + idx]);
			idx = (idx + 1) % capacity[i];
		}
		printf("\n");
	}
}