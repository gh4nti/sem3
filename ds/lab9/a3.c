// Write a program to copy one binary tree to another.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *left, *right;
} Node;

Node *createNode(int data);
Node *buildTree();
Node *copyTree(Node *root);
void inorder(Node *root);

int main()
{
	printf("Enter the original binary tree:\n");
	struct Node *root = buildTree();

	struct Node *copy = copyTree(root);

	printf("\nInorder traversal of original tree: ");
	inorder(root);

	printf("\nInorder traversal of copied tree:   ");
	inorder(copy);
	printf("\n");

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

Node *copyTree(Node *root)
{
	if (root == NULL)
		return NULL;

	Node *newRoot = newNode(root->data);
	newRoot->left = copyTree(root->left);
	newRoot->right = copyTree(root->right);
	return newRoot;
}

void inorder(Node *root)
{
	if (root == NULL)
		return;
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}