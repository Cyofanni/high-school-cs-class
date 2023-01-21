/*
  The program reads 2 integers from stdin.
  If they're equal, their sum is stored in another variable.
  Otherwise, their difference is stored in another variable, different
  from the one used to store the sum.
*/

#include <stdio.h>

int main() {
  int var1, var2;
  int sum, int diff;

  printf("%s", "enter the first integer number: ");
  scanf("%d", &var1);
  printf("%s", "enter the second integer number: ");
  scanf("%d", &var2);

  if (var1 == var2) {
    sum = var1 + var2;
  }
  else {
    diff = var1 - var2;
  }

  return 0;
}
