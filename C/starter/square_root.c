#include <stdio.h>
#include <math.h>

int main() {
  double n;
  printf("enter an integer: ");
  scanf("%lf", &n);

  double approx = 0;
  double step = 1;

  for (int i = 0; i < 8; i++) {
    while (approx * approx <= n) {
      approx = approx + step;
    }
    approx = approx - step;
    step = step / 10;
  }

  printf("my approximated square root of %lf is %lf\n", n, approx);
  printf("C library-approximated square root of %lf is %lf\n", n, sqrt(n));
}
