// Write a C program to implement Breadth First Search (BFS).

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Node
{
	int vertex;
	struct Node *next;
} Node;

typedef struct Graph
{
	int vertices;
	Node *adj[MAX];
} Graph;

int queue[MAX];
int front = -1, rear = -1;

int isEmpty();
void enqueue(int val);
int dequeue();
Node *createNode(int v);
Graph *createGraph(int vertices);
void addEdge(Graph *graph, int src, int dest);
void BFS(Graph *graph, int startVertex);

int main()
{
	int vertices, edges, src, dest, start;

	printf("Enter number of vertices: ");
	scanf("%d", &vertices);

	Graph *graph = createGraph(vertices);

	printf("Enter number of edges: ");
	scanf("%d", &edges);

	printf("Enter edges (source destination):\n");
	for (int i = 0; i < edges; i++)
	{
		scanf("%d %d", &src, &dest);
		addEdge(graph, src, dest);
	}

	printf("Enter starting vertex for BFS: ");
	scanf("%d", &start);

	BFS(graph, start);

	for (int i = 0; i < vertices; i++)
	{
		Node *temp = graph->adj[i];
		while (temp)
		{
			Node *toFree = temp;
			temp = temp->next;
			free(toFree);
		}
	}
	free(graph);

	return 0;
}

int isEmpty()
{
	return front == -1;
}

void enqueue(int val)
{
	if (rear == MAX - 1)
	{
		printf("Queue is full\n");
		return;
	}
	if (isEmpty())
		front = 0;
	rear++;
	queue[rear] = val;
}

int dequeue()
{
	if (isEmpty())
		return -1;
	int item = queue[front];
	if (front == rear)
	{
		front = rear = -1;
	}
	else
	{
		front++;
	}
	return item;
}

Node *createNode(int v)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->vertex = v;
	newNode->next = NULL;
	return newNode;
}

Graph *createGraph(int vertices)
{
	Graph *graph = (Graph *)malloc(sizeof(Graph));
	graph->vertices = vertices;
	for (int i = 0; i < vertices; i++)
		graph->adj[i] = NULL;
	return graph;
}

void addEdge(Graph *graph, int src, int dest)
{
	Node *newNode = createNode(dest);
	newNode->next = graph->adj[src];
	graph->adj[src] = newNode;

	newNode = createNode(src);
	newNode->next = graph->adj[dest];
	graph->adj[dest] = newNode;
}

void BFS(Graph *graph, int startVertex)
{
	int visited[MAX] = {0};

	visited[startVertex] = 1;
	enqueue(startVertex);

	printf("BFS traversal starting from vertex %d: ", startVertex);

	while (!isEmpty())
	{
		int currentVertex = dequeue();
		printf("%d ", currentVertex);

		Node *temp = graph->adj[currentVertex];
		while (temp)
		{
			int adjVertex = temp->vertex;
			if (!visited[adjVertex])
			{
				visited[adjVertex] = 1;
				enqueue(adjVertex);
			}
			temp = temp->next;
		}
	}
	printf("\n");
}