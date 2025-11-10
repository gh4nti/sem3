/*
Create a BST which holds course codes (example: “CS105”, “BT101”). Use a menu-driven program to print the operations in the main function.
1. Add course codes iteratively.
2. Postorder traversal iteratively.
3. Delete the root and replace it with its inorder successor and print postorder traversal iteratively.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	char *data;
	struct Node *left, *right;
} Node;

typedef struct Stack
{
	Node **data;
	int top;
} Stack;

Node *createNode(char *data);
Node *insert(Node *root, char *data);
int isEmpty(Stack *s);
void push(Stack *s, Node *node);
Node *pop(Stack *s);
void postorder(Node *root);
Node *findMin(Node *node, Node **parent);
Node *findMax(Node *node, Node **parent);
Node *deleteRootReplace(Node *root);
void freeTree(Node *root);

int main()
{
	Node *root = NULL;
	int c;
	char *data = (char *)malloc(100 * sizeof(char));

	while (1)
	{
		printf("\n--Course Registration System--\n");

		printf("1. Add course\n");
		printf("2. Postorder traversal of courses\n");
		printf("3. Delete root and replace with inorder successor, then print postorder\n");
		printf("4. Exit\n");

		printf("Enter choice: ");
		scanf("%d", &c);

		switch (c)
		{
		case 1:
			printf("\nEnter course code: ");
			getchar();
			fgets(data, 100, stdin);

			root = insert(root, data);

			break;

		case 2:
			printf("\nPostorder traversal:\n");
			postorder(root);
			break;

		case 3:
			printf("\nReplacing root with inorder successor:\n");
			root = deleteRootReplace(root);

			printf("\nPostorder traversal:\n");
			postorder(root);
			break;

		case 4:
			printf("\nExiting.\n");
			freeTree(root);
			exit(1);
			break;

		default:
			printf("Invalid choice.\n");
			break;
		}
	}
}

Node *createNode(char *data)
{
	Node *new = (Node *)malloc(sizeof(Node));
	strcpy(new->data, data);
	new->left = new->right = NULL;
	return new;
}

Node *insert(Node *root, char *data)
{
	Node *new = createNode(data);

	if (!root)
		return new;

	Node *curr = root, *parent = NULL;

	while (curr)
	{
		parent = curr;
		int cmp = strcmp(data, curr->data);
		if (cmp < 0)
			curr = curr->left;
		else if (cmp > 0)
			curr = curr->right;
		else
		{
			free(new);
			return root;
		}
	}

	if (strcmp(data, parent->data) < 0)
		parent->left = new;
	else
		parent->right = new;

	return root;
}

int isEmpty(Stack *s)
{
	return s->top == -1;
}

void push(Stack *s, Node *node)
{
	if (s->top < 99)
		s->data[++(s->top)] = node;
}

Node *pop(Stack *s)
{
	if (s->top >= 0)
		return s->data[(s->top)--];
	return NULL;
}

void postorder(Node *root)
{
	if (!root)
		return;

	Stack s1 = {.top = -1}, s2 = {.top = -1};
	push(&s1, root);

	while (!isEmpty(&s1))
	{
		Node *node = pop(&s1);
		push(&s2, node);
		if (node->left)
			push(&s1, node->left);
		if (node->right)
			push(&s1, node->right);
	}

	while (!isEmpty(&s2))
	{
		Node *node = pop(&s2);
		printf("%s ", node->data);
	}

	printf("\n");
}

Node *findMin(Node *node, Node **parent)
{
	*parent = node;
	node = node->right;

	while (node->left)
	{
		*parent = node;
		node = node->left;
	}

	return node;
}

Node *findMax(Node *node, Node **parent)
{
	*parent = node;
	node = node->left;

	while (node->right)
	{
		*parent = node;
		node = node->right;
	}

	return node;
}

Node *deleteRootReplace(Node *root)
{
	if (!root)
		return NULL;

	if (root->right)
	{
		Node *parent = root, *succ = findMin(root, &parent);
		strcpy(root->data, succ->data);

		if (parent->left == succ)
			parent->left = succ->right;
		else
			parent->right = succ->right;

		free(succ);
		return root;
	}

	if (root->left)
	{
		Node *parent = root, *pred = findMax(root, &parent);
		strcpy(root->data, pred->data);

		if (parent->right == pred)
			parent->right = pred->left;
		else
			parent->left = pred->left;

		free(pred);
		return root;
	}

	free(root);
	return NULL;
}

void freeTree(Node *root)
{
	if (!root)
		return;

	freeTree(root->left);
	freeTree(root->right);
	free(root);
}