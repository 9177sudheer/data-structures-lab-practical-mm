#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *head = NULL;

void insertAtBeginning(int data) {
  struct node newNode = (struct node) malloc(sizeof(struct node));
  newNode->data = data;
  newNode->next = head;
  head = newNode;
  printf("Element inserted at the beginning\n");
}

void insertAtEnd(int data) {
  struct node newNode = (struct node) malloc(sizeof(struct node));
  newNode->data = data;
  newNode->next = NULL;
  if (head == NULL) {
    head = newNode;
  } else {
    struct node *current = head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = newNode;
  }
  printf("Element inserted at the end\n");
}

void delete(int data) {
  if (head == NULL) {
    printf("List is empty\n");
  } else {
    struct node *current = head, *prev = NULL;
    while (current != NULL && current->data != data) {
      prev = current;
      current = current->next;
    }
    if (current == NULL) {
      printf("Element not found\n");
    } else if (prev == NULL) {
      head = current->next;
      free(current);
      printf("Element deleted\n");
    } else {
      prev->next = current->next;
      free(current);
      printf("Element deleted\n");
    }
  }
}

void display() {
  if (head == NULL) {
    printf("List is empty\n");
  } else {
    struct node *current = head;
    printf("List: ");
    while (current != NULL) {
      printf("%d ", current->data);
      current = current->next;
    }
    printf("\n");
  }
}

int main() {
  int choice, data;
  while (1) {
    printf("Choose an operation to perform:\n");
    printf("1. Insert at the beginning\n");
    printf("2. Insert at the end\n");
    printf("3. Delete\n");
    printf("4. Display\n");
    printf("5. Exit\n");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        printf("Enter the element to insert: ");
        scanf("%d", &data);
        insertAtBeginning(data);
        break;
      case 2:
        printf("Enter the element to insert: ");
        scanf("%d", &data);
        insertAtEnd(data);
        break;
      case 3:
        printf("Enter the element to delete: ");
        scanf("%d", &data);
        delete(data);
        break;
      case 4:
        display();
        break;
      case 5:
        exit(0);
      default:
        printf("Invalid choice\n");
    }
  }
  return 0;
}

