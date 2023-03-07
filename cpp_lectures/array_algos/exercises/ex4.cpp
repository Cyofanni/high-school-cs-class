#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
  int vect[10];
  int i = 0;
  while (i < 10) {
    cin >> vect[i];
    i += 1;
  }

  cout << endl << endl;
  for (int i = 9; i >= 0; i--) {
    cout << vect[i] << ' ';
  }
  cout << endl;
}
