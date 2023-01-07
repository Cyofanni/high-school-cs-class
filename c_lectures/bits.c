#include <stdio.h>
#include <string.h>
#include <limits.h>

#define LSB_MASK 1

void print_bits_int(int val) {
  const size_t sz_int_bits = sizeof(int) * 8;
  printf("integer value is: %d\n", val);
  const size_t sz_bits_spaces = sz_int_bits + sz_int_bits / 4 - 1; 
  char bits[sz_bits_spaces]; //make room for spaces
  
  unsigned int count;
  int curr_right_shifted = val;
  unsigned int bits_index = sz_bits_spaces - 1;
  for (count = 1; count <= sz_bits_spaces; count++) {
    if (count % 5 != 0) {
      bits[bits_index] = curr_right_shifted & LSB_MASK == 1 ? '1' : '0';
      curr_right_shifted = curr_right_shifted >> 1;
    }
    else {
      bits[bits_index] = ' ';
    }
    bits_index--;
  }
  printf("the bit layout is: %s\n", bits);
  if (val < 0) {
    puts("signed integers are represented in 2's complement");
  }
}

int main(int argc, char *argv[]) {
  print_bits_int(INT_MIN);
  return 0;
}
