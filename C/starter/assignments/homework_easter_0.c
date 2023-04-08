#include <stdio.h>

int main() {
  unsigned long n;
  printf("enter an integer: ");
  scanf("%lu", &n);
  while (n != 1) {
    if (n % 2 == 0) {
      n /= 2;
    }
    else {
      n = 3 * n + 1;
    }
    printf("%lu\n", n);
  }
}
