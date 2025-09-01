// Implement multiple stacks in a single array. (using fixed partitioning)

#include <stdio.h>
#include <stdlib.h>

typedef struct MultiStack
{
	int *arr; // single big array
	int *top; // top index of each stack
	int n, k; // total size and number of stacks
	int size; // size of each stack partition
} MultiStack;

MultiStack *init(int k, int n);
int isFull(MultiStack *ms, int sn);
int isEmpty(MultiStack *ms, int sn);
void push(MultiStack *ms, int sn, int val);
int pop(MultiStack *ms, int sn);
void freeMultiStack(MultiStack *ms);

int main()
{
	int k = 3, n = 12;
	MultiStack *ms = init(k, n);

	push(ms, 0, 10);
	push(ms, 0, 20);
	push(ms, 1, 30);
	push(ms, 2, 40);

	printf("Popped from stack 0: %d\n", pop(ms, 0));
	printf("Popped from stack 1: %d\n", pop(ms, 1));
	printf("Popped from stack 2: %d\n", pop(ms, 2));

	freeMultiStack(ms);
	return 0;
}

MultiStack *init(int k, int n)
{
	MultiStack *ms = (MultiStack *)malloc(sizeof(MultiStack));
	ms->k = k;
	ms->n = n;
	ms->size = n / k;

	ms->arr = (int *)malloc(n * sizeof(int));
	ms->top = (int *)malloc(k * sizeof(int));

	for (int i = 0; i < k; i++)
	{
		ms->top[i] = i * ms->size - 1;
	}

	return ms;
}

int isFull(MultiStack *ms, int sn)
{
	return ms->top[sn] == (sn + 1) * ms->size - 1;
}

int isEmpty(MultiStack *ms, int sn)
{
	return ms->top[sn] == sn * ms->size - 1;
}

void push(MultiStack *ms, int sn, int val)
{
	if (isFull(ms, sn))
	{
		printf("Stack %d Overflow!\n", sn);
		return;
	}
	ms->arr[++ms->top[sn]] = val;
}

int pop(MultiStack *ms, int sn)
{
	if (isEmpty(ms, sn))
	{
		printf("Stack %d Underflow!\n", sn);
		return -1;
	}
	return ms->arr[ms->top[sn]--];
}

void freeMultiStack(MultiStack *ms)
{
	free(ms->arr);
	free(ms->top);
	free(ms);
}