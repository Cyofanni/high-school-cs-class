#include <stdio.h>
#include <stdint.h>

int main() {
  uint8_t x = 255;
  printf("%hhu\n", x << 1);

  uint8_t a = 7;
  printf("%hhu\n", ~a);

  uint8_t w = 0xAB;
  uint8_t z = 0xCD;
  printf("0x%hhx\n", w & z);
}
