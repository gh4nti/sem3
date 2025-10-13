// Write a program to check if one binary tree is the mirror image of another.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *left, *right;
} Node;

Node *createNode(int data);
Node *buildTree();
int isMirror(Node *root1, Node *root2);

int main()
{
	printf("Enter the first binary tree:\n");
	Node *root1 = buildTree();

	printf("\nEnter the second binary tree:\n");
	Node *root2 = buildTree();

	if (isMirror(root1, root2))
		printf("\nThe two binary trees are mirror images of each other.\n");
	else
		printf("\nThe two binary trees are NOT mirror images of each other.\n");

	return 0;
}

Node *createNode(int data)
{
	Node *new = (Node *)malloc(sizeof(Node));
	new->data = data;
	new->left = new->right = NULL;
	return new;
}

Node *buildTree()
{
	int data;
	printf("Enter node data (-1 for NULL): ");
	scanf("%d", &data);

	if (data == -1)
		return NULL;

	Node *new = newNode(data);

	printf("Enter left child of %d\n", data);
	new->left = buildTree();

	printf("Enter right child of %d\n", data);
	new->right = buildTree();

	return new;
}

int isMirror(Node *root1, Node *root2)
{
	if (root1 == NULL && root2 == NULL)
		return 1;

	if (root1 == NULL || root2 == NULL)
		return 0;

	return (root1->data == root2->data) &&
		   isMirror(root1->left, root2->right) &&
		   isMirror(root1->right, root2->left);
}