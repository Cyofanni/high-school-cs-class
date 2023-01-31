#include <iostream>
using namespace std;

int main() {
  int sum_mult_5 = 0;

  for (int mult_5 = 10; mult_5 <= 100; mult_5 += 5) {
    sum_mult_5 = sum_mult_5 + mult_5;
  }
  cout << "sum is: " << sum_mult_5 << endl;
}
