// Write a C program to define a student structure with the data members to store name, roll no and grade of the student. Also write the required functions to read, display, and sort student information according to the roll number of the student. All the member functions will have array of objects as arguments.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
	char *name;
	int roll_no;
	char grade;
} Student;

void swap(Student *x, Student *y);
void readStudent(Student *students, int n);
void printStudent(Student *students, int n);
void sortStudents(Student *students, int n);
void freeStudents(Student *students, int n);

int main()
{
	int n;

	printf("Enter number of students: ");
	scanf("%d", &n);
	getchar();

	Student *students = (Student *)malloc(n * sizeof(Student));

	if (students == NULL)
	{
		printf("Memory allocation failed.\n");
		return -1;
	}

	readStudent(students, n);

	printf("Before sorting:\n");
	printStudent(students, n);

	sortStudents(students, n);
	printf("After sorting:\n");
	printStudent(students, n);

	freeStudents(students, n);
	free(students);
	return 0;
}

void swap(Student *x, Student *y)
{
	Student temp = *x;
	*x = *y;
	*y = temp;
}

void readStudent(Student *students, int n)
{
	for (int i = 0; i < n; i++)
	{
		Student *current_student = students + i;

		printf("\nEnter details for student %d:\n", i + 1);

		current_student->name = (char *)malloc(100 * sizeof(char));
		if (current_student->name == NULL)
		{
			printf("Memory allocation for name failed.\n");
			return;
		}

		printf("Name: ");
		fgets(current_student->name, 100, stdin);
		current_student->name[strcspn(current_student->name, "\n")] = '\0';

		printf("Roll Number: ");
		while (scanf("%d", &current_student->roll_no) != 1 || current_student->roll_no <= 0)
		{
			printf("Invalid roll number. Please enter a positive integer.\n");
			while (getchar() != '\n')
				;
		}

		getchar();

		printf("Grade: ");
		while (scanf(" %c", &current_student->grade) != 1)
		{
			printf("Invalid grade.\n");
			while (getchar() != '\n')
				;
		}
	}
}

void printStudent(Student *students, int n)
{
	printf("\nStudent Information:\n");
	for (int i = 0; i < n; i++)
	{
		Student *current_student = students + i;

		printf("\nStudent %d:\n", i + 1);
		printf("Name: %s\n", current_student->name);
		printf("Roll Number: %d\n", current_student->roll_no);
		printf("Grade: %c\n", current_student->grade);
	}
}

void sortStudents(Student *students, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			Student *student_i = students + i;
			Student *student_j = students + j;

			if (student_i->roll_no > student_j->roll_no)
			{
				swap(student_i, student_j);
			}
		}
	}
}

void freeStudents(Student *students, int n)
{
	for (int i = 0; i < n; i++)
	{
		free((students + i)->name);
	}
}
