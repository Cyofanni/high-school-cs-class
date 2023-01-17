#include <stdio.h>

int main() {
  puts("enter a positive integer number:");
  int num;
  printf("value of unitialized variable 'num' before reading from stdin: "
               "%d\n", num);
  scanf("%d", &num);
  printf("value of variable 'num' after reading from stdin: %d\n", num);

  if (num < 0) {
    printf("entered a negative number... exiting program\n");
  }
  else {
    int num_squared = num * num;
    printf("the square of %d is %d\n", num, num_squared);
  }

  return 0;
}
