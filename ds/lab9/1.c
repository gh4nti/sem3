/*
Write user-defined functions to perform the following operations on binary trees:
i) Inorder traversal (Iterative)
ii) Postorder traversal (Iterative)
iii) Preorder traversal (Iterative)
iv) Print the parent of a given element
v) Print the depth (or height) of the tree
vi) Print the ancestors of a given element
vii) Count the number of leaf nodes in a binary tree
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *left, *right;
} Node;

Node *createNode(int data);
Node *buildTree();
void inorderIterative(Node *root);
void postorderIterative(Node *root);
void preorderIterative(Node *root);
void printParent(Node *root, int key);
int height(Node *root);
int printAncestors(Node *root, int key);
int countLeaves(Node *root);

int main()
{
	printf("Build the binary tree:\n");
	Node *root = buildTree();

	printf("\nInorder Traversal (Iterative): ");
	inorderIterative(root);

	printf("\nPreorder Traversal (Iterative): ");
	preorderIterative(root);

	printf("\nPostorder Traversal (Iterative): ");
	postorderIterative(root);

	int key;
	printf("\n\nEnter element to find its parent: ");
	scanf("%d", &key);
	printParent(root, key);

	printf("\nHeight of tree: %d\n", height(root));

	printf("\nEnter element to find its ancestors: ");
	scanf("%d", &key);
	printf("Ancestors of %d: ", key);
	if (!printAncestors(root, key))
		printf("Element not found.");

	printf("\n\nNumber of leaf nodes: %d\n", countLeaves(root));

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
	printf("Enter data (-1 for no node): ");
	scanf("%d", &data);

	if (data == -1)
		return NULL;

	Node *new = createNode(data);
	printf("Enter left child of %d:\n", data);
	new->left = buildTree();
	printf("Enter right child of %d:\n", data);
	new->right = buildTree();

	return new;
}

void inorderIterative(Node *root)
{
	Node *stack[100];
	int top = -1;
	Node *curr = root;

	while (curr != NULL || top != -1)
	{
		while (curr != NULL)
		{
			stack[++top] = curr;
			curr = curr->left;
		}
		curr = stack[top--];
		printf("%d ", curr->data);
		curr = curr->right;
	}
}

void postorderIterative(Node *root)
{
	if (root == NULL)
		return;

	Node *stack1[100], *stack2[100];
	int top1 = -1, top2 = -1;

	stack1[++top1] = root;

	while (top1 != -1)
	{
		Node *node = stack1[top1--];
		stack2[++top2] = node;

		if (node->left)
			stack1[++top1] = node->left;
		if (node->right)
			stack1[++top1] = node->right;
	}

	while (top2 != -1)
		printf("%d ", stack2[top2--]->data);
}

void preorderIterative(Node *root)
{
	if (root == NULL)
		return;

	Node *stack[100];
	int top = -1;
	stack[++top] = root;

	while (top != -1)
	{
		Node *node = stack[top--];
		printf("%d ", node->data);

		if (node->right)
			stack[++top] = node->right;
		if (node->left)
			stack[++top] = node->left;
	}
}

void printParent(Node *root, int key)
{
	if (root == NULL || root->data == key)
		return;

	Node *queue[100];
	int front = 0, rear = 0;
	queue[rear++] = root;

	while (front < rear)
	{
		Node *node = queue[front++];

		if (node->left)
		{
			if (node->left->data == key)
			{
				printf("Parent of %d is %d\n", key, node->data);
				return;
			}
			queue[rear++] = node->left;
		}

		if (node->right)
		{
			if (node->right->data == key)
			{
				printf("Parent of %d is %d\n", key, node->data);
				return;
			}
			queue[rear++] = node->right;
		}
	}

	printf("Element not found.\n");
}

int height(Node *root)
{
	if (root == NULL)
		return 0;
	int lh = height(root->left);
	int rh = height(root->right);
	return (lh > rh ? lh : rh) + 1;
}

int printAncestors(Node *root, int key)
{
	if (root == NULL)
		return 0;
	if (root->data == key)
		return 1;

	if (printAncestors(root->left, key) || printAncestors(root->right, key))
	{
		printf("%d ", root->data);
		return 1;
	}

	return 0;
}

int countLeaves(Node *root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return countLeaves(root->left) + countLeaves(root->right);
}