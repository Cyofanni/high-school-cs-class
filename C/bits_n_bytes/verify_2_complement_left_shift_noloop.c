#include <stdio.h>

int main() {
    short int n;
    printf("%s", "enter a signed hexadecimal number (max 2 bytes): ");
    scanf("%hx", &n);

    puts("its machine representation (reversed) is: ");
    putchar('\t');
    /*extract lsb: 1*/
    short int n_masked_0x0001 = n & 0x0001;
    char lsb = n_masked_0x0001 == 1 ? '1' : '0';
    putchar(lsb);

    /*extract lsb: 2*/
    n = n >> 1;
    n_masked_0x0001 = n & 0x0001;
    lsb = n_masked_0x0001 == 1 ? '1' : '0';
    putchar(lsb);

    /*extract lsb: 3*/
    n = n >> 1;
    n_masked_0x0001 = n & 0x0001;
    lsb = n_masked_0x0001 == 1 ? '1' : '0';
    putchar(lsb);

    /*extract lsb: 4*/
    n = n >> 1;
    n_masked_0x0001 = n & 0x0001;
    lsb = n_masked_0x0001 == 1 ? '1' : '0';
    putchar(lsb);

    /*extract lsb: 5*/
    n = n >> 1;
    n_masked_0x0001 = n & 0x0001;
    lsb = n_masked_0x0001 == 1 ? '1' : '0';
    putchar(lsb);

    /*extract lsb: 6*/
    n = n >> 1;
    n_masked_0x0001 = n & 0x0001;
    lsb = n_masked_0x0001 == 1 ? '1' : '0';
    putchar(lsb);

    /*extract lsb: 7*/
    n = n >> 1;
    n_masked_0x0001 = n & 0x0001;
    lsb = n_masked_0x0001 == 1 ? '1' : '0';
    putchar(lsb);

    /*extract lsb: 8*/
    n = n >> 1;
    n_masked_0x0001 = n & 0x0001;
    lsb = n_masked_0x0001 == 1 ? '1' : '0';
    putchar(lsb);

    /*extract lsb: 9*/
    n = n >> 1;
    n_masked_0x0001 = n & 0x0001;
    lsb = n_masked_0x0001 == 1 ? '1' : '0';
    putchar(lsb);

    /*extract lsb: 10*/
    n = n >> 1;
    n_masked_0x0001 = n & 0x0001;
    lsb = n_masked_0x0001 == 1 ? '1' : '0';
    putchar(lsb);

    /*extract lsb: 11*/
    n = n >> 1;
    n_masked_0x0001 = n & 0x0001;
    lsb = n_masked_0x0001 == 1 ? '1' : '0';
    putchar(lsb);

    /*extract lsb: 12*/
    n = n >> 1;
    n_masked_0x0001 = n & 0x0001;
    lsb = n_masked_0x0001 == 1 ? '1' : '0';
    putchar(lsb);

    /*extract lsb: 13*/
    n = n >> 1;
    n_masked_0x0001 = n & 0x0001;
    lsb = n_masked_0x0001 == 1 ? '1' : '0';
    putchar(lsb);

    /*extract lsb: 14*/
    n = n >> 1;
    n_masked_0x0001 = n & 0x0001;
    lsb = n_masked_0x0001 == 1 ? '1' : '0';
    putchar(lsb);

    /*extract lsb: 15*/
    n = n >> 1;
    n_masked_0x0001 = n & 0x0001;
    lsb = n_masked_0x0001 == 1 ? '1' : '0';
    putchar(lsb);

    /*extract lsb: 16*/
    n = n >> 1;
    n_masked_0x0001 = n & 0x0001;
    lsb = n_masked_0x0001 == 1 ? '1' : '0';
    putchar(lsb);

    putchar('\n');
}
