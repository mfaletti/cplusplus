#include <iostream>
#include <algorithm>

// return smallest difference between a pair of numbers.
// time complexity: nlog(n) 

int min_diff(int list[], int k) {
  int min;

  if (k < 2) 
    return -1;

  // sorting the list first lets us do this is nlogn time instead of n^2 
  std::sort(list, list+k);

  min = list[1] - list[0];

  for(int i=1; i<k-1; i++){
    if (list[i] - list[i-1] < min) {
      min = list[i] - list[i-1];
    }
  }

  return min;
}

int main() {
  int arr[] = {-1};
  int len = sizeof(arr)/sizeof(arr[0]);

  std::cout<<min_diff(arr, len);
  return 0;
}