/*
Merge two singly linked lists alternatively.

Example 1:
list1: 1->3->5->7->NULL
list2: 2->4->6->NULL
merged: 1->2->3->4->5->6->7->NULL

Example 2:
list1: 10->50->20->70->NULL
list2: 9->15->3->80->NULL
merged: 10->9->50->15->20->3->70->80->NULL
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
} Node;

Node *createNode(int data);
void insertAtEnd(Node **head, int data);
Node *mergeListsAlternatively(Node *list1, Node *list2);
void printList(Node *head);
void freeList(Node *head);

int main()
{
	Node *list1 = NULL, *list2 = NULL;
	int n1, n2, val;

	// List 1 input
	printf("Enter number of elements in List 1: ");
	scanf("%d", &n1);
	printf("Enter elements for List 1: ");
	for (int i = 0; i < n1; i++)
	{
		scanf("%d", &val);
		insertAtEnd(&list1, val);
	}

	// List 2 input
	printf("Enter number of elements in List 2: ");
	scanf("%d", &n2);
	printf("Enter elements for List 2: ");
	for (int i = 0; i < n2; i++)
	{
		scanf("%d", &val);
		insertAtEnd(&list2, val);
	}

	printf("\nList 1: ");
	printList(list1);

	printf("List 2: ");
	printList(list2);

	Node *mergedList = mergeListsAlternatively(list1, list2);

	printf("\nMerged list: ");
	printList(mergedList);

	freeList(mergedList);

	return 0;
}

Node *createNode(int data)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void insertAtEnd(Node **head, int data)
{
	Node *newNode = createNode(data);
	if (*head == NULL)
	{
		*head = newNode;
		return;
	}

	Node *temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = newNode;
}

Node *mergeListsAlternatively(Node *list1, Node *list2)
{
	Node *head = list1; // lists get merged into list1
	Node *ptr1 = list1, *ptr2 = list2;
	Node *next1, *next2;

	while (ptr1 != NULL && ptr2 != NULL)
	{
		next1 = ptr1->next;
		next2 = ptr2->next;

		ptr1->next = ptr2;

		if (next1 == NULL)
			break;

		ptr2->next = next1;

		ptr1 = next1;
		ptr2 = next2;
	}
	return head;
}

void printList(Node *head)
{
	while (head != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

void freeList(Node *head)
{
	Node *temp;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}