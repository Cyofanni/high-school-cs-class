#include <stdio.h>

int main() {
    int k;
    while (1) {
        printf("enter an integer: ");
        scanf("%d", &k);
        if (k == -1) {
            break;
        }
    }

    puts("exiting program...");
}
