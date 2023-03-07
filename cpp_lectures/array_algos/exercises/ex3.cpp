#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
  int vect[10];
  int i = 0;
  while (i < 10) {
    cin >> vect[i];
    i+= 1;
  }

  cout << endl << endl;
  for (int i = 0; i < 10; i++) {
    bool is_duplicate = false;
    for (int j = 0; j < i && is_duplicate == false; j++) {
      if(vect[j] == vect[i]) {
	is_duplicate = true;
      }
    }
    if (is_duplicate == false) {
      cout << vect[i] << ' ';
    }
  }
  cout << endl;
}
