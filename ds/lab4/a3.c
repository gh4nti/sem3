// Interleave two lists

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
} Node;

Node *createNode(int data);
void printList(Node *head);
Node *interleaveLists(Node *list1, Node *list2);
void freeList(Node *head);

int main()
{
	// Example list1: 1 -> 3 -> 5 -> 7
	Node *list1 = createNode(1);
	list1->next = createNode(3);
	list1->next->next = createNode(5);
	list1->next->next->next = createNode(7);

	// Example list2: 2 -> 4 -> 6
	Node *list2 = createNode(2);
	list2->next = createNode(4);
	list2->next->next = createNode(6);

	printf("List 1: ");
	printList(list1);
	printf("List 2: ");
	printList(list2);

	Node *list3 = interleaveLists(list1, list2);

	printf("Interleaved List: ");
	printList(list3);

	freeList(list3); // Free merged list
	return 0;
}

// create a new node
Node *createNode(int data)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	if (!temp)
	{
		printf("Memory allocation failed!\n");
		exit(1);
	}
	temp->data = data;
	temp->next = NULL;
	return temp;
}

// print the list
void printList(Node *head)
{
	while (head != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

// free the list
void freeList(Node *head)
{
	while (head)
	{
		Node *temp = head;
		head = head->next;
		free(temp);
	}
}

// interleave two lists
Node *interleaveLists(Node *list1, Node *list2)
{
	if (!list1)
		return list2;
	if (!list2)
		return list1;

	Node *head = list1, *p1 = list1, *p2 = list2;
	Node *temp1, *temp2;

	while (p1 && p2)
	{
		temp1 = p1->next;
		temp2 = p2->next;

		p1->next = p2;

		if (!temp1)
			break; // if list1 ends, stop

		p2->next = temp1;

		p1 = temp1;
		p2 = temp2;
	}

	return head;
}
