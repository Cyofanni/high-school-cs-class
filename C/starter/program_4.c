/*
  This program reads two integers from standard input
  and stores them in two variables.
  If the first number is greater or equal to the second one,
  the program prints the string "var_1 gte var_2\n" on standard output.
  Otherwise, it prints "var_1 lt var_2\n".
  The whole program is written in the main function.
  The program prints the value of each variable after each declaration
  or initialization.
*/

#include <stdio.h>

int main() {
  int var1, var2;
  printf("value or var1 is %d\nvalue of var2 is %d\n", var1, var2);

  printf("%s", "enter the first integer number: ");
  scanf("%d", &var1);
  printf("%s", "enter the second integer number: ");
  scanf("%d", &var2);
  printf("value or var1 is %d\nvalue of var2 is %d\n", var1, var2);

  if (var1 >= var2) {
    printf("%s\n", "var1 gte var2");
  }
  else {
    printf("%s\n", "var1 lt var2");
  }

  return 0;
}
