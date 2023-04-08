#include <stdio.h>

int main() {
  unsigned short a = 4, b = 6;
  printf("a & b: %hu\n", a & b);
  printf("a | b: %hu\n", a | b);
  printf("a ^ b: %hu\n", a ^ b);
  printf("~a: %hu\n", ~a);
}
