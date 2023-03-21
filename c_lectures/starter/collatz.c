#include <stdio.h>

int main() {
    unsigned long int n;
    printf("enter a number to verify Collatz conjecture: ");
    scanf("%ld", &n);

    //no proof, could last forever...
    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        }
        else {
            n = 3 * n + 1;
        }
        printf("%ld\n", n);
    }
}
