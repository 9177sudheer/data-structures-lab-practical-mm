#include <stdio.h>
#include <stdlib.h>

struct Node {
  int vertex;
  struct Node* next;
};

struct Graph {
  int numVertices;
  int* visited;
  struct Node** adjLists;
};

struct Node* createNode(int v) {
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

struct Graph* createGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;
  graph->visited = malloc(vertices * sizeof(int));
  graph->adjLists = malloc(vertices * sizeof(struct Node*));

  int i;
  for (i = 0; i < vertices; i++) {
    graph->visited[i] = 0;
    graph->adjLists[i] = NULL;
  }

  return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
  struct Node* newNode = createNode(dest);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;

  newNode = createNode(src);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
}

void DFS(struct Graph* graph, int vertex) {
  graph->visited[vertex] = 1;
  printf("%d ", vertex);

  struct Node* adjList = graph->adjLists[vertex];
  while (adjList != NULL) {
    int connectedVertex = adjList->vertex;
    if (graph->visited[connectedVertex] == 0) {
      DFS(graph, connectedVertex);
    }
    adjList = adjList->next;
  }
}

int main() {
  struct Graph* graph = createGraph(4);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 2, 3);

  printf("Depth First Traversal starting from vertex 0: ");
  DFS(graph, 0);

  return 0;
}
