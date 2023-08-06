#include <stdio.h>

int main() {
  int n, i;
  printf("Enter the number of elements in the array\n");
  scanf("%d", &n);
  int a[n];
  printf("Enter the elements of the array\n");
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  printf("Odd numbers in the array are: ");
  for (i = 0; i < n; i++) {
    if (a[i] % 2 != 0) {
      printf("%d ", a[i]);
    }
  }
  printf("\nEven numbers in the array are: ");
  for (i = 0; i < n; i++) {
    if (a[i] % 2 == 0) {
      printf("%d ", a[i]);
    }
  }
  return 0;
}
