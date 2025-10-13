// Write a program to implement level order traversal on binary search tree.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *left, *right;
} Node;

typedef struct Queue
{
	int front, rear, size;
	struct Node **arr;
} Queue;

Node *createNode(int data);
Node *insert(Node *root, int data);
Queue *createQueue(int capacity);
int isEmpty(Queue *queue);
void enqueue(Queue *queue, Node *node);
Node *dequeue(Queue *queue);
void levelOrder(Node *root);

int main()
{
	Node *root = NULL;
	int n, val;

	printf("Enter number of nodes: ");
	scanf("%d", &n);

	printf("Enter %d values:\n", n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &val);
		root = insert(root, val);
	}

	levelOrder(root);
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

Queue *createQueue(int capacity)
{
	Queue *queue = (Queue *)malloc(sizeof(Queue));
	queue->front = queue->size = 0;
	queue->rear = capacity - 1;
	queue->arr = (Node **)malloc(capacity * sizeof(Node *));
	return queue;
}

int isEmpty(Queue *queue)
{
	return (queue->size == 0);
}

void enqueue(Queue *queue, Node *node)
{
	queue->rear = (queue->rear + 1);
	queue->arr[queue->rear] = node;
	queue->size++;
}

Node *dequeue(Queue *queue)
{
	Node *new = queue->arr[queue->front];
	queue->front++;
	queue->size--;
	return new;
}

void levelOrder(Node *root)
{
	if (root == NULL)
		return;

	Queue *queue = createQueue(100);
	enqueue(queue, root);

	printf("Level Order Traversal: ");
	while (!isEmpty(queue))
	{
		Node *current = dequeue(queue);
		printf("%d ", current->data);

		if (current->left != NULL)
			enqueue(queue, current->left);
		if (current->right != NULL)
			enqueue(queue, current->right);
	}
	printf("\n");
}