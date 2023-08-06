#include <stdio.h>

void merge(int array[], int left, int mid, int right) {
  int i, j, k;
  int n1 = mid - left + 1;
  int n2 = right - mid;
  int leftArray[n1], rightArray[n2];
  for (i = 0; i < n1; i++) {
    leftArray[i] = array[left + i];
  }
  for (j = 0; j < n2; j++) {
    rightArray[j] = array[mid + 1 + j];
  }
  i = 0;
  j = 0;
  k = left;
  while (i < n1 && j < n2) {
    if (leftArray[i] <= rightArray[j]) {
      array[k] = leftArray[i];
      i++;
    } else {
      array[k] = rightArray[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    array[k] = leftArray[i];
    i++;
    k++;
  }
  while (j < n2) {
    array[k] = rightArray[j];
    j++;
    k++;
  }
}

void mergeSort(int array[], int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    mergeSort(array, left, mid);
    mergeSort(array, mid + 1, right);
    merge(array, left, mid, right);
  }
}

void printArray(int array[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

int main() {
  int array[] = { 12, 11, 13, 5, 6, 7 };
  int n = sizeof(array) / sizeof(array[0]);
  printf("Original array: ");
  printArray(array, n);
  mergeSort(array, 0, n - 1);
  printf("Sorted array: ");
  printArray(array, n);
  return 0;
}

