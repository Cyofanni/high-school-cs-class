#include <stdio.h>

int main() {
    short int n;
    unsigned short int extraction_counter = 1;
    printf("%s", "enter a signed hexadecimal number (max 2 bytes): ");
    scanf("%hx", &n);

    puts("its machine representation (reversed) is: ");
    putchar('\t');

    unsigned short int mask = 0x0001;
    while (extraction_counter <= sizeof(short int) * 8) {
      short int n_masked = n & mask;
      char lsb = n_masked == 1 ? '1' : '0';
      putchar(lsb);
      n = n >> 1;
      extraction_counter++;
    }
    putchar('\n');
}
