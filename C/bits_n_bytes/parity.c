#include <stdio.h>
#include <stdint.h>

/*add parity bit (even parity)
  1 bit count in the initial bit string is odd --> add trailing 1
  1 bit count in the initial bit string is even --> add trailing 0
*/
int main() {
    uint8_t n = 0b01000000;
    printf("initial bit string is: %b\n", n);
    int one_bit_cnt = 0;
    uint8_t n1 = n;
    int i = 1;
    while (i <= 8) {
        (n1 & 0b00000001) == 0b00000001 ? one_bit_cnt++ : 0;
        n1 = n1 >> 1;
        i++;
    }
    printf("1 bit count is: %d\n", one_bit_cnt);
    if (one_bit_cnt % 2) {
        printf("bit string with parity is: %b\n", (n << 1) + 1);
    }
    else {
        printf("bit string with parity is: %b\n", (n << 1));
    }
}
