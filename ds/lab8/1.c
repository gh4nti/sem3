/*
Array-Based Queue Implementation:
Write a C program to simulate a printer queue where tasks arrive randomly and are processed in order.
i. Tasks (with a document ID and name) arrive at random (simulate using random function or user input).
ii. Enqueue each print job.
iii. Dequeue in FIFO order to simulate printing
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX 100

typedef struct PrintJob
{
	int docID;
	char docName[MAX];
} PrintJob;

typedef struct Queue
{
	int front, rear, size;
	unsigned capacity;
	PrintJob *jobArr;
} Queue;

Queue *createQueue(unsigned capacity);
int isFull(Queue *queue);
int isEmpty(Queue *queue);
void enqueue(Queue *queue, PrintJob job);
PrintJob dequeue(Queue *queue);
void printQueue(Queue *queue);
void freeQueue(Queue *queue);
void printMenu();

int main()
{
	Queue *printerQueue = createQueue(5);
	if (printerQueue == NULL)
	{
		return 1;
	}

	int c;
	PrintJob newJob, printedJob;

	while (1)
	{
		printMenu();
		if (scanf("%d", &c) != 1)
		{
			while (getchar() != '\n')
				;
			printf("\n[ERROR] Invalid input. Please enter a number.\n");
			continue;
		}

		switch (c)
		{
		case 1:
			if (isFull(printerQueue))
			{
				printf("\n[ERROR] Queue is full. Cannot add new print job.\n");
				break;
			}
			newJob.docID = rand() % 1000 + 1;
			printf("Enter document name: ");
			while (getchar() != '\n')
				;
			fgets(newJob.docName, MAX, stdin);
			newJob.docName[strcspn(newJob.docName, "\n")] = 0;

			enqueue(printerQueue, newJob);
			break;

		case 2:
			printedJob = dequeue(printerQueue);
			if (printedJob.docID != INT_MIN)
			{
				printf("\n[PRINTING...] Job completed:\n");
				printf(" -> Document ID: %d\n", printedJob.docID);
				printf(" -> Document Name: %s\n", printedJob.docName);
			}
			break;

		case 3:
			printQueue(printerQueue);
			break;

		case 4:
			printf("\nExiting program. Shutting down printer queue.\n");
			freeQueue(printerQueue);
			return 0;

		default:
			printf("\n[ERROR] Invalid choice. Please try again.\n");
			break;
		}
	}

	freeQueue(printerQueue);
	return 0;
}

Queue *createQueue(unsigned capacity)
{
	Queue *queue = (Queue *)malloc(sizeof(Queue));

	if (!queue)
	{
		perror("Failed to allocate memory for queue");
		return NULL;
	}

	queue->capacity = capacity;
	queue->front = 0;
	queue->size = 0;
	queue->rear = capacity - 1;
	queue->jobArr = (PrintJob *)malloc(queue->capacity * sizeof(PrintJob));

	if (!queue->jobArr)
	{
		perror("Failed to allocate memory for job array");
		free(queue);
		return NULL;
	}

	return queue;
}

int isFull(Queue *queue)
{
	return (queue->size == queue->capacity);
}

int isEmpty(Queue *queue)
{
	return (queue->size == 0);
}

void enqueue(Queue *queue, PrintJob job)
{
	if (isFull(queue))
	{
		printf("\n[ERROR] Queue is full. Cannot add new print job.\n");
		return;
	}

	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->jobArr[queue->rear] = job;
	queue->size = queue->size + 1;

	printf("\n[SUCCESS] Added Job: ID %d, Name '%s'\n", job.docID, job.docName);
}

PrintJob dequeue(Queue *queue)
{
	PrintJob job;
	job.docID = INT_MIN;
	strcpy(job.docName, "EMPTY");

	if (isEmpty(queue))
	{
		printf("\n[INFO] Queue is empty. No jobs to print.\n");
		return job;
	}

	job = queue->jobArr[queue->front];

	queue->front = (queue->front + 1) % queue->capacity;
	queue->size = queue->size - 1;

	return job;
}

void printQueue(Queue *queue)
{
	if (isEmpty(queue))
	{
		printf("\n[INFO] Print queue is currently empty.\n");
		return;
	}

	printf("\n--- Current Printer Queue ---\n");
	printf("---------------------------------\n");
	printf("Position | Doc ID | Document Name\n");
	printf("---------------------------------\n");

	int i;
	int pos = 1;

	for (i = 0; i < queue->size; i++)
	{
		int index = (queue->front + i) % queue->capacity;
		printf("%-8d | %-6d | %s\n", pos++, queue->jobArr[index].docID, queue->jobArr[index].docName);
	}
	printf("---------------------------------\n");
	printf("Total jobs in queue: %d\n", queue->size);
}

void freeQueue(Queue *queue)
{
	if (queue)
	{
		if (queue->jobArr)
		{
			free(queue->jobArr);
		}
		free(queue);
	}
}

void printMenu()
{
	printf("\n--- Printer Queue Manager ---\n");
	printf("1. Add a Print Job\n");
	printf("2. Print Next Job\n");
	printf("3. Display Print Queue\n");
	printf("4. Exit\n");
	printf("---------------------------\n");
	printf("Enter your choice: ");
}