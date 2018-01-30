#include <cstdio>

void printArray(int a[], int len) {
  int i;
  for (i = 0; i < len; i++) {
    printf("%d", a[i]);
  }

  printf("\n");
}

void insertion_sort(int a[], int length) {
  int temp, min, i, j, counter = 0;
  bool swap;

  for (i = 1; i < length; i++) {
    j = i;

    while( j > 0 && a[j] < a[j-1]) {
      ++counter;
      min = a[j];
      a[j] = a[j-1];
      a[j-1] = min;

      j--;
    }

    printf("Iteration %d#: ",(i));
    printArray(a, length);
  }

  printf("total number of passthrough %d: ", counter);
}

int main() {

  int a[] = {6,5,4,3,2,1};
  int len = sizeof(a)/sizeof(int);

  insertion_sort(a, len);
  printArray(a,len);

  return 0;
}