#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Buffer overflow with ip redirection;
   Simple example with constant data;
   echo 0 > /proc/sys/kernel/randomize_va_space
   gcc -fno-stack-protector -g -o buf_overflow buf_overflow.c
*/

void hackers_function() {
  puts("***HACKED***");
}

void f() {
  int8_t buffer[8];
  buffer[0] = 255;
  puts("f (licit function) called");
  buffer[16] = (int8_t)&hackers_function;
  //buffer[16] = 0x69;
}

int main() {
  printf("hacker's function's code starts at: %p\n", &hackers_function);
  f();
  puts("returned from call to f");
}
