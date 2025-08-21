#include <iostream>
using namespace std;

int main() {
  double P[] = {-8, 6 , 3, -4, 0, 0};    //-4x^3 + 3x^2 + 6x - 8
  double Q[] = {16, 10, 4, 0, 0, 0};     //4x^2 + 10x + 16

  const int conv_size = 6;
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
