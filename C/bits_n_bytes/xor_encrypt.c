#include <stdio.h>

int main() {
    //plaintext: 'hello'
    unsigned long plaintext = 0x00000068656c6c6f;
    printf("plaintext (string): ");
    printf("%c", (plaintext & 0x000000ff00000000) >> 32);
    printf("%c", (plaintext & 0x00000000ff000000) >> 24);
    printf("%c", (plaintext & 0x0000000000ff0000) >> 16);
    printf("%c", (plaintext & 0x000000000000ff00) >> 8);
    printf("%c\n", (plaintext & 0x000000000000ff));

    unsigned long key = 0x10ff0044cafebeef;

    unsigned long ciphertext = plaintext ^ key;
    printf("ciphertext, as unsigned long (hex): 0x%lx\n", ciphertext);

    //decryption
    unsigned long decryption = ciphertext ^ key;
    printf("result of decryption (string): ");
    printf("%c", (decryption & 0x000000ff00000000) >> 32);
    printf("%c", (decryption & 0x00000000ff000000) >> 24);
    printf("%c", (decryption & 0x0000000000ff0000) >> 16);
    printf("%c", (decryption & 0x000000000000ff00) >> 8);
    printf("%c\n", (decryption & 0x000000000000ff));
}
