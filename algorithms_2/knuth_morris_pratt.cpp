#include <iostream>
#include <cstring>
using namespace std;

int max(int a, int b) {
  return a >= b ? a : b;
}

void pref_table(char* pattern, int* table, int size) {
  for (int i = 1; i < size; i++) {
    int len = 0;
    for (int j = 0; j <= i && pattern[j] == pattern[i + j]; j++) {
      table[i + j] = max(table[i + j], j + 1);
    }
  }
}

int kmp(char* text, char* pattern, int t_size, int p_size) {
  int table[p_size] = {0};
  pref_table(pattern, table, p_size);

  int i = 0;
  while (i <= t_size - p_size) {
    int part_match = 0;
    for (int j = 0; j < p_size && text[i + j] == pattern[j]; j++) {
      part_match++;
    }
    if (part_match == p_size) {
      return i;
    }
    else {
      if (part_match == 0) {
        i++;
      }
      else {
        i = i + part_match - table[part_match - 1];
      }
    }
  }

  return -1;
}

int main() {
  char text[] = "bcaabcabqabcababaqabcabababqqqqqqzz";
  char pattern[] = "abcababab";

  cout << kmp(text, pattern, strlen(text), strlen(pattern)) << endl;
}
