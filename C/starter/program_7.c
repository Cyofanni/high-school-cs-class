/*
  The program reads 3 integers from stdin and stores them in 3 variables
  a, b, and c.
  If a and b are equal to c, it prints "a and b have the same value, c".
  Otherwise, it prints "either a or b has a value different from c".
*/

#include <stdio.h>

int main() {
  int a, b, c;
  printf("enter an integer: ");
  scanf("%d", &a);

  printf("enter an integer: ");
  scanf("%d", &b);

  printf("enter an integer: ");
  scanf("%d", &c);

  if (a == c && b == c) {
    printf("%s\n", "a and b have the same value, c");
  }
  else {
    printf("%s\n", "either a or b has a value different from c");
  }

  puts("exiting program...");

  return 0;
}
