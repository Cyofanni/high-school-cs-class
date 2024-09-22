#include <iostream>
using namespace std;

int main() {
  unsigned int q, q_bar;
  unsigned int s, r;

  while (true) {
    cout << "S: ";
    cin >> s;
    cout << "R: ";
    cin >> r;

    if (s == 1 && r == 0) {
      q = 1;
      q_bar = 0;
    }
    else if (s == 0 && r == 1) {
      q = 0;
      q_bar = 1;
    }
    else if (s == 1 && r == 1) {
      cout << "X" << endl << endl;
      continue;
    }
    cout << "Q: " << q << endl;
    cout << "Q_bar: " << q_bar << endl << endl;
  }
}
