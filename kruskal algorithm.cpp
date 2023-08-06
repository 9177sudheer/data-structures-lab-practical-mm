#include <stdio.h>
#include <stdlib.h>

#define V 5

struct Edge {
  int src, dest, weight;
};

struct Graph {
  int numVertices, numEdges;
  struct Edge* edges;
};

struct Graph* createGraph(int vertices, int edges) {
  struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
  graph->numVertices = vertices;
  graph->numEdges = edges;
  graph->edges = (struct Edge*)malloc(edges * sizeof(struct Edge));
  return graph;
}

int find(int parent[], int i) {
  if (parent[i] == -1)
    return i;
  return find(parent, parent[i]);
}

void Union(int parent[], int x, int y) {
  int xset = find(parent, x);
  int yset = find(parent, y);
  parent[xset] = yset;
}

int myComp(const void* a, const void* b) {
  struct Edge* a1 = (struct Edge*)a;
  struct Edge* b1 = (struct Edge*)b;
  return a1->weight > b1->weight;
}

void KruskalMST(struct Graph* graph) {
  int parent[V];
  for (int i = 0; i < V; i++)
    parent[i] = -1;

  int i = 0, e = 0;
  struct Edge result[V];

  qsort(graph->edges, graph->numEdges, sizeof(graph->edges[0]), myComp);

  while (e < V - 1 && i < graph->numEdges) {
    struct Edge next_edge = graph->edges[i++];

    int x = find(parent, next_edge.src);
    int y = find(parent, next_edge.dest);

    if (x != y) {
      result[e++] = next_edge;
      Union(parent, x, y);
    }
  }

  printf("Edge \tWeight\n");
  for (i = 0; i < e; i++)
    printf("%d - %d \t%d\n", result[i].src, result[i].dest, result[i].weight);
}

int main() {
  int vertices = V;
  int edges = 7;
  struct Graph* graph = createGraph(vertices, edges);

  graph->edges[0].src = 0;
  graph->edges[0].dest = 1;
  graph->edges[0].weight = 2;

  graph->edges[1].src = 0;
  graph->edges[1].dest = 3;
  graph->edges[1].weight = 6;

  graph->edges[2].src = 1;
  graph->edges[2].dest = 2;
  graph->edges[2].weight = 3;

  graph->edges[3].src = 1;
  graph->edges[3].dest = 3;
  graph->edges[3].weight = 8;

  graph->edges[4].src = 1;
  graph->edges[4].dest = 4;
  graph->edges[4].weight = 5;

  graph->edges[5].src = 2;
  graph->edges[5].dest = 4;
  graph->edges[5].weight = 1;

  graph->edges[6].src = 3;
  graph->edges[6].dest = 4;
  graph->edges[6].weight = 9;

  KruskalMST(graph);

  return 0;
}
