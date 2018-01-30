#include <iostream>
using namespace std;

// return true if there are no duplicates in the list, false otherwise.
// time complexity: O(nlog n) 
int isUnique(int list[], int k) {

  if (k < 2) {
    return -1;
  }

  sort(list, list+k);

  for (int i=0;i<k-1;i++) {
    if (list[i] == list[i+1])
      return false;
  }
  return true;
}

int main() {
  int list[] = {2,2,3,4};
  int len = sizeof(list)/sizeof(list[0]);

  cout<<isUnique(list, len);

  return 0;
}