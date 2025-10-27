// Write a function to find the minimum and maximum elements in a BST.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *left, *right;
} Node;

Node *createNode(int data);
Node *insert(Node *root, int data);
Node *findMin(Node *root);
Node *findMax(Node *root);
void inorder(Node *root);

int main()
{
	Node *root = NULL;
	int n, data;

	printf("Enter number of nodes: ");
	scanf("%d", &n);

	printf("Enter %d values:\n", n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &data);
		root = insert(root, data);
	}

	printf("\nInorder traversal of BST: ");
	inorder(root);

	Node *minNode = findMin(root);
	Node *maxNode = findMax(root);

	if (minNode != NULL && maxNode != NULL)
	{
		printf("\n\nMinimum element in BST: %d", minNode->data);
		printf("\nMaximum element in BST: %d\n", maxNode->data);
	}
	else
	{
		printf("\nBST is empty.\n");
	}

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

	return root;
}

Node *findMin(Node *root)
{
	if (root == NULL)
		return NULL;

	Node *curr = root;
	while (curr->left != NULL)
		curr = curr->left;
	return curr;
}

Node *findMax(Node *root)
{
	if (root == NULL)
		return NULL;

	Node *curr = root;
	while (curr->right != NULL)
		curr = curr->right;
	return curr;
}

void inorder(Node *root)
{
	if (root == NULL)
		return;

	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}