// Write a C program to define a student structure with the data members to store name, roll no and grade of the student. Also write the required functions to read, display, and sort student information according to the roll number of the student. All the member functions will have array of objects as arguments.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
	char name[50];
	int roll_no;
	char grade;
};

void read(struct student *students, int n);
void display(struct student *students, int n);
void sort(struct student *students, int n);

int main()
{
	int n;

	printf("Enter number of students: ");
	scanf("%d", &n);
	getchar();

	struct student *students = (struct student *)malloc(n * sizeof(struct student));

	if (students == NULL)
	{
		printf("Memory allocation failed.\n");
		return -1;
	}

	read(students, n);

	printf("Before sorting:\n");
	display(students, n);
	sort(students, n);

	printf("After sorting:\n");
	display(students, n);

	free(students);
	return 0;
}

void read(struct student *students, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("\nEnter details for student %d:\n", i + 1);

		printf("Name: ");
		fgets(((students + i))->name, sizeof(((students + i))->name), stdin);
		((students + i))->name[strcspn(((students + i))->name, "\n")] = '\0'; // remove the newline character

		printf("Roll Number: ");
		if (scanf("%d", &((students + i))->roll_no) != 1 || ((students + i))->roll_no <= 0)
		{
			printf("Invalid roll number. Please enter a positive integer.\n");
			// Handle the error, e.g., by setting a default value or exiting the program
			((students + i))->roll_no = 0; // Set to a default value
			while (getchar() != '\n')
				; // Clear the input buffer
		}
		getchar();

		printf("Grade: ");
		if (scanf(" %c", &((students + i))->grade) != 1)
		{
			printf("Invalid grade.\n");
			// Handle the error
			((students + i))->grade = ' '; // Set to a default value
			while (getchar() != '\n')
				; // Clear the input buffer
		}
		getchar();
	}
}

void display(struct student *students, int n)
{
	printf("\nStudent Information:\n");
	for (int i = 0; i < n; i++)
	{
		printf("\nStudent %d:\n", i + 1);
		printf("Name: %s\n", (students + i)->name);
		printf("Roll Number: %d\n", (students + i)->roll_no);
		printf("Grade: %c\n", (students + i)->grade);
	}
}

void sort(struct student *students, int n)
{
	struct student tmp;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if ((students + i)->roll_no > (students + j)->roll_no)
			{
				tmp = *(students + i);
				*(students + i) = *(students + j);
				*(students + j) = tmp;
			}
		}
	}
}