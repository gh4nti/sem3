// Write a program in C to find the fast transpose of a sparse matrix represented using array of objects.

#include <stdio.h>
#include <stdlib.h>

typedef struct Term
{
	int r, c, v;
} Term;

void fastTranspose(Term *a, Term *b);

int main()
{
	int n;
	printf("Enter the number of non-zero elements: ");
	scanf("%d", &n);
	Term *a = (Term *)malloc((n + 1) * sizeof(Term));
	a->v = n;

	if (a == NULL)
	{
		printf("Memory allocation failed.\n");
		return -1;
	}

	printf("Enter number of rows and columns: ");
	scanf("%d %d", &a->r, &a->c);

	printf("Enter elements in the format: row column value\n");
	for (int i = 1; i < a->v + 1; i++)
	{
		scanf("%d %d %d", &a[i].r, &a[i].c, &a[i].v);
	}

	printf("\nOriginal matrix:\n");
	for (int i = 0; i <= a->v; i++)
	{
		printf("%d %d %d\n", a[i].r, a[i].c, a[i].v);
	}

	Term *b = (Term *)malloc((n + 1) * sizeof(Term));
	if (b == NULL)
	{
		printf("Memory allocation failed.\n");
		free(a);
		return -1;
	}

	fastTranspose(a, b);

	printf("\nFast transposed matrix:\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d %d %d\n", b[i].r, b[i].c, b[i].v);
	}

	free(a);
	free(b);
	return 0;
}

void fastTranspose(Term *a, Term *b)
{
	int *rowTerms = (int *)malloc((a->c + 1) * sizeof(int));
	int *startingPos = (int *)malloc((a->c + 1) * sizeof(int));

	if (rowTerms == NULL || startingPos == NULL)
	{
		printf("Memory allocation failed.\n");
		exit(-1);
	}

	b->r = a->c;
	b->c = a->r;
	b->v = a->v;

	if (a->v > 0)
	{
		for (int i = 0; i < a->c; i++)
			rowTerms[i] = 0;
		for (int i = 1; i <= a->v; i++)
			rowTerms[a[i].c]++;

		startingPos[0] = 1;

		for (int i = 1; i < a->c; i++)
			startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];

		for (int i = 1; i <= a->v; i++)
		{
			int j = startingPos[a[i].c]++;
			b[j].r = a[i].c;
			b[j].c = a[i].r;
			b[j].v = a[i].v;
		}
	}
}