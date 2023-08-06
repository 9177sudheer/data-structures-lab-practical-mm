#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct stack {
  int data[MAX_SIZE];
  int top;
};

void push(struct stack *s, int element) {
  if (s->top == MAX_SIZE - 1) {
    printf("Stack Overflow\n");
  } else {
    s->data[++s->top] = element;
    printf("Element %d pushed to the stack\n", element);
  }
}

void pop(struct stack *s) {
  if (s->top == -1) {
    printf("Stack Underflow\n");
  } else {
    printf("Element %d popped from the stack\n", s->data[s->top--]);
  }
}

void peek(struct stack *s) {
  if (s->top == -1) {
    printf("Stack is empty\n");
  } else {
    printf("Top element of the stack is %d\n", s->data[s->top]);
  }
}

int main() {
  struct stack s;
  s.top = -1;
  int choice, element;
  while (1) {
    printf("Choose an operation to perform:\n");
    printf("1. PUSH\n");
    printf("2. POP\n");
    printf("3. PEEK\n");
    printf("4. Exit\n");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        printf("Enter the element to push: ");
        scanf("%d", &element);
        push(&s, element);
        break;
      case 2:
        pop(&s);
        break;
      case 3:
        peek(&s);
        break;
      case 4:
        exit(0);
      default:
        printf("Invalid choice\n");
    }
  }
  return 0;
}
