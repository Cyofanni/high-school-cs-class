#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    unsigned short int i = 0xFF10;
    char buffer[8] = {};

    gets(buffer);

    printf("0x%02x\n", i);
}
