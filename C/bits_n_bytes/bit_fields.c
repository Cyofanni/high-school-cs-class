#include <stdio.h>
#include <stdint.h>

struct unix_f_p
{
    uint8_t read;
    uint8_t write;
    uint8_t execute;
};

struct unix_f_p_bf
{
    uint8_t read : 1;
    uint8_t write : 1;
    uint8_t execute : 1;
};

int main() {
  printf("size without bit fields: %lu\n", sizeof(struct unix_f_p));
  printf("size with bit fields: %lu\n", sizeof(struct unix_f_p_bf));

  struct unix_f_p_bf file_1_p;
  file_1_p.read = 1;
  file_1_p.write = 0;
  file_1_p.execute = 1;

  if (file_1_p.read) {
    fputs("the file has read permission\n", stdout);
  }
  if (file_1_p.write) {
    fputs("the file has write permission\n", stdout);
  }
  if (file_1_p.execute) {
    fputs("the file has execute permission\n", stdout);
  }
}
