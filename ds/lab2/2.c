// Write a recursive C program to implement selection sort using pointers.

#include <stdio.h>

void swap(int *x, int *y);
void selectionSortRecursive(int *arr, int n);

int main()
{
	int n;

	printf("Enter the number of elements: ");
	scanf("%d", &n);
	int *arr = (int *)malloc(n * sizeof(int));

	printf("Enter the elements: ");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", arr + i);
	}

	selectionSortRecursive(arr, n);

	for (int i = 0; i < n; i++)
	{
		printf("%d ", *(arr + i));
	}

	printf("\n");
	free(arr);
	return 0;
}

void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void selectionSortRecursive(int *arr, int n)
{
	if (n <= 1)
	{
		return;
	}

	int min = 0;
	for (int i = 1; i < n; i++)
	{
		if (*(arr + i) < *(arr + min))
		{
			min = i;
		}
	}

	if (min != 0)
	{
		swap(arr, arr + min);
	}

	selectionSortRecursive(arr + 1, n - 1);
}