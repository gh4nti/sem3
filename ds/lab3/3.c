/*
Define a structure Student with the following members:
char name [50] – to store student name as a string
int roll_no – to store roll number
float marks – to store marks

Write a C program that:
i. Reads the details of ‘n’ students using a function that uses pointer to structure as an argument.
ii. Displays the details of all students using a separate function.
iii. Finds and displays the student with the highest marks using pointer-based access.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
	char name[50];
	int roll_no;
	float marks;
};

void read(struct Student *students, int n);
void display(struct Student *students, int n);
void findTopper(struct Student *students, int n);

int main()
{
	int n;

	printf("Enter number of students: ");
	scanf("%d", &n);
	getchar();

	struct Student *students = (struct Student *)malloc(n * sizeof(struct Student));

	if (students == NULL)
	{
		printf("Memory allocation failed.\n");
		return -1;
	}

	read(students, n);
	display(students, n);
	findTopper(students, n);

	free(students);
	return 0;
}

void read(struct Student *students, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("\nEnter details for student %d:\n", i + 1);

		printf("Name: ");
		fgets((students + i)->name, sizeof((students + i)->name), stdin);
		(students + i)->name[strcspn((students + i)->name, "\n")] = '\0'; // Remove newline from name

		printf("Roll Number: ");
		if (scanf("%d", &(students + i)->roll_no) != 1 || (students + i)->roll_no <= 0)
		{
			printf("Invalid roll number. Please enter a positive integer.\n");
			// Handle the error, e.g., by setting a default value or exiting the program
			(students + i)->roll_no = 0; // Set to a default value
			while (getchar() != '\n')
				; // Clear the input buffer
		}
		getchar();

		printf("Marks: ");
		if (scanf("%f", &(students + i)->marks) != 1 || (students + i)->marks < 0 || (students + i)->marks > 100)
		{
			printf("Invalid marks. Please enter a value between 0 and 100.\n");
			// Handle the error
			(students + i)->marks = 0.0; // Set to a default value
			while (getchar() != '\n')
				; // Clear the input buffer
		}
		getchar();
	}
}

void display(struct Student *students, int n)
{
	printf("\nStudent Details:\n");
	for (int i = 0; i < n; i++)
	{
		printf("\nStudent %d:\n", i + 1);
		printf("Name: %s\n", (students + i)->name);
		printf("Roll Number: %d\n", (students + i)->roll_no);
		printf("Marks: %.2f\n", (students + i)->marks);
	}
}

void findTopper(struct Student *students, int n)
{
	if (n <= 0)
	{
		printf("No students available.\n");
		return;
	}

	struct Student *topStudent = students;

	for (int i = 1; i < n; i++)
	{
		if ((students + i)->marks > topStudent->marks)
		{
			topStudent = students + i;
		}
	}

	printf("\nTop Student:\n");
	printf("Name: %s\n", topStudent->name);
	printf("Roll Number: %d\n", topStudent->roll_no);
	printf("Marks: %.2f\n", topStudent->marks);
}