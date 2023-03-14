#include <stdio.h>

int main() {
  /*what happens?
  while (0) {
    int ds = 0;
    int dd = 1;
    int q = dd / ds;
  }
  */

  /*
  do {
    int ds = 0;
    int dd = 1;
    int q = dd / ds;
  } while (1 != 1 && 1);
  */

  /*what happens?
  if (0 && 0 / 0) {
    puts("dennis ritchie");
  }
  else {
    puts("brian kernighan");
  }
  */

  /*what happens?
  if (0 || 4 / 0) {
    puts("dennis ritchie");
  }
  else {
    puts("ken thompson");
  }
  */

  /*what happens?
  long i = 9223372036854775800;
  do {
    i += i;
    printf("%ld\n", i);
  } while (0);
  */

  /*what happens?
  double dividend = 5.0;
  double divisor = 0.0000000000000000000001;
  printf("%lf\n", dividend / divisor);
  */

  /*what happens?
  double f = 0.0;
  printf("%f\n", f);

  while (f != 1) {
    printf("%f\n", f);
    f = f + 1.0 / 9.0;
  }
  printf("%f\n", f);
  */
}
