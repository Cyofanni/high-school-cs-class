#include <stdio.h>

int main() {
  int decimal_number;
  printf("enter an integer: ");
  scanf("%d", &decimal_number);
  do {
    int remainder = decimal_number % 8;
    printf("%d", remainder);
    decimal_number /= 8;
  } while (decimal_number != 0);

  putchar('\n');
}
