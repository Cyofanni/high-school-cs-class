#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
  int vect[10];

  for (int i = 0; i < 10; i++) {
    cin >> vect[i];
  }
  int key;
  cin >> key;
  bool found = false;
  int key_index = -1;

  for (int i = 0; i < 10 && found == false; i++) {
    if (key == vect[i]) {
      found = true;
      key_index = i;
    }
  }

  if (found == true) {
    cout << key << " found at index: " << key_index << endl;
  }
  else {
    cout << key << " not found" << endl;
  }

  cout << endl;
}
