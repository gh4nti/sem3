/*
Create a queue using singly linked list to manage patients in a hospital. Use a menu-based program to print the operations in the main function.
1. Add a patient to the rear of the queue.
2. Remove a patient from the front of the queue after completing registration.
3. Display all patients pending registration.
4. Display topmost patient without registering (removing from queue).
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int id;
	char *name;
	struct Node *next;
} Node;

Node *front = NULL;

Node *createNode(int id, char *name);
void enqueue(int id, char *name);
Node *dequeue();
Node *peek();
void printQueue();
void freeQueue();

int main()
{
	int c, i = 0;

	while (1)
	{
		printf("\n--Hospital Registration System--\n");

		printf("1. Add patient\n");
		printf("2. Register topmost patient\n");
		printf("3. Print all patients awaiting registration\n");
		printf("4. View topmost patient without registering\n");
		printf("5. Exit\n");

		printf("Enter your choice: ");
		scanf("%d", &c);

		switch (c)
		{
		case 1:
			char *name = (char *)malloc(100 * sizeof(char));
			printf("\nEnter name of patient: ");
			getchar();
			fgets(name, 100, stdin);

			enqueue(i, name);
			i++;

			printf("Added patient. ID: %d, Name: %s\n", i, name);
			break;

		case 2:
			Node *top = dequeue();
			printf("\nRegistered patient. ID: %d, Name: %s\n", top->id, top->name);

			break;

		case 3:
			printf("Patients yet to be registered:\n");
			printQueue();

			break;

		case 4:
			Node *top = dequeue();
			printf("\nTopmost patient: ID: %d, Name: %s\n", top->id, top->name);

			break;

		case 5:
			printf("Exiting.\n");
			freeQueue();
			exit(1);

			break;

		default:
			printf("Invalid choice.\n");
			break;
		}
	}
}

Node *createNode(int id, char *name)
{
	Node *new = (Node *)malloc(sizeof(Node));
	new->id = id;
	new->name = name;
	new->next = NULL;
	return new;
}

void enqueue(int id, char *name)
{
	Node *new = createNode(id, name);

	if (!front)
	{
		front = new;
		return;
	}

	Node *temp = front;
	while (temp->next)
		temp = temp->next;

	temp->next = new;
}

Node *dequeue()
{
	if (!front)
		return NULL;

	Node *temp = front;
	front = front->next;
	return temp;
}

Node *peek()
{
	if (!front)
		return NULL;

	return front;
}

void printQueue()
{
	if (!front)
		return;

	Node *temp = front;

	while (temp)
	{
		printf("\nPatient ID: %d\n", temp->id);
		printf("Patient Name: %s\n", temp->name);
		temp = temp->next;
	}
}

void freeQueue()
{
	while (front)
	{
		Node *temp = front;
		front = front->next;
		free(temp->name);
		free(temp);
	}
}