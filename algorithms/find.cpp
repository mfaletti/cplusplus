#include <string>
#include <iostream>

// find a substring str1 in str2. 
// returns the index of the first element in the range if found.
// returns m if no match. 
// runtime O( m)
int find(std::string& str1, std::string& str2, int n, int m) {

  // base case. empty string or str1 has been found, return the current position of the pointer m in the range 
  if ( n== 0) return m; 

  // str2 has been completely traversed at this point or we are out of search range (when n > m).
  if (n > m || m == 0) return str2.length();

  if (str1[n-1] == str2[m-1])
    return find(str1, str2, n-1, m-1);
  else if (str1[str1.length()-1] == str2[m-1]) {
    return find(str1, str2, str1.length(), m);
  } 
  else return find(str1, str2, str1.length(), m-1);
}

int main(){
  std::string str1 = "light";
  std::string str2 = "ightmy very lightightenighted mother";

  int n = str1.length();
  int m = str2.length();

  std::cout << find(str1, str2, n, m);
  return 0;
}
