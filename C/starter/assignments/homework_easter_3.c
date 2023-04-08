#include <stdio.h>
#include <math.h>

int main() {
  unsigned long n;
  printf("enter an integer to test its primality: ");
  scanf("%lu", &n);
  int sqrt_n = (int)floor(sqrt(n));

  int is_prime = 1;  //did not find divisors so far, assume it is prime
  if ((n % 2 == 0 && n != 2) || n == 1) {
    is_prime = 0;
  }
  else if (n == 2) {
    is_prime = 1;
  }
  else {
    int trial_div = 3;
    while (trial_div <= sqrt_n && is_prime) {
      if (n % trial_div == 0 && n != trial_div && n != 2) {
	is_prime = 0;
      }
      trial_div += 2;
    }
  }

  if (is_prime) {
    printf("%lu is prime\n", n);
  }
  else {
    printf("%lu is composite\n", n);
  }
}
