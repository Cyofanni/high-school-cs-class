#include <stdio.h>

int main() {
    unsigned int mult_1, mult_2;
    unsigned int product = 0;
    printf("enter the multiplicand: ");
    scanf("%d", &mult_1);
    printf("enter the multiplicator: ");
    scanf("%d", &mult_2);

    for (int i = 1; i <= mult_2; i++) {
        product += mult_1;
    }
    printf("the product is: %d\n", product);
}
