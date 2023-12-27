#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  //example 0
  string s1("wolfgang ");
  string s2("amadeus ");
  string s3("mozart\n");

  string s4(s1 + s2 + s3);
  cout << s4;
  reverse(s4.begin(), s4.end());
  cout << s4 << endl;

  //example 1
  cout << endl;
  string s5 = "johann sebastian bach";
  string s6 = s5.substr(2, 5);
  cout << s6 << endl;

  //example 2
  cout << endl;
  string s7 = "ludwig van beethoven";
  size_t pos = s7.find("dwi");
  if (pos != string::npos) {
    cout << pos << endl;
  }
}
