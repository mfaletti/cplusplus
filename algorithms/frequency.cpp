#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

// returns the value from the list with the highest frequency
// time complexity: O(nlog n)
int max_occurences(int list[], int k) {
  int counter = 1;
  int max = 1;
  std::map<int, int>count_map;

  // edge cases
  if (k == 0) 
    return -1;

  if (k<2) 
    return list[0];

  sort(list, list+k);

  for (int i=1; i<=k-1; i++) {
    if (list[i] == list[i-1]){
      ++counter;
      if (counter > max) {
        max = counter;
        count_map[max] = list[i];
      }
    } else {
      counter=1; //reset counter
    }
  }

  return count_map[max];
}

int main() {
  int list[] = {};
  int len = sizeof(list)/sizeof(list[0]);

  cout<<max_occurences(list, len);
  return 0;
}

