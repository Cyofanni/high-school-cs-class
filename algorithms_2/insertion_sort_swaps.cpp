#include <iostream>
using namespace std;

int main() {
  const int size = 16;
  int ar[size] = {1, 3, -12, 7, -10, 1500, 160, 172, -20, 30, 35, 360, 37, 450, 500, -80};

  for (int i = 1; i < size; i++) {
    for (int j = i; j >= 1 && ar[j] < ar[j - 1]; j--) {
      int t = ar[j];
      ar[j] = ar[j - 1];
      ar[j - 1] = t;
    }
  }

  for (int i = 0; i < size; i++) {
    cout << ar[i] << ' ';
  }
  cout << endl;
}
