#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define SIZEOF_U_INT 32
//convert an unsigned int into 32-bit binary
void print_bits(unsigned int i) {
    char bits[SIZEOF_U_INT] = {};
    memset(bits, '0', SIZEOF_U_INT);
    unsigned int j = 1;
    do {
        bits[SIZEOF_U_INT - j] = (i % 2 == 1 ? '1' : '0');
        i /= 2;
        j++;
    } while (i != 0);
    for (int k = 0; k < SIZEOF_U_INT; k++) {
        putchar(bits[k]);
        if (!((k + 1) % 4)){
            putchar(' ');
        }
    }
    putchar('\n');
}

int main() {
  unsigned int a = 0xDEADBEEF;
  unsigned int result = ~a;
  printf("a in 8-digit hexadecimal and 32-bit binary is:       0x%08x", a);
  printf("       ");
  print_bits(a);
  printf("~a in 8-digit hexadecimal and 32-bit binary is:      0x%08x", result);
  printf("       ");
  print_bits(result);
}
