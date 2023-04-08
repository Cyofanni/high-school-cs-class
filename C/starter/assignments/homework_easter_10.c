#include <stdio.h>
#include <math.h>

int main() {
  unsigned long n;
  printf("enter an integer to factorize it: ");
  scanf("%lu", &n);

  while (n != 1) {
    int trial_div = 2;
    int found_div = 0;
    while (trial_div <= n && !found_div) {
      if (n % trial_div == 0) {
	n = n / trial_div;
	printf("%d\n", trial_div);
	found_div = 1;
      }
      trial_div++;
    }
  }
}
