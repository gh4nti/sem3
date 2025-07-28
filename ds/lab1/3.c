// Bubble sort, selection sort, and insertion sort

#include <stdio.h>

void swap(int *x, int *y);
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);

int main()
{
	int n;

	printf("Enter the number of elements: ");
	scanf("%d", &n);
	int arr[n];

	printf("Enter the elements:\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("Unsorted array:\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}

	int c;
	printf("\nEnter 1 for bubble sort, 2 for selection sort, or 3 for insertion sort: ");
	scanf("%d", &c);

	printf("Sorted array:\n");
	switch (c)
	{
	case 1:
		bubbleSort(arr, n);
		break;
	case 2:
		selectionSort(arr, n);
		break;
	case 3:
		insertionSort(arr, n);
		break;
	default:
		printf("Invalid choice\n");
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}

void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void bubbleSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

void selectionSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		swap(&arr[min], &arr[i]);
	}
}

void insertionSort(int arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int key = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}