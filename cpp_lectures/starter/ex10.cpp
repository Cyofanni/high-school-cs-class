#include <iostream>
#include <climits>
using namespace std;

int main() {
  int num;
  cout << "enter an integer: ";
  cin >> num;
  char c1, c2, c3;
  cout << "enter 3 charaters: ";
  cin >> c1 >> c2 >> c3;

  for (int c = 1; c <= num; c++) {
    cout << c1 << '\t' << c2 << '\t' << c3 << '\n';
  }
}
