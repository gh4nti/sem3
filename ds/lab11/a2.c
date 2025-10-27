// Detect a cycle in a directed graph using recursion stack.

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

int visited[MAX], stack[MAX];

Node *createNode(int v);
Graph *createGraph(int vertices);
void addEdge(Graph *graph, int src, int dest);
int DFS_Cycle(Graph *graph, int vertex);
int hasCycle(Graph *graph);

int main()
{
	int vertices, edges, src, dest;

	printf("Enter number of vertices: ");
	scanf("%d", &vertices);

	Graph *graph = createGraph(vertices);

	printf("Enter number of edges: ");
	scanf("%d", &edges);

	printf("Enter edges (source destination) for directed graph:\n");
	for (int i = 0; i < edges; i++)
	{
		scanf("%d %d", &src, &dest);
		addEdge(graph, src, dest);
	}

	if (hasCycle(graph))
		printf("Graph contains a cycle.\n");
	else
		printf("Graph does not contain a cycle.\n");

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
}

int DFS_Cycle(Graph *graph, int vertex)
{
	if (!visited[vertex])
	{
		visited[vertex] = 1;
		stack[vertex] = 1;

		Node *temp = graph->adj[vertex];
		while (temp)
		{
			int adjVertex = temp->vertex;
			if (!visited[adjVertex] && DFS_Cycle(graph, adjVertex))
				return 1;
			else if (stack[adjVertex])
				return 1;
			temp = temp->next;
		}
	}

	stack[vertex] = 0;
	return 0;
}

int hasCycle(Graph *graph)
{
	for (int i = 0; i < graph->vertices; i++)
	{
		visited[i] = 0;
		stack[i] = 0;
	}

	for (int i = 0; i < graph->vertices; i++)
	{
		if (DFS_Cycle(graph, i))
			return 1;
	}

	return 0;
}