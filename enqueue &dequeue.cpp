#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct queue {
  int data[MAX_SIZE];
  int front;
  int rear;
};

void enqueue(struct queue *q, int element) {
  if (q->rear == MAX_SIZE - 1) {
    printf("Queue Overflow\n");
  } else {
    q->data[++q->rear] = element;
    printf("Element %d enqueued\n", element);
  }
}

void dequeue(struct queue *q) {
  if (q->front > q->rear) {
    printf("Queue Underflow\n");
  } else {
    printf("Element %d dequeued\n", q->data[q->front++]);
  }
}

void display(struct queue *q) {
  if (q->front > q->rear) {
    printf("Queue is empty\n");
  } else {
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
      printf("%d ", q->data[i]);
    }
    printf("\n");
  }
}

int main() {
  struct queue q;
  q.front = 0;
  q.rear = -1;
  int choice, element;
  while (1) {
    printf("Choose an operation to perform:\n");
    printf("1. ENQUEUE\n");
    printf("2. DEQUEUE\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        printf("Enter the element to enqueue: ");
        scanf("%d", &element);
        enqueue(&q, element);
        break;
      case 2:
        dequeue(&q);
        break;
      case 3:
        display(&q);
        break;
      case 4:
        exit(0);
      default:
        printf("Invalid choice\n");
    }
  }
  return 0;
}

