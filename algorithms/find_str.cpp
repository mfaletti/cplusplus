#include <cstdio>
#include <string>

int find_str(std::string text, std::string pattern) {
  int i, j, t, p;

  t = text.length();
  p = pattern.length();

  for (i = 0; i <= t - p; i++) {
    j = 0;

    while ((j < p) && text[i+j] == pattern[j]) {
      j++;
    }

    if (j == p) {
      return i;
    }
  }

  return -1;
}

int main() {

  std::string str = "testickles";
  std::string pattern = "tickles";

  printf("%d: ", find_str(str, pattern));

  return 0;
}