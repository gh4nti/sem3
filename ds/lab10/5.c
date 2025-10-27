// Write a program to create an AVL Tree and perform insertion.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *left, *right;
	int height;
} Node;

int height(Node *node);
int max(int a, int b);
Node *createNode(int data);
Node *rightRotate(Node *y);
Node *leftRotate(Node *x);
int getBalance(Node *node);
Node *insert(Node *root, int data);
void inorder(Node *root);

int main()
{
	Node *root = NULL;
	int n, data;

	printf("Enter number of elements to insert: ");
	scanf("%d", &n);

	printf("Enter %d values:\n", n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &data);
		root = insert(root, data);
	}

	printf("\nFinal Inorder traversal (sorted): ");
	inorder(root);
	printf("\n");

	return 0;
}

int height(Node *node)
{
	if (node == NULL)
		return 0;
	return node->height;
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}

Node *createNode(int data)
{
	Node *new = (Node *)malloc(sizeof(Node));
	new->data = data;
	new->left = new->right = NULL;
	new->height = 1;
	return new;
}

Node *rightRotate(Node *y)
{
	Node *x = y->left;
	Node *T2 = x->right;

	x->right = y;
	y->left = T2;

	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

	return x;
}

Node *leftRotate(Node *x)
{
	Node *y = x->right;
	Node *T2 = y->left;

	y->left = x;
	x->right = T2;

	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;

	return y;
}

int getBalance(Node *node)
{
	if (node == NULL)
		return 0;
	return height(node->left) - height(node->right);
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
		return root;

	root->height = 1 + max(height(root->left), height(root->right));

	int balance = getBalance(root);

	if (balance > 1 && data < root->left->data)
		return rightRotate(root);

	if (balance < -1 && data > root->right->data)
		return leftRotate(root);

	if (balance > 1 && data > root->left->data)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	if (balance < -1 && data < root->right->data)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

void inorder(Node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}