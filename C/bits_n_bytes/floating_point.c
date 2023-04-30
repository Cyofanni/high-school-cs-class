#include <stdio.h>
#include <stdint.h>

#define IEEE_754_SINGLE_SIZE 32

union f_i {
  float f;
  unsigned int i;
};

int main() {
    union f_i f_i_var;
    f_i_var.f = 0.5;
    int8_t ieee754_bits[IEEE_754_SINGLE_SIZE];

    for (int j = 1; j <= IEEE_754_SINGLE_SIZE; j++) {
      int8_t bit = f_i_var.i & 0x00000001;
      ieee754_bits[IEEE_754_SINGLE_SIZE - j] = bit;
      f_i_var.i = f_i_var.i >> 1;
    }
    for (int j = 0; j < IEEE_754_SINGLE_SIZE; j++) {
      printf("%d", ieee754_bits[j]);
    }
    putchar('\n');
}
