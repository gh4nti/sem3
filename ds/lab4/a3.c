// Interleave two lists

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *link;
} Node;

Node *new(int data);
void print(Node *head);
Node *interleave(Node *list1, Node *list2);

int main()
{
	// Example list1: 1 -> 3 -> 5 -> 7
	Node *list1 = new(1);
	list1->link = new(3);
	list1->link->link = new(5);
	list1->link->link->link = new(7);

	// Example list2: 2 -> 4 -> 6
	Node *list2 = new(2);
	list2->link = new(4);
	list2->link->link = new(6);

	printf("List 1: ");
	print(list1);
	printf("List 2: ");
	print(list2);

	Node *list3 = interleave(list1, list2);

	printf("Interleaved List: ");
	print(list3);

	free(list1->link->link->link);
	free(list1->link->link);
	free(list1->link);
	free(list1);
	free(list2->link->link);
	free(list2->link);
	free(list2);
	free(list3->link->link->link);
	free(list3->link->link);
	free(list3->link);
	free(list3);
	return 0;
}

// create a new node
Node *new(int data)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->data = data;
	temp->link = NULL;
	return temp;
}

// print the list
void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->link;
	}
	printf("\n");
}

// interleave two lists
Node *interleave(Node *list1, Node *list2)
{
	if (!list1)
		return list2;
	if (!list2)
		return list1;

	Node *head = list1, *p1 = list1, *p2 = list2, *temp1, *temp2;

	while (p1 && p2)
	{
		temp1 = p1->link;
		temp2 = p2->link;

		p1->link = p2;

		if (!temp1)
			break;
		p2->link = temp1;

		p1 = temp1;
		p2 = temp2;
	}

	return head;
}