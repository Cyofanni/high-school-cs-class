#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define IEEE_754_DOUBLE_SIZE 64

union f_i {
  double f;
  uint64_t i;
};

int main() {
    union f_i f_i_var;
    f_i_var.f = 27.56640625;
    printf("The machine representation (IEEE 754 - double precision) of %10.8lf is:\n",
            f_i_var.f);

    char bits[IEEE_754_DOUBLE_SIZE + 1] = {};
    for (int i = 1; i <= IEEE_754_DOUBLE_SIZE; i++) {
        int8_t bit = f_i_var.i & 0x0000000000000001;
        bits[IEEE_754_DOUBLE_SIZE - i] = bit == 1 ? '1' : '0';
        f_i_var.i >>= 1;
    }

    for (int i = 0; i < strlen(bits); i++) {
        fputc(bits[i], stdout);
        if (i == 0) {
            fputc(' ', stdout);
        }
        else if (i == 11) {
            fputc(' ', stdout);
        }
    }
    putchar('\n');
}
