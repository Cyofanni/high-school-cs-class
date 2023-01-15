#include <stdio.h>
#include <string.h>

/* Buffer overflow with ip redirection.
   Simple example with constant data.
   echo 0 > /proc/sys/kernel/randomize_va_space
   gcc -fno-stack-protector -g -o buf_overflow buf_overflow.c 
*/

int hackers_function() {
  puts("greetings from the hacker");
}

int f() {
  char str[8];
  puts("hello f");
  str[16] = 0x69;
  str[17] = 0x51;
}

int main() {
  printf("hackers function at address: %p\n", hackers_function);
  f();
  puts("returned from call to f");
}
