#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Buffer overflow with ip redirection.
   Simple example with constant data.
   echo 0 > /proc/sys/kernel/randomize_va_space
   gcc -fno-stack-protector -g -o buf_overflow buf_overflow.c
*/

void hackers_function() {
  puts("greetings from hackers function");
}

void f() {
  char str[8];
  puts("hello f");
  int16_t ptr_as_int = (int16_t) &hackers_function;
  int8_t byte_0 = ptr_as_int & 0x00FF;
  int8_t byte_1 = (ptr_as_int & 0xFF00) >> 8;

  str[20] = byte_0;
  str[21] = byte_1;
}

int main() {
  f();
  puts("returned from call to f");
}
