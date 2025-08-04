// Write a program in C to find the transpose of a sparse matrix represented using array of objects.

#include <stdio.h>
#include <stdlib.h>

typedef struct Term
{
	int row;
	int col;
	int val;
} Term;

void transpose(Term *a, Term *b);
void printSparseMatrix(Term *arr);

int main()
{
	int rows, cols, numTerms;
	int i;

	printf("Enter the number of rows: ");
	scanf("%d", &rows);
	printf("Enter the number of columns: ");
	scanf("%d", &cols);
	printf("Enter the number of non-zero terms: ");
	scanf("%d", &numTerms);

	Term *a = (Term *)malloc((numTerms + 1) * sizeof(Term));
	Term *b = (Term *)malloc((numTerms + 1) * sizeof(Term));

	if (!a || !b)
	{
		printf("Memory allocation failed!\n");
		return 1;
	}

	// First element stores dimensions and number of non-zero terms
	a->row = rows;
	a->col = cols;
	a->val = numTerms;

	printf("Enter the row, column, and value of each non-zero term:\n");
	for (i = 1; i <= numTerms; i++)
	{
		scanf("%d %d %d", &(a + i)->row, &(a + i)->col, &(a + i)->val);
	}

	printf("Original Matrix:\n");
	printSparseMatrix(a);

	transpose(a, b);

	printf("\nTransposed Matrix:\n");
	printSparseMatrix(b);

	free(a);
	free(b);

	return 0;
}

void transpose(Term *a, Term *b)
{
	int n = a->val;	 // Number of non-zero terms
	b->row = a->col; // Rows and columns are swapped
	b->col = a->row;
	b->val = n;

	int i, j;
	int currentB = 1;
	for (i = 0; i < a->col; i++)
	{ // Iterate through each column of original matrix
		for (j = 1; j <= n; j++)
		{ // Find terms in current column
			if ((a + j)->col == i)
			{
				(b + currentB)->row = (a + j)->col;
				(b + currentB)->col = (a + j)->row;
				(b + currentB)->val = (a + j)->val;
				currentB++;
			}
		}
	}
}

void printSparseMatrix(Term *arr)
{
	int rows = arr->row;
	int cols = arr->col;
	int numTerms = arr->val;
	int i, j, k = 1;

	printf("Rows: %d, Columns: %d, Non-zero Terms: %d\n", rows, cols, numTerms);

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			if (k <= numTerms && (arr + k)->row == i && (arr + k)->col == j)
			{
				printf("%d ", (arr + k)->val);
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
