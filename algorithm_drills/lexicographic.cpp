#include <iostream>
#include <cstring>
using namespace std;

int lex_ord(char* s1, char* s2, int sz_1,
            int sz_2) {
  if (!sz_1 && !sz_2) {
    return 0;
  }
  if (!sz_1 && sz_2) {
    return 1;
  }
  if (sz_1 && !sz_2) {
    return -1;
  }
  if (*s1 > *s2) {
    return -1;
  }
  if (*s1 < *s2) {
    return 1;
  }
  return lex_ord(s1 + 1, s2 + 1, sz_1 - 1, sz_2 - 1);
}

int main() {
  char st1[] = "dante";
  char st2[] = "petrarca";
  cout << lex_ord(st1, st2, strlen(st1), strlen(st2)) << endl;
}
