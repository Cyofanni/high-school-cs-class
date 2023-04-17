#include <stdio.h>

int main() {
  unsigned short n;
  printf("enter an integer: ");
  scanf("%hu", &n);

  do {
    printf("%hu\t%hu\n", n % 10, 9 - n % 10);
    n /= 10;
  } while (n != 0);
}
