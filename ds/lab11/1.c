// Write a C program to represent directed and undirected graphs using adjacency matrix.

#include <stdio.h>
#define MAX 100

void createGraph(int graph[MAX][MAX], int vertices, int directed);
void printGraph(int graph[MAX][MAX], int vertices);

int main()
{
	int graph[MAX][MAX];
	int vertices, choice;

	printf("Enter number of vertices: ");
	scanf("%d", &vertices);

	printf("Choose graph type:\n1. Directed\n2. Undirected\nEnter choice: ");
	scanf("%d", &choice);

	if (choice != 1 && choice != 2)
	{
		printf("Invalid choice!\n");
		return 0;
	}

	int directed = (choice == 1) ? 1 : 0;

	createGraph(graph, vertices, directed);
	printGraph(graph, vertices);
}

void createGraph(int graph[MAX][MAX], int vertices, int directed)
{
	int edges, src, dest;

	for (int i = 0; i < vertices; i++)
	{
		for (int j = 0; j < vertices; j++)
			graph[i][j] = 0;
	}

	printf("Enter the number of edges: ");
	scanf("%d", &edges);

	printf("Enter the edges (source destination):\n");
	for (int i = 0; i < edges; i++)
	{
		scanf("%d %d", &src, &dest);

		if (src >= vertices || dest >= vertices || src < 0 || dest < 0)
		{
			printf("Invalid edge! Skipping.\n");
			i--;
			continue;
		}

		graph[src][dest] = 1;

		if (!directed)
		{
			graph[dest][src] = 1;
		}
	}
}

void printGraph(int graph[MAX][MAX], int vertices)
{
	printf("\nAdjacency Matrix:\n");
	for (int i = 0; i < vertices; i++)
	{
		for (int j = 0; j < vertices; j++)
			printf("%d ", graph[i][j]);
		printf("\n");
	}
}