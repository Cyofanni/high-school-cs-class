#include <stdio.h>

int main() {
  int decimal_number;
  printf("enter an integer: ");
  scanf("%d", &decimal_number);
  do {
    printf("%d", decimal_number % 2);
    decimal_number /= 2;
  } while (decimal_number != 0);
  putchar('\n');
}
