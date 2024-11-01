#include <iostream>
using namespace std;

int main() {
  const int size = 16;
  int ar[size] = {1, 3, 5, 7, 15, 160, -17, 20, 29, 30, 31, -1, -2, 30, 50, 35};

  for (int i = size - 2; i >= 0; i--) {
    int item = ar[i];
    int j;
    for (j = i + 1; j <= size - 1 && item > ar[j]; j++) {
      ar[j - 1] = ar[j];
    }
    ar[j - 1] = item;
  }

  for (int i = 0; i < size; i++) {
    cout << ar[i] << ' ';
  }
  cout << endl;
}
