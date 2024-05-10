#include <stdio.h>
#include <string.h>

/* compilation command:
     gcc -fno-stack-protector -o stack_buf_overflow_basic stack_buf_overflow_basic.c
*/
int main(int argc, char* argv[]) {
    unsigned short int i = 0xFF10;
    char buffer[8] = {};

    gets(buffer);

    printf("0x%X\n", i);
}
