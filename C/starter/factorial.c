#include <stdio.h>

int main() {
    long num;
    printf("enter an integer: ");
    scanf("%ld", &num);
    while (num >= 0) {
        long result = 1;
        long i = num;
        while (i >= 1) {
            result = result * i;
            i--;
        }
        printf("factorial of %ld is %ld\n\n", num, result);
        printf("enter an integer: ");
        scanf("%ld", &num);
    }
}
