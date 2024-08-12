#include <iostream>
#include <string>
using namespace std;

int lcs(string s1, string s2, int i, int j) {
  if (i == -1 || j == -1) {
    return 0;
  }
  if (s1.at(i) == s2.at(j)) {
    return 1 + lcs(s1, s2, i - 1, j - 1);
  }
  int r1 = lcs(s1, s2, i - 1, j);
  int r2 = lcs(s1, s2, i, j - 1);
  int r3 = lcs(s1, s2, i - 1, j - 1);
  int max_r = r1;
  if (r2 > max_r) {
    max_r = r2;
  }
  if (r3 > max_r) {
    max_r = r3;
  }
  return max_r;
}

int main(int argc, char* argv[]) {
  string s1 = argv[1], s2 = argv[2];
  cout << lcs(s1, s2, s1.size() - 1, s2.size() - 1) << endl;
}
