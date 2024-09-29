#include <iostream>
#include <cmath>
using namespace std;

int main() {
  double X[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  double freqs[10] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
  double tot = 0;
  for (int i = 0; i < 10; i++) {
    tot += freqs[i];
  }

  double x_freqs_tot = 0;
  for (int i = 0; i < 10; i++) {
    x_freqs_tot += X[i] * freqs[i];
  }
  double mean = x_freqs_tot / tot;

  double tot_sq_dev = 0;
  for (int i = 0; i < 10; i++) {
    tot_sq_dev += pow(X[i] - mean, 2) * freqs[i];
  }
  double var = tot_sq_dev / tot;

  cout << "mean is: " << mean << endl;
  cout << "variance is: " << var << endl;
}
