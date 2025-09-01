/*
Washing Machine Rental System Simulation: Develop a C application to simulate a washing machine rental queue using a circular doubly linked list.
Requirements:
i. Each user books the washing machine for a specific time.
ii. After time expires, the machine automatically passes to the next  user  in  the queue.
iii. Use the circular nature of the list to model the continuous cycle of usage.
iv. Optional: simulate time using delays or counters for testing logic.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	char *name;
	int time;
	struct Node *prev, *next;
} Node;

typedef struct Queue
{
	Node *first, *current, *last;
} Queue;

Node *createNode(const char *name, int time);
void insertUser(Queue *queue, const char *name, int time);
void simulateStep(Queue *queue);
void printQueue(Queue *queue);
void freeList(Queue *queue);

int main()
{
	Queue queue = {NULL, NULL, NULL};
	int c, time;
	char *name = (char *)malloc(100 * sizeof(char));

	while (1)
	{
		printf("\nWashing Machine Rental Simulation:\n");
		printf("1. Add user to queue\n");
		printf("2. Simulate one usage step\n");
		printf("3. Display queue\n");
		printf("4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &c);

		switch (c)
		{
		case 1:
			printf("Enter user name: ");
			scanf("%s", name);
			printf("Enter booking time (seconds): ");
			scanf("%d", &time);
			insertUser(&queue, name, time);
			break;

		case 2:
			simulateStep(&queue);
			break;

		case 3:
			printQueue(&queue);
			break;

		case 4:
			freeList(&queue);
			free(name);
			printf("Queue freed and program exiting.\n");
			return 0;

		default:
			printf("Invalid choice! Please try again.\n");
		}
	}
	return 0;
}

Node *createNode(const char *name, int time)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		printf("Memory allocation failed for node!\n");
		exit(1);
	}

	newNode->name = (char *)malloc(strlen(name) + 1); // +1 for null terminator
	if (newNode->name == NULL)
	{
		printf("Memory allocation failed for name!\n");
		free(newNode);
		exit(1);
	}
	strcpy(newNode->name, name);
	newNode->time = time;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

void insertUser(Queue *queue, const char *name, int time)
{
	Node *newNode = createNode(name, time);

	if (queue->first == NULL)
	{
		queue->first = queue->last = newNode;
		newNode->next = newNode;
		newNode->prev = newNode;
	}
	else
	{
		newNode->prev = queue->last;
		newNode->next = queue->first;
		queue->last->next = newNode;
		queue->first->prev = newNode;
		queue->last = newNode;
	}
	printf("User %s added with %d seconds booking.\n", name, time);
}

void simulateStep(Queue *queue)
{
	if (queue->first == NULL)
	{
		printf("No users in the queue!\n");
		return;
	}

	if (queue->current == NULL)
	{
		queue->current = queue->first;
	}

	printf("User %s is using the washing machine for %d seconds.\n", queue->current->name, queue->current->time);
	printf("Time expired. Passing the machine to the next user.\n");

	queue->current = queue->current->next;
}

void printQueue(Queue *queue)
{
	if (queue->first == NULL)
	{
		printf("Queue is empty!\n");
		return;
	}

	Node *curr = queue->first;
	printf("Current queue (user - time): ");
	do
	{
		printf("%s (%d) ", curr->name, curr->time);
		curr = curr->next;
	} while (curr != queue->first);
	printf("\n");
}

void freeList(Queue *queue)
{
	if (queue->first == NULL)
		return;

	queue->last->next = NULL;

	Node *curr = queue->first;
	Node *next;
	while (curr != NULL)
	{
		next = curr->next;
		free(curr->name);
		free(curr);
		curr = next;
	}

	queue->first = queue->last = queue->current = NULL;
}
