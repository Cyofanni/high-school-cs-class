#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
  int vect[10];

  for (int i = 0; i < 10; i++) {
    cin >> vect[i];
  }

  for (int i = 0; i < 10; i++) {
      bool is_duplicate = false;
      for (int j = 0; j < i && is_duplicate == false; j++) {
	if (vect[j] == vect[i]) {
	  is_duplicate = true;
	}
      }
      if (is_duplicate == true) {
	cout << vect[i] << " has duplicate" << endl;
      }
  }

  cout << endl;
}
