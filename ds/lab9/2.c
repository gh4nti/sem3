/*
Write a recursive function to:
i) Create a binary tree
ii) Print the binary tree (in traversal order, typically level-order)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *left, *right;
} Node;

Node *createTree();
void inorder(Node *root);
int height(Node *root);
void printLevel(Node *root, int level);
void printLevelOrder(Node *root);

int main()
{
	Node *root = createTree();

	printf("\nInorder Traversal (Recursive): ");
	inorder(root);

	printf("\nLevel Order Traversal: ");
	printLevelOrder(root);

	printf("\n");
	return 0;
}

Node *createTree()
{
	int data;
	printf("Enter data (-1 for no node): ");
	scanf("%d", &data);

	if (data == -1)
		return NULL;

	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;

	printf("Enter left child of %d:\n", data);
	newNode->left = createTree();

	printf("Enter right child of %d:\n", data);
	newNode->right = createTree();

	return newNode;
}

void inorder(Node *root)
{
	if (root == NULL)
		return;
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}

int height(Node *root)
{
	if (root == NULL)
		return 0;
	int lh = height(root->left);
	int rh = height(root->right);
	return (lh > rh ? lh : rh) + 1;
}

void printLevel(Node *root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
		printf("%d ", root->data);
	else
	{
		printLevel(root->left, level - 1);
		printLevel(root->right, level - 1);
	}
}

void printLevelOrder(Node *root)
{
	for (int i = 1; i <= height(root); i++)
		printLevel(root, i);
}