#include <stdio.h>

int main() {
    unsigned int addend_1, addend_2;
    printf("enter the first addend: ");
    scanf("%d", &addend_1);
    printf("enter the second addend: ");
    scanf("%d", &addend_2);

    for (int i = 1; i <= addend_2; i++) {
        addend_1++;
    }
    printf("the sum is: %d\n", addend_1);
}
