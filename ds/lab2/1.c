// Write a small function to find the smallest element in an array using pointers.

#include <stdio.h>
#include <stdlib.h>

int findSmallest(int *arr, int n);

int main()
{
	int n;

	printf("Enter number of elements: ");
	scanf("%d", &n);
	int *arr = (int *)malloc(n * sizeof(int));

	printf("Enter elements: ");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", arr + i);
	}

	printf("Smallest element in array: %d\n", findSmallest(arr, n));
	free(arr);
	return 0;
}

int findSmallest(int *arr, int n)
{
	if (n == 0)
	{
		return -1; // handle empty array
	}

	int smallest = *arr;

	for (int i = 1; i < n; i++)
	{
		arr++;
		if (*arr < smallest)
		{
			smallest = *arr;
		}
	}

	return smallest;
}