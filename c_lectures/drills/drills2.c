/*
  compute e^x iteratively as:
     sum_(n_0-inf) x^n / n! 
*/

#include <stdio.h>
#include <math.h>

long double e_to_the_x(int x, int n_iters) {
  long double result = 0;
  long double denominator = 1;
  
  for (int n = 0; n <= n_iters; n++){
    result = result + pow(x, n) / denominator;
    denominator = denominator * (n + 1);
  }

  return result;
}

int main(int argc, char *argv[]) {
  printf("%13.12Lf\n", e_to_the_x(1, 5));
}
