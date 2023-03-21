#include <stdio.h>

int main() {
  unsigned long int fib_pp = 0, fib_p = 1;
  unsigned long int fib_curr;
  long double phi_approx;

  printf("0-th fibonacci number is: %lu\n", fib_pp);
  printf("1-th fibonacci number is: %lu\n", fib_p);
  for (unsigned int i = 2; i <= 30; i++) {
    fib_curr = fib_pp + fib_p;
    printf("%u-th fibonacci number is: %lu\t", i, fib_curr);
    phi_approx = (long double) fib_curr / fib_p;
    printf("approximation of phi is: %16.15Lf\n", phi_approx);
    fib_pp = fib_p;
    fib_p = fib_curr;
  }
  putchar('\n');
}
