#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 
*/

void hackers_function(char c1) {
  putchar(c1);
  putchar('\n');
  puts("hacker's function called...");
}

void f(int8_t param_offset, int8_t ret_addr_offset_0,
       int8_t ret_addr_offset_1) {
  char str[8];
  puts("hello f");
  int16_t ptr_as_int = (int16_t) &hackers_function;
  int8_t byte_0 = ptr_as_int & 0x00FF;
  int8_t byte_1 = (ptr_as_int & 0xFF00) >> 8;
  str[param_offset] = 0x63;
  str[ret_addr_offset_0] = byte_0;
  str[ret_addr_offset_1] = byte_1;
}

int main(int argc, char *argv[]) {
  printf("argv: %d, %d, %d\n", atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
  f(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
  puts("returned from call to f");
}
