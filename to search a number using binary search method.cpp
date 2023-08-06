#include <stdio.h>

int binarySearch(int arr[], int size, int key) {
  int low = 0, high = size - 1, mid;
  while (low <= high) {
    mid = (low + high) / 2;
    if (arr[mid] == key) {
      return mid;
    } else if (arr[mid] < key) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}

int main() {
  int size, i, key, index;
  printf("Enter the size of the array: ");
  scanf("%d", &size);
  int arr[size];
  printf("Enter the elements of the array in ascending order: ");
  for (i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }
  printf("Enter the number to search: ");
  scanf("%d", &key);
  index = binarySearch(arr, size, key);
  if (index != -1) {
    printf("Number found at index %d\n", index);
  } else {
    printf("Number not found\n");
  }
  return 0;
}
