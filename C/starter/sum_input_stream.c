#include <stdio.h>

int main() {
    int inp, sum = 0;
    printf("enter an integer, -1 to quit: ");
    scanf("%d", &inp);
    printf("\n");
    while (inp != -1) {
        sum += inp;
        printf("enter an integer, -1 to quit: ");
        scanf("%d", &inp);
        printf("\n");
    }
    printf("the sum is: %d\n", sum);
}
