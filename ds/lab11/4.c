// Write a C program to implement Depth First Search (DFS).

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

int visited[MAX];

Node *createNode(int v);
Graph *createGraph(int vertices);
void addEdge(Graph *graph, int src, int dest);
void DFS(Graph *graph, int vertex);

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

	for (int i = 0; i < vertices; i++)
		visited[i] = 0;

	printf("Enter starting vertex for DFS: ");
	scanf("%d", &start);

	printf("DFS traversal starting from vertex %d: ", start);
	DFS(graph, start);
	printf("\n");

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

void DFS(Graph *graph, int vertex)
{
	visited[vertex] = 1;
	printf("%d ", vertex);

	Node *temp = graph->adj[vertex];
	while (temp)
	{
		int adjVertex = temp->vertex;
		if (!visited[adjVertex])
			DFS(graph, adjVertex);
		temp = temp->next;
	}
}