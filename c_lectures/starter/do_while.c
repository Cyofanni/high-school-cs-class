#include <stdio.h>

int main() {
  int i = 1;
  do {
    printf("i's value is: %d\n", i);
    i += 1;
  } while (i <= 10);

  printf("after the do-while loop, i's value is: %d\n\n", i);

  int j = 0;
  do {
    puts("alan turing"); //1 iteration (at least) is executed
  } while (j != 0);
}
