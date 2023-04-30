#include <stdio.h>

/*compute the hamming distance between binary
  representation of two unsigned shorts
*/

int main() {
    unsigned short int x = 0xFFFF;
    unsigned short int y = 0xAEEA;

    int bit_cnt = 1;
    int ham_dis_count = 0;
    while (bit_cnt < sizeof(unsigned short int) * 8) {
        unsigned short int cur_lsb_x = x & 0x0001;
        unsigned short int cur_lsb_y = y & 0x0001;
        ham_dis_count += cur_lsb_x ^ cur_lsb_y;

        x = x >> 1;
        y = y >> 1;
        bit_cnt++;
    }

    printf("hamming_distance(x, y): %d\n", ham_dis_count);
}
