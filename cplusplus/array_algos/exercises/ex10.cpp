#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
  double v[15];

  for (int i = 0; i < 15; i++) {
    v[i] = i;
  }

  for (int i = 1; i <= 13; i++) {
    double sum_triple_div_3 = (v[i - 1] + v[i] + v[i + 1]) / 3;
    cout << sum_triple_div_3 << endl;
  }

  cout << endl;
}
