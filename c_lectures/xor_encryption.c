#include <stdio.h>
#include <string.h>

void enc_dec(const char *pt, const char *k, char *ct) {
  const char *key_iter = k;
  
  for (; *pt; ) {
    if (!(*key_iter)) {
      key_iter = k;
    }
    *ct++ = *pt++ ^ *key_iter++;
  }
}

void print_bytes(const char *str) {
  while (*str) {
    printf("%02x", *str++ & 0xFF);
  }
  putchar('\n');
}

int main(int argc, char *argv[]) {
  char plaintext[30] = "alan turing died in 1954";
  char ciphertext[30] = {};
  char key[5] = {0xCA, 0xFE, 0xBE, 0xEF, 0x00};

  puts("key bytes (hex): ");
  print_bytes(key);
  puts("");
  
  puts("encryption");
  enc_dec(plaintext, key, ciphertext);
  printf("plaintext:             %s\n", plaintext);
  printf("ciphertext bytes (hex) ");
  print_bytes(ciphertext);
  puts("");

  puts("decryption");
  enc_dec(ciphertext, key, plaintext);
  printf("ciphertext bytes (hex): ");
  print_bytes(ciphertext);
  printf("plaintext:              %s", plaintext);
  puts("");
}
