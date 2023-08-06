#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

int hash[TABLE_SIZE];

int hasht(int key) {
  return key % TABLE_SIZE;
}

int rehashl(int key) {
  return (key + 1) % TABLE_SIZE;
}

void insert(int key) {
  int index = hasht(key);
  while (hash[index] != -1) {
    index = rehashl(index);
  }
  hash[index] = key;
}

void search(int key) {
  int index = hasht(key);
  while (hash[index] != key && hash[index] != -1) {
    index = rehashl(index);
  }
  if (hash[index] == key) {
    printf("Element %d found at index %d\n", key, index);
  } else {
    printf("Element not found\n");
  }
}

void display() {
  printf("Hash Table:\n");
  for (int i = 0; i < TABLE_SIZE; i++) {
    printf("%d ", hash[i]);
  }
  printf("\n");
}

int main() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    hash[i] = -1;
  }
  int choice, key;
  while (1) {
    printf("Choose an operation to perform:\n");
    printf("1. Insert\n");
    printf("2. Search\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        printf("Enter the element to insert: ");
        scanf("%d", &key);
        insert(key);
        break;
      case 2:
        printf("Enter the element to search: ");
        scanf("%d", &key);
        search(key);
        break;
      case 3:
        display();
        break;
      case 4:
        exit(0);
      default:
        printf("Invalid choice\n");
    }
  }
  return 0;
}
