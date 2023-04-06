#include <stdio.h>

int main() {
  /*what happens?
  do {
    printf("john von neumann\n");
  } while (1 == 1);
  */

  /*what happens?
  while (0 == 0 && 5 / 0) {}
  */

  /*what happens?
  while (1 && 1 / 0) {}
  */

  /*what happens?
  while (0 || 3 / 0) {}
  */

  /*what happens?
  while (1 || 3 / 0) {}
  */

  /*what does it print?
  int a = 3.14;
  printf("%d\n", a);
  */

  /*what happens?
  int a = 2147483647;
  int b = a + 1;
  printf("%d\n", b);
  */
}
