#include <stdio.h>

int main() {
  int size, i, pos, element, choice;
  printf("Enter the size of the array: ");
  scanf("%d", &size);
  int arr[size];
  printf("Enter the elements of the array: ");
  for (i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }
  printf("Choose an operation to perform:\n");
  printf("1. Insert an element\n");
  printf("2. Delete an element\n");
  printf("3. Display the array\n");
  scanf("%d", &choice);
  switch (choice) {
    case 1:
      printf("Enter the element to insert: ");
      scanf("%d", &element);
      printf("Enter the position to insert: ");
      scanf("%d", &pos);
      if (pos < 0 || pos > size) {
        printf("Invalid position\n");
      } else {
        for (i = size - 1; i >= pos; i--) {
          arr[i + 1] = arr[i];
        }
        arr[pos] = element;
        size++;
        printf("Element inserted successfully\n");
      }
      break;
    case 2:
      printf("Enter the element to delete: ");
      scanf("%d", &element);
      for (i = 0; i < size; i++) {
        if (arr[i] == element) {
          for (pos = i; pos < size - 1; pos++) {
            arr[pos] = arr[pos + 1];
          }
          size--;
          printf("Element deleted successfully\n");
          break;
        }
      }
      if (i == size) {
        printf("Element not found\n");
      }
      break;
    case 3:
      printf("The array is: ");
      for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
      }
      break;
    default:
      printf("Invalid choice\n");
  }
  return 0;
}
