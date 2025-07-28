// Implement a C program to read, display, and find the product of two matrices using functions with appropriate parameters.

#include <stdio.h>
#include <stdlib.h>

void read(int **arr, int r, int c);
void display(int **arr, int r, int c);
void mult(int **arr1, int **arr2, int r1, int c1, int r2, int c2, int **res);
void free_arr(int **arr, int r);

int main()
{
	int r1, c1, r2, c2;

	printf("Enter rows and columns of first matrix: ");
	scanf("%d%d", &r1, &c1);

	printf("Enter rows and columns of second matrix: ");
	scanf("%d%d", &r2, &c2);

	if (c1 != r2)
	{
		printf("Matrix multiplication is not possible.\n");
		return -1;
	}

	int **arr1 = (int **)malloc(r1 * sizeof(int *));
	int **arr2 = (int **)malloc(r2 * sizeof(int *));
	int **res = (int **)malloc(r1 * sizeof(int *));

	for (int i = 0; i < r1; i++)
	{
		*(arr1 + i) = (int *)malloc(c1 * sizeof(int));
		*(res + i) = (int *)malloc(c2 * sizeof(int));
	}
	for (int i = 0; i < r2; i++)
	{
		*(arr2 + i) = (int *)malloc(c2 * sizeof(int));
	}

	// read matrices
	read(arr1, r1, c1);
	read(arr2, r2, c2);

	// display matrices
	printf("\nFirst matrix:\n");
	display(arr1, r1, c1);

	printf("\nSecond matrix:\n");
	display(arr2, r2, c2);

	// matrix multiplication
	mult(arr1, arr2, r1, c1, r2, c2, res);

	printf("\nResult of matrix multiplication:\n");
	display(res, r1, c2);

	free_arr(arr1, r1);
	free_arr(arr2, r2);
	free_arr(res, r1);

	return 0;
}

void read(int **arr, int r, int c)
{
	printf("Enter the elements of the matrix (%d x %d):\n", r, c);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			printf("Element [%d][%d]: ", i, j);
			scanf("%d", *(arr + i) + j);
		}
	}
}

void display(int **arr, int r, int c)
{
	printf("Matrix (%d x %d):\n", r, c);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			printf("%d ", *(*(arr + i) + j));
		}
		printf("\n");
	}
}

void mult(int **arr1, int **arr2, int r1, int c1, int r2, int c2, int **res)
{
	if (c1 != r2)
	{
		printf("Matrix multiplication is not possible.\n");
		return;
	}

	for (int i = 0; i < r1; i++)
	{
		for (int j = 0; j < c2; j++)
		{
			*(*(res + i) + j) = 0;
		}
	}

	for (int i = 0; i < r1; i++)
	{
		for (int j = 0; j < c2; j++)
		{
			for (int k = 0; k < c1; k++)
			{
				*(*(res + i) + j) += *(*(arr1 + i) + k) * *(*(arr2 + k) + j);
			}
		}
	}
}

void free_arr(int **arr, int r)
{
	for (int i = 0; i < r; i++)
	{
		free(*(arr + i));
	}
	free(arr);
}