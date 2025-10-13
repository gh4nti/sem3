// Write a function to search an element in a BST.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *left, *right;
} Node;

Node *createNode(int data);
Node *insert(Node *root, int data);
Node *search(Node *root, int key);
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

	printf("\nInorder Traversal: ");
	inorder(root);

	printf("\n\nEnter element to search: ");
	scanf("%d", &key);

	Node *result = search(root, key);
	if (result != NULL)
		printf("Element %d found in the BST.\n", key);
	else
		printf("Element %d not found in the BST.\n", key);

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

Node *search(Node *root, int key)
{
	if (root == NULL || root->data == key)
		return root;

	if (key < root->data)
		return search(root->left, key);
	else
		return search(root->right, key);
}

void inorder(Node *root)
{
	if (root == NULL)
		return;
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}