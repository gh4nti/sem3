// Write a program to convert a BST into a sorted doubly linked list.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *left, *right;
} Node;

Node *prev = NULL, *head = NULL;

Node *createNode(int data);
Node *insert(Node *root, int data);
void BSTtoDLL(Node *root);
void printDLL(Node *head);

int main()
{
	Node *root = NULL;
	int n, val;

	printf("Enter number of nodes: ");
	scanf("%d", &n);

	printf("Enter %d values:\n", n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &val);
		root = insert(root, val);
	}

	BSTtoDLL(root);
	printDLL(head);
	return 0;
}

Node *createNode(int data)
{
	Node *new = (Node *)malloc(sizeof(Node));
	new->data = data;
	new->left = new->right = NULL;
	return new;
}

Node *insert(Node *root, int data)
{
	if (root == NULL)
		return createNode(data);

	if (data < root->data)
		root->left = insert(root->left, data);
	else if (data > root->data)
		root->right = insert(root->right, data);
	else
		printf("Duplicate values not allowed in BST.\n");

	return root;
}

void BSTtoDLL(Node *root)
{
	if (root == NULL)
		return;

	BSTtoDLL(root->left);

	if (prev == NULL)
		head = root;
	else
	{
		root->left = prev;
		prev->right = root;
	}
	prev = root;

	BSTtoDLL(root->right);
}

void printDLL(Node *head)
{
	Node *temp = head;
	printf("Sorted Doubly Linked List: ");
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->right;
	}
	printf("\n");
}