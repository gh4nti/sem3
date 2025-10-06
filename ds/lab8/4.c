// Create a queue of structures (e.g., queue of patients with name, age, and priority).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Patient
{
	char *name;
	int age, priority;
	struct Patient *next;
} Patient;

Patient *front = NULL, *rear = NULL;

int isEmpty();
void enqueue(char *name, int age, int priority);
void dequeue();
void peek();
void display();

int main()
{
	int c, age, priority;
	char *name = (char *)malloc(100 * sizeof(char));

	while (1)
	{
		printf("\nHospital Queue System\n");
		printf("1. Add Patient\n");
		printf("2. Serve Patient\n");
		printf("3. Show Next Patient\n");
		printf("4. Display All Patients\n");
		printf("5. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &c);
		getchar();

		switch (c)
		{
		case 1:
			printf("Enter patient name: ");
			fgets(name, sizeof(name), stdin);
			name[strcspn(name, "\n")] = 0;

			printf("Enter age: ");
			scanf("%d", &age);
			printf("Enter priority (1=Low, 2=Medium, 3=High): ");
			scanf("%d", &priority);

			enqueue(name, age, priority);
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
			while (!isEmpty())
				dequeue();
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

void enqueue(char *name, int age, int priority)
{
	Patient *new = (Patient *)malloc(sizeof(Patient));
	if (new == NULL)
		return;

	new->name = (char *)malloc(strlen(name) + 1);

	if (new->name == NULL)
	{
		free(new);
		return;
	}

	strcpy(new->name, name);

	new->age = age;
	new->priority = priority;
	new->next = NULL;

	if (rear == NULL)
		front = rear = new;
	else
	{
		rear->next = new;
		rear = new;
	}

	printf("Patient %s (Age: %d, Priority: %d) added to the queue.\n", name, age, priority);
}

void dequeue()
{
	if (isEmpty())
		return;

	Patient *temp = front;
	printf("Serving patient: %s (Age: %d, Priority: %d)\n", temp->name, temp->age, temp->priority);

	front = front->next;
	if (front == NULL)
		rear = NULL;

	free(temp->name);
	free(temp);
}

void peek()
{
	if (isEmpty())
		return;

	printf("Next patient to be served: %s (Age: %d, Priority: %d)\n", front->name, front->age, front->priority);
}

void display()
{
	if (isEmpty())
		return;

	Patient *temp = front;
	while (temp != NULL)
	{
		printf("Name: %-15s  Age: %-3d  Priority: %-2d\n", temp->name, temp->age, temp->priority);
		temp = temp->next;
	}
	printf("\n");
}