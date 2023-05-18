#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int8_t c = 0;
  char buffer[8];
  strcpy(buffer, argv[1]);

  if (c) {
    fputs("access granted\n", stdout);
  }
  else {
    fputs("access denied\n", stdout);
  }
}
