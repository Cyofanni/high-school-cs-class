#include <stdio.h>

int main() {
  printf("sizeof char is: %lu bytes\n", sizeof(char));
  printf("sizeof short is: %lu bytes\n", sizeof(short));
  printf("sizeof int is: %lu bytes\n", sizeof(int));
  printf("sizeof unsigned int is: %lu bytes\n", sizeof(unsigned int));
  printf("sizeof long: %lu bytes\n", sizeof(long));
  printf("sizeof unsigned long is: %lu bytes\n", sizeof(unsigned long));
  printf("sizeof float is: %lu bytes\n", sizeof(float));
  printf("sizeof double is: %lu bytes\n", sizeof(double));
  printf("sizeof long double is: %lu bytes\n", sizeof(long double));
}
