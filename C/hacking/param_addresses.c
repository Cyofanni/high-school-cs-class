#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void g(char c) {
  puts("HACKED");
  putchar(c);
  putchar('\n');
}

void f(int off2, int off3) {
  char str[8];
  //str[-36] = 'A';
  int16_t ptr_as_int = (int16_t) &g;
  int8_t byte_0 = ptr_as_int & 0x00FF;
  int8_t byte_1 = (ptr_as_int & 0xFF00) >> 8;
  str[off2] = byte_0;
  str[off3] = byte_1;
  //g(str, 'A');
}

int main(int argc, char *argv[]) {
  printf("%p\n", &g);
  f(20, 21);
  //f(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
  puts("returned from call to f");
}

