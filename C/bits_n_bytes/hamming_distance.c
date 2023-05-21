#include <stdio.h>
#include <stdint.h>

/*compute the hamming distance between binary
  representation of two uint8_t
*/

int main() {
    uint8_t x = 0xFF;
    uint8_t y = 0x11;

    int bit_cnt = 1;
    int ham_dis_count = 0;
    while (bit_cnt <= sizeof(uint8_t) * 8) {
        uint8_t cur_lsb_x = x & 0x01;
        uint8_t cur_lsb_y = y & 0x01;
        ham_dis_count += cur_lsb_x ^ cur_lsb_y;

        x = x >> 1;
        y = y >> 1;
        bit_cnt++;
    }

    printf("hamming_distance(x, y): %d\n", ham_dis_count);
}
