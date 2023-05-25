#include <iostream>
#include <climits>

using namespace std;

int main() {
  int arr1[10] = {1, 3, 5, 7, 8, 11, 13, 15, 17, 19};
  int arr2[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

  for (int i = 0; i < 10; i++) {
    bool found = false;
    for (int j = 0; j < 10 && found == false; j++) {
      if (arr1[i] == arr2[j]) {
	found = true;
      }
    }
    if (found == false) {
      cout << arr1[i] << ' ';
    }
  }
  cout << endl;
}
