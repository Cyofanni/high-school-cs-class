#include <stdio.h>
#include <string.h>
#include <limits.h>

//the mask extracts the least significant bit
#define LSB_MASK 1

#define BYTES 0xDEADBEEF
#define BYTES_SEQ_LENGTH 4

void print_bits_int(int val, int is_float) {
  const size_t sz_int_bits = sizeof(int) * 8;
  printf("integer value is: %d\n", val);
  const size_t sz_bits_and_spaces = sz_int_bits + sz_int_bits / 4 - 1; 
  char bits[sz_bits_and_spaces]; //make room for spaces, 1 space between each nibble
  
  unsigned int count;
  int curr_right_shifted = val;
  unsigned int bits_index = sz_bits_and_spaces - 1;
  for (count = 1; count <= sz_bits_and_spaces; count++) {
    if (count % 5 != 0) {
      //get the rightmost bit and then shift to the right
      bits[bits_index] = curr_right_shifted & LSB_MASK == 1 ? '1' : '0';
      curr_right_shifted = curr_right_shifted >> 1;
    }
    //1 space after each nibble
    else {
      bits[bits_index] = ' ';
    }
    bits_index--;
  }
  if (!is_float) {
    printf("the bit layout is: %s\n", bits);
    if (val < 0) {
      puts("signed integers are represented in 2's complement");
    }
  }
  else {
    //skip spaces
    printf("the bit layout (IEEE 754 single precision) is:\n");
    printf("\tsign_bit:      %c\n", bits[0]);
    printf("\texponent bits: ");
    for (int i = 1; i <= 3; i++) {
      printf("%c ", bits[i]);
    }
    //space at position 4
    for (int i = 5; i <= 8; i++) {
      printf("%c ", bits[i]);
    }
    //space at position 9
    printf("%c", bits[10]);
    putchar('\n');
    printf("\tmantissa bits: ");
    for (int i = 11; i <= sz_bits_and_spaces - 1; i++) {
      if ((i + 1) % 5 != 0) {
	printf("%c ", bits[i]);
      }
    }
    putchar('\n');
  }
  
}

void show_endianness() {
  unsigned int bytes = BYTES;
  unsigned char *bytes_ptr = (unsigned char*)&bytes;
  printf("bytes sequence is 0x%04X\n", bytes);
  putchar('\n');
  puts("bytes in memory, ordered by increasing addresses:");
  for (int i = 0; i < BYTES_SEQ_LENGTH; i++) {
    printf("\tbyte 0x%02X at address %p\n", *(bytes_ptr + i) & 0xFF, bytes_ptr + i);
  }
}

union floating_point__bits {
  float f;
  unsigned int ui;
};

int main(int argc, char *argv[]) {
  union floating_point__bits fb;
  fb.f = 0.15625;
  print_bits_int(fb.ui, 1);
  
  return 0;
}
