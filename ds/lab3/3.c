/*
Define a structure Student with the following members:
char name [50] – to store student name as a string
int roll_no – to store roll number
float marks – to store marks

This program:
i. Reads the details of ‘n’ students using a function that uses a pointer to the structure as an argument.
ii. Displays the details of all students using a separate function.
iii. Finds and displays the student with the highest marks using pointer-based access.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Student
{
	char name[50];
	int roll_no;
	float marks;
} Student;

void readStudent(Student *s, int n);
void printStudent(const Student *s, int n);
void findTopper(const Student *s, int n);

int main()
{
	int n;

	printf("Enter the number of students: ");
	if (scanf("%d", &n) != 1 || n <= 0)
	{
		printf("Invalid input. Please enter a positive number.\n");
		return 1;
	}
	getchar();

	Student *students = (Student *)malloc(n * sizeof(Student));

	if (students == NULL)
	{
		printf("Memory allocation failed.\n");
		return -1;
	}

	readStudent(students, n);
	printStudent(students, n);
	findTopper(students, n);

	free(students);
	return 0;
}

void readStudent(Student *s, int n)
{
	for (int i = 0; i < n; i++)
	{
		Student *currentStudent = s + i;
		printf("\nEnter details for student %d:\n", i + 1);

		printf("Name: ");
		fgets(currentStudent->name, sizeof(currentStudent->name), stdin);
		currentStudent->name[strcspn(currentStudent->name, "\n")] = '\0';

		printf("Roll Number: ");
		scanf("%d", &currentStudent->roll_no);
		getchar();

		printf("Marks: ");
		scanf("%f", &currentStudent->marks);
		getchar();
	}
}

void printStudent(const Student *s, int n)
{
	printf("\n--- Student Details ---\n");
	for (int i = 0; i < n; i++)
	{
		printf("\nStudent %d:\n", i + 1);
		printf("  Name: %s\n", (s + i)->name);
		printf("  Roll Number: %d\n", (s + i)->roll_no);
		printf("  Marks: %.2f\n", (s + i)->marks);
	}
}

void findTopper(const Student *s, int n)
{
	if (n <= 0)
	{
		printf("\nNo students to compare.\n");
		return;
	}

	const Student *topStudent = s; // Point to the first student

	for (int i = 1; i < n; i++)
	{
		if ((s + i)->marks > topStudent->marks)
		{
			topStudent = (s + i);
		}
	}

	printf("\n--- Top Student ---\n");
	printf("Name: %s\n", topStudent->name);
	printf("Roll Number: %d\n", topStudent->roll_no);
	printf("Marks: %.2f\n", topStudent->marks);
}
