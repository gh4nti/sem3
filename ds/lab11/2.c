// Write a C program to represent directed and undirected graphs using adjacency list.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int vertex;
	struct Node *next;
} Node;

typedef struct Graph
{
	int vertices;
	Node **adj;
	int directed;
} Graph;

Node *createNode(int v);
Graph *createGraph(int vertices, int directed);
void addEdge(Graph *graph, int src, int dest);
void printGraph(Graph *graph);
void freeGraph(Graph *graph);

int main()
{
	int vertices, choice, edges, src, dest;

	printf("Enter number of vertices: ");
	scanf("%d", &vertices);

	printf("Choose graph type:\n1. Directed\n2. Undirected\nEnter choice: ");
	scanf("%d", &choice);

	int directed = (choice == 1) ? 1 : 0;
	Graph *graph = createGraph(vertices, directed);

	printf("Enter number of edges: ");
	scanf("%d", &edges);

	printf("Enter edges (source destination):\n");
	for (int i = 0; i < edges; i++)
	{
		scanf("%d %d", &src, &dest);
		if (src < 0 || src >= vertices || dest < 0 || dest >= vertices)
		{
			printf("Invalid edge! Try again.\n");
			i--;
			continue;
		}
		addEdge(graph, src, dest);
	}

	printf("\nGraph adjacency list representation:\n");
	printGraph(graph);

	freeGraph(graph);
	return 0;
}

Node *createNode(int v)
{
	Node *new = (Node *)malloc(sizeof(Node));
	new->vertex = v;
	new->next = NULL;
	return new;
}

Graph *createGraph(int vertices, int directed)
{
	Graph *graph = (Graph *)malloc(sizeof(Graph));
	graph->vertices = vertices;
	graph->directed = directed;

	graph->adj = (Node **)malloc(vertices * sizeof(Node *));
	for (int i = 0; i < vertices; i++)
		graph->adj[i] = NULL;

	return graph;
}

void addEdge(Graph *graph, int src, int dest)
{
	Node *newNode = createNode(dest);
	newNode->next = graph->adj[src];
	graph->adj[src] = newNode;

	if (!graph->directed)
	{
		newNode = createNode(src);
		newNode->next = graph->adj[dest];
		graph->adj[dest] = newNode;
	}
}

void printGraph(Graph *graph)
{
	for (int i = 0; i < graph->vertices; i++)
	{
		Node *temp = graph->adj[i];
		printf("Vertex %d: ", i);
		while (temp)
		{
			printf("-> %d ", temp->vertex);
			temp = temp->next;
		}
		printf("\n");
	}
}
void freeGraph(Graph *graph)
{
	for (int i = 0; i < graph->vertices; i++)
	{
		Node *temp = graph->adj[i];
		while (temp)
		{
			Node *toFree = temp;
			temp = temp->next;
			free(toFree);
		}
	}
	free(graph->adj);
	free(graph);
}