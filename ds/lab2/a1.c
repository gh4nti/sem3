// Write a C program to simulate the working of the Tower of Hanoi problem using recursion for n disks.

#include <stdio.h>

void towerOfHanoi(int n, char source, char aux, char dest);

int main()
{
	int n;

	printf("Enter number of disks: ");
	scanf("%d", &n);

	printf("\nSequence of moves:\n");
	towerOfHanoi(n, 'A', 'B', 'C');
}

void towerOfHanoi(int n, char source, char aux, char dest)
{
	// base case
	if (n == 1)
	{
		printf("Move disk 1 from %c to %c\n", source, dest);
		return;
	}

	// move top n - 1 disks from source to aux, using dest as aux
	towerOfHanoi(n - 1, source, dest, aux);

	// move nth disk from source to dest
	printf("Move disk %d from %c to %c\n", n, source, dest);

	// move top n - 1 disks from aux to dest, using source as aux
	towerOfHanoi(n - 1, aux, source, dest);
}