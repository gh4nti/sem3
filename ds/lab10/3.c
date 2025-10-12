// Write a function to delete a node from a BST.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *left, *right;
} Node;

Node *createNode(int data);
Node *insert(Node *root, int data);
Node *findMin(Node *node);
Node *deleteNode(Node *root, int key);
void inorder(Node *root);

int main()
{
	Node *root = NULL;
	int n, data, key;

	printf("Enter number of nodes: ");
	scanf("%d", &n);

	printf("Enter %d values:\n", n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &data);
		root = insert(root, data);
	}

	printf("\nInorder traversal before deletion: ");
	inorder(root);

	printf("\n\nEnter element to delete: ");
	scanf("%d", &key);

	root = deleteNode(root, key);

	printf("\nInorder traversal after deletion: ");
	inorder(root);
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

Node *findMin(Node *node)
{
	Node *curr = node;
	while (curr && curr->left != NULL)
		curr = curr->left;
	return curr;
}

Node *deleteNode(Node *root, int key)
{
	if (root == NULL)
		return root;

	if (key < root->data)
		root->left = deleteNode(root->left, key);
	else if (key > root->data)
		root->right = deleteNode(root->right, key);

	else
	{
		if (root->left == NULL)
		{
			Node *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			Node *temp = root->left;
			free(root);
			return temp;
		}

		Node *temp = findMin(root->right);

		root->data = temp->data;
		root->right = deleteNode(root->right, temp->data);
	}

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