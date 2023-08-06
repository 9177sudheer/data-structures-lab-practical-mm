#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int element) {
  if (top == MAX_SIZE - 1) {
    printf("Stack Overflow\n");
  } else {
    stack[++top] = element;
    printf("Element %d pushed to the stack\n", element);
  }
}

void pop() {
  if (top == -1) {
    printf("Stack Underflow\n");
  } else {
    printf("Element %d popped from the stack\n", stack[top--]);
  }
}

void peek() {
  if (top == -1) {
    printf("Stack is empty\n");
  } else {
    printf("Top element of the stack is %d\n", stack[top]);
  }
}

int main() {
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
        push(element);
        break;
      case 2:
        pop();
        break;
      case 3:
        peek();
        break;
      case 4:
        exit(0);
      default:
        printf("Invalid choice\n");
    }
  }
  return 0;
}

