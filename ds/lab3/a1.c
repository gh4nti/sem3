// Write a program in C to find the fast transpose of a sparse matrix represented using array of objects.

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int row;
	int col;
	int value;
} Term;

void fastTranspose(Term *a, Term *b);
void printSparseMatrix(Term *arr);

int main()
{
	int r, c, n;
	int i;

	printf("Enter number of rows, columns and non-zero elements: ");
	scanf("%d %d %d", &r, &c, &n);

	if (n <= 0)
	{
		printf("No non-zero elements to process.\n");
		return 0;
	}

	Term *a = (Term *)malloc((n + 1) * sizeof(Term));
	Term *b = (Term *)malloc((n + 1) * sizeof(Term));

	if (!a || !b)
	{
		printf("Memory allocation failed.\n");
		return 1;
	}

	a->row = r;
	a->col = c;
	a->value = n;

	printf("Enter row, column, and value for each non-zero element:\n");
	for (i = 1; i <= n; i++)
	{
		scanf("%d %d %d", &(a + i)->row, &(a + i)->col, &(a + i)->value);
	}

	printf("Original Sparse Matrix:\n");
	printSparseMatrix(a);

	fastTranspose(a, b);

	printf("\nFast Transpose of Sparse Matrix:\n");
	printSparseMatrix(b);

	free(a);
	free(b);

	return 0;
}

void fastTranspose(Term *a, Term *b)
{
	int n = a->value;
	int numCols = a->col;
	int *rowTerms = (int *)malloc(numCols * sizeof(int));
	int *startingPos = (int *)malloc(numCols * sizeof(int));
	int i, j;

	if (!rowTerms || !startingPos)
	{
		printf("Memory allocation failed in fastTranspose.\n");
		free(rowTerms);
		free(startingPos);
		return;
	}

	b->row = numCols;
	b->col = a->row;
	b->value = n;

	if (n > 0)
	{
		for (i = 0; i < numCols; i++)
		{
			*(rowTerms + i) = 0;
		}

		for (i = 1; i <= n; i++)
		{
			(*(rowTerms + ((a + i)->col)))++;
		}

		*startingPos = 1;
		for (i = 1; i < numCols; i++)
		{
			*(startingPos + i) = *(startingPos + (i - 1)) + *(rowTerms + (i - 1));
		}

		for (i = 1; i <= n; i++)
		{
			j = (*(startingPos + ((a + i)->col)))++;
			(b + j)->row = (a + i)->col;
			(b + j)->col = (a + i)->row;
			(b + j)->value = (a + i)->value;
		}
	}
	free(rowTerms);
	free(startingPos);
}

void printSparseMatrix(Term *arr)
{
	int r = arr->row;
	int c = arr->col;
	int n = arr->value;
	int k = 1;
	int i, j;

	printf("Rows: %d, Columns: %d, Non-zero elements: %d\n", r, c, n);

	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			if (k <= n && (arr + k)->row == i && (arr + k)->col == j)
			{
				printf("%d ", (arr + k)->value);
				k++;
			}
			else
			{
				printf("0 ");
			}
		}
		printf("\n");
	}
}