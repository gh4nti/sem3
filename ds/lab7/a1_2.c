// Implement multiple stacks in a single array. (using K-Stacks algorithm)

#include <stdio.h>
#include <stdlib.h>

typedef struct KStacks
{
	int *arr;	 // data array
	int *top;	 // top index for each stack
	int *next;	 // next free slot or link to previous element
	int freeTop; // index of next free slot
	int n, k;	 // total size and number of stacks
} KStacks;

KStacks *init(int k, int n);
int isFull(KStacks *ks);
int isEmpty(KStacks *ks, int sn);
void push(KStacks *ks, int sn, int val);
int pop(KStacks *ks, int sn);
void freeKStacks(KStacks *ks);

int main()
{
	int k = 3, n = 10;
	KStacks *ks = init(k, n);

	push(ks, 0, 15);
	push(ks, 1, 45);
	push(ks, 2, 30);
	push(ks, 0, 20);

	printf("Popped from stack 0: %d\n", pop(ks, 0));
	printf("Popped from stack 1: %d\n", pop(ks, 1));
	printf("Popped from stack 2: %d\n", pop(ks, 2));

	freeKStacks(ks);
	return 0;
}

KStacks *init(int k, int n)
{
	KStacks *ks = (KStacks *)malloc(sizeof(KStacks));
	ks->k = k;
	ks->n = n;

	ks->arr = (int *)malloc(n * sizeof(int));
	ks->top = (int *)malloc(k * sizeof(int));
	ks->next = (int *)malloc(n * sizeof(int));

	for (int i = 0; i < k; i++)
		ks->top[i] = -1;

	ks->freeTop = 0;
	for (int i = 0; i < n - 1; i++)
		ks->next[i] = i + 1;
	ks->next[n - 1] = -1;

	return ks;
}

int isFull(KStacks *ks)
{
	return ks->freeTop == -1;
}

int isEmpty(KStacks *ks, int sn)
{
	return ks->top[sn] == -1;
}

void push(KStacks *ks, int sn, int val)
{
	if (isFull(ks))
	{
		printf("Stack Overflow!\n");
		return;
	}

	int i = ks->freeTop;	   // get free index
	ks->freeTop = ks->next[i]; // update free list

	ks->next[i] = ks->top[sn]; // link with previous top
	ks->top[sn] = i;		   // new top
	ks->arr[i] = val;
}

int pop(KStacks *ks, int sn)
{
	if (isEmpty(ks, sn))
	{
		printf("Stack Underflow!\n");
		return -1;
	}

	int i = ks->top[sn];	   // index of top item
	ks->top[sn] = ks->next[i]; // change top to next element
	ks->next[i] = ks->freeTop; // put this index in free list
	ks->freeTop = i;

	return ks->arr[i];
}

void freeKStacks(KStacks *ks)
{
	free(ks->arr);
	free(ks->top);
	free(ks->next);
	free(ks);
}