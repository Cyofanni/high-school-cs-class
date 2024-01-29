#include <iostream>
using namespace std;

int main() {
  const int size = 5;
  double poly[size] = {5, 4, 6.7, 1.3, -10.91};
  //horner's method
  double x0 = 8.57;
  double b = poly[size - 1];

  for (int i = size - 2; i >= 0; i--) {
    b = poly[i] + x0 * b;
  }

  cout << b << endl;
}
