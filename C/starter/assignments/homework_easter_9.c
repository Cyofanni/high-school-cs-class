#include <stdio.h>

int main() {
    int inp = 0, previous = -1;
    printf("enter an integer: ");
    scanf("%d", &inp);
    
    while (inp != previous) {
        previous = inp;
        printf("enter an integer: ");
        scanf("%d", &inp);
    }
}
