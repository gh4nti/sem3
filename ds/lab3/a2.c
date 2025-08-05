// Write a program in C to find the transpose of a sparse matrix represented using array of objects.

#include <stdio.h>
#include <stdlib.h>

typedef struct Term
{
	int r, c, v;
} Term;

void transpose(Term *a, Term *b);

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
	for (int i = 1; i <= a->v; i++)
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

	transpose(a, b);

	printf("\nTransposed matrix:\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d %d %d\n", b[i].r, b[i].c, b[i].v);
	}

	free(a);
	free(b);
	return 0;
}

void transpose(Term *a, Term *b)
{
	int n = a->v;
	b->r = a->c;
	b->c = a->r;
	b->v = n;

	if (n > 0)
	{
		int k = 1;

		for (int i = 0; i < a->c; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (a[j].c == i)
				{
					b[k].r = a[j].c;
					b[k].c = a[j].r;
					b[k].v = a[j].v;
					k++;
				}
			}
		}
	}
}