#include <stdio.h>

int linearSearch(int arr[], int size, int key) {
  int i;
  for (i = 0; i < size; i++) {
    if (arr[i] == key) {
      return i;
    }
  }
  return -1;
}

int main() {
  int size, i, key, index;
  printf("Enter the size of the array: ");
  scanf("%d", &size);
  int arr[size];
  printf("Enter the elements of the array: ");
  for (i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }
  printf("Enter the number to search: ");
  scanf("%d", &key);
  index = linearSearch(arr, size, key);
  if (index != -1) {
    printf("Number found at index %d\n", index);
  } else {
    printf("Number not found\n");
  }
  return 0;
}

