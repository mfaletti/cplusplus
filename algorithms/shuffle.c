#include <cstdio>
#include<stdlib.h>

void shuffle(int *array, size_t n){
  if (n > 1) {
    size_t i;
    for (int i=0; i < n-1; i++) {
      size_t j = i + rand() / (RAND_MAX / (n-i) + 1);printf("%zd",j);
      int t = array[j];
      array[j] = array[i];
      array[i] = t;
    }
  }
}

void printArray(int a[], int len) {
  int i;

  printf("\n");
  for (i = 0; i < len; i++) {
    printf("%d", a[i]);
  }
}

int main() {
  int list[] = {1,2,3,4,5,6,7,8,9,10};
  size_t n = sizeof(list)/sizeof(list[0]);
  shuffle(list, n);

  printArray(list, n);
  return 0;
}