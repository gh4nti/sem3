// Write a program to create a BST and perform inorder, preorder, and postorder traversals.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *left, *right;
} Node;

Node *createNode(int data);
Node *insert(Node *root, int data);
void inorder(Node *root);
void preorder(Node *root);
void postorder(Node *root);

int main()
{
	Node *root = NULL;
	int n, c, data;

	printf("Enter number of nodes to insert: ");
	scanf("%d", &n);

	printf("Enter %d values:\n", n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &data);
		root = insert(root, data);
	}

	while (1)
	{
		printf("\nBST menu\n");
		printf("1. Inorder traversal\n");
		printf("2. Preorder traversal\n");
		printf("3. Postorder traversal\n");
		printf("4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &c);

		switch (c)
		{
		case 1:
			inorder(root);
			break;
		case 2:
			preorder(root);
			break;
		case 3:
			postorder(root);
			break;
		case 4:
			printf("Exiting...\n");
			return 0;
		default:
			printf("Invalid choice. Please try again\n");
		}
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
	else
		printf("Duplicate values not allowed in BST.\n");

	return root;
}

void inorder(Node *root)
{
	if (root == NULL)
		return;
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}

void preorder(Node *root)
{
	if (root == NULL)
		return;
	printf("%d ", root->data);
	preorder(root->left);
	preorder(root->right);
}

void postorder(Node *root)
{
	if (root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->data);
}