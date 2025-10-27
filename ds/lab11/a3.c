// Check if a graph is bipartite using BFS.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define UNCOLORED -1

typedef struct Node
{
	int vertex;
	struct Node *next;
} Node;

typedef struct Graph
{
	int numVertices;
	Node *adj[MAX];
} Graph;

int queue[MAX];
int front = -1, rear = -1;

int isEmpty();
void enqueue(int value);
int dequeue();
Node *createNode(int v);
Graph *createGraph(int vertices);
void addEdge(Graph *graph, int src, int dest);
int isBipartite(Graph *graph, int start);
int checkBipartite(Graph *graph);

int main()
{
	int vertices, edges, src, dest;

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

	if (checkBipartite(graph))
		printf("Graph is bipartite.\n");
	else
		printf("Graph is not bipartite.\n");

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

void enqueue(int value)
{
	if (rear == MAX - 1)
		return;
	if (isEmpty())
		front = 0;
	queue[++rear] = value;
}

int dequeue()
{
	if (isEmpty())
		return -1;
	int item = queue[front];
	if (front == rear)
		front = rear = -1;
	else
		front++;
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
	graph->numVertices = vertices;
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

int isBipartite(Graph *graph, int start)
{
	int color[MAX];
	for (int i = 0; i < graph->numVertices; i++)
		color[i] = UNCOLORED;

	color[start] = 0;
	enqueue(start);

	while (!isEmpty())
	{
		int u = dequeue();
		Node *temp = graph->adj[u];
		while (temp)
		{
			int v = temp->vertex;
			if (color[v] == UNCOLORED)
			{
				color[v] = 1 - color[u];
				enqueue(v);
			}
			else if (color[v] == color[u])
			{
				return 0;
			}
			temp = temp->next;
		}
	}
	return 1;
}

int checkBipartite(Graph *graph)
{
	int color[MAX];
	for (int i = 0; i < graph->numVertices; i++)
		color[i] = UNCOLORED;

	for (int i = 0; i < graph->numVertices; i++)
	{
		if (color[i] == UNCOLORED)
		{
			front = rear = -1;
			color[i] = 0;
			enqueue(i);

			while (!isEmpty())
			{
				int u = dequeue();
				Node *temp = graph->adj[u];
				while (temp)
				{
					int v = temp->vertex;
					if (color[v] == UNCOLORED)
					{
						color[v] = 1 - color[u];
						enqueue(v);
					}
					else if (color[v] == color[u])
					{
						return 0;
					}
					temp = temp->next;
				}
			}
		}
	}
	return 1;
}