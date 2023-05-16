#include <stdio.h>
#include <float.h>
#include <math.h>

typedef union ieee754 {
  unsigned int i;
  float f;
} IEEE_754;

int main() {
  //what happens?
  /*
  float f = 0.1;
  for (; f != 1;) {
    f += 0.1;
  }
  printf("%f\n", f);
  */

  //what happens?
  /*
  printf("%d\n", 0.2 - 0.1 == 0.1);
  printf("%d\n", 0.3 - 0.2 == 0.1);
  if (0.2 - 0.1 == 0.3 - 0.2) {
    printf("equality\n");
  }
  else {
    printf("inequality\n");
  }
  */

  //what happens?
  /*
  float v = FLT_MAX;
  printf("%f\n", v);
  printf("%f\n", v * 2);
  */

  //what happens?
  /*
  printf("%d\n", 0.1e-39f == 0.0f);
  printf("%d\n", 0.1e-40f == 0.0f);
  printf("%d\n", 0.1e-45f == 0.0f);
  */

  //what happens?
  /*
  IEEE_754 va;
  va.i = 0x7fffffff;
  printf("%f\n", va.f);
  va.i = 0x7f800000;
  printf("%f\n", va.f);
  */

  //what happens?
  /*
  printf("%d\n", sqrt(3) * sqrt(3) == 3.0);
  printf("%d\n", sqrt(5) * sqrt(5) == 5.0);
  */

  for (unsigned int exp = 1; exp <= 32; exp++) {
    long double n1 = pow(2, exp);
    long double n2 = pow(sqrt(2), exp * 2);
    printf("exp:%3u; ", exp);
    printf("error: %Le\n", n1 - n2);
  }
}
