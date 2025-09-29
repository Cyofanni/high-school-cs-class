#include <iostream>
using namespace std;

int main() {
  double P[] = {3, 2, 6, 1, 12, 0, 0, 0, 0};    //3 + 2x + 6x^2 + 1x^3 + 12x^4
  double Q[] = {7, 6, 1, -6, 3, 0, 0, 0, 0};    //7 + 6x + 1x^2 - 6x^3 + 3x^4

  const int conv_size = 9;
  double convolution[conv_size] = {};

  for (int i = 0; i < conv_size; i++) {
    double sum = 0;
    for (int j = 0; j <= i; j++) {
      sum += P[j] * Q[i - j];
    }
    convolution[i] = sum;
  }

  for (int i = 0; i < conv_size; i++) {
    cout << convolution[i] << ' ';
  }
  cout << endl;
}
