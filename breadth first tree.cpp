#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

struct Queue {
  int items[MAX_QUEUE_SIZE];
  int front;
  int rear;
};

struct Queue* createQueue() {
  struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
  queue->front = -1;
  queue->rear = -1;
  return queue;
}

int isEmpty(struct Queue* queue) {
  if (queue->rear == -1)
    return 1;
  else
    return 0;
}

void enqueue(struct Queue* queue, int value) {
  if (queue->rear == MAX_QUEUE_SIZE - 1)
    printf("Queue overflow\n");
  else {
    if (queue->front == -1)
      queue->front = 0;
    queue->rear++;
    queue->items[queue->rear] = value;
  }
}

int dequeue(struct Queue* queue) {
  int item;
  if (isEmpty(queue)) {
    printf("Queue underflow\n");
    item = -1;
  } else {
    item = queue->items[queue->front];
    queue->front++;
    if (queue->front > queue->rear) {
      queue->front = queue->rear = -1;
    }
  }
  return item;
}

void bfs(int adjacencyMatrix[][7], int startVertex, int visited[]) {
  struct Queue* queue = createQueue();

  visited[startVertex] = 1;
  enqueue(queue, startVertex);

  while (!isEmpty(queue)) {
    int currentVertex = dequeue(queue);
    printf("%d ", currentVertex);

    for (int i = 0; i < 7; i++) {
      if (adjacencyMatrix[currentVertex][i] == 1 && visited[i] == 0) {
        visited[i] = 1;
        enqueue(queue, i);
      }
    }
  }
}

int main() {
  int adjacencyMatrix[7][7] = {
    {0, 1, 1, 0, 0, 0, 0},
    {1, 0, 0, 1, 1, 0, 0},
    {1, 0, 0, 0, 1, 0, 0},
    {0, 1, 0, 0, 1, 0, 0},
    {0, 1, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0}
  };
  int visited[7] = {0, 0, 0, 0, 0, 0, 0};
  printf("BFS traversal starting from vertex 0: ");
  bfs(adjacencyMatrix, 0, visited);
  printf("\n");
  printf("BFS traversal starting from vertex 1: ");
  bfs(adjacencyMatrix, 1, visited);
  printf("\n");
  return 0;
}
