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
Node *insert(Node *node, int key);
void inorder(Node *root);
void preorder(Node *root);

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
		printf("Preorder after inserting %d: ", data);
		preorder(root);
		printf("\n");
	}

	printf("\nFinal Inorder traversal (sorted): ");
	inorder(root);
	printf("\n");

	printf("Final Preorder traversal (AVL structure): ");
	preorder(root);
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

Node *insert(Node *node, int key)
{
	if (node == NULL)
		return createNode(key);

	if (key < node->data)
		node->left = insert(node->left, key);
	else if (key > node->data)
		node->right = insert(node->right, key);
	else
		return node;

	node->height = 1 + max(height(node->left), height(node->right));

	int balance = getBalance(node);

	if (balance > 1 && key < node->left->data)
		return rightRotate(node);

	if (balance < -1 && key > node->right->data)
		return leftRotate(node);

	if (balance > 1 && key > node->left->data)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	if (balance < -1 && key < node->right->data)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
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

void preorder(Node *root)
{
	if (root != NULL)
	{
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}