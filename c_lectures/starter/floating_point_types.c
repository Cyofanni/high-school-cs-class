#include <stdio.h>
#include <float.h>

int main() {
  float a = 3.14;
  float b = 0.1234567e1;
  printf("%f\t%7.6f\n", a, b);

  printf("float min: %f\t float max:%f\n",
	  FLT_MIN, FLT_MAX);
  printf("double min: %lf\t double max:%lf\n",
	  DBL_MIN, DBL_MAX);
}
