#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  string s1("wolfgang ");
  string s2("amadeus ");
  string s3("mozart\n");

  string s4(s1 + s2 + s3);
  cout << s4;
  reverse(s4.begin(), s4.end());
  cout << s4 << endl;
}
