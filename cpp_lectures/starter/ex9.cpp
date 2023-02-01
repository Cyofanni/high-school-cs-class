#include <iostream>
#include <climits>
using namespace std;

int main() {
  double base;
  int exp;
  double result = 1;

  cout << "enter a real base: ";
  cin >> base;
  cout << "enter an integer exponent: ";
  cin >> exp;
  
  for (int c = 1; c <= abs(exp); c++) {
    result *= base;
  }

  if (exp < 0) {
    result = 1 / result;
  }
  
  cout << "the result is: " << result << endl;
}
