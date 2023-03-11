#include <stdio.h>

int main() {
  int i;
  for (i = 0; i < 10; i++) {
    printf("i's value is: %d\n", i);
  }
  printf("i's value after loop is: %d\n", i);

  /*
    equivalent loop with while construct
    int i = 0;
    while (i < 10) {
      printf("i's value is: %d\n", i);
      i++;
    }
  */
}
