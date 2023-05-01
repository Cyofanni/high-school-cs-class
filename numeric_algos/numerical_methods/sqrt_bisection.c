#include <stdio.h>
#include <stdbool.h>

#define NUM_ITERS 1024

int main() {
    double n;
    printf("enter a number: ");
    scanf("%lf", &n);

    bool found_root = false;
    double low = 1, high = n, middle;

    for (int counter = 0; counter < NUM_ITERS && !found_root; counter++) {
        middle = (low + high) / 2;
        double middle_squared = middle * middle;
        if (n < middle_squared) {
            high = middle;
        }
        else if (n > middle_squared) {
            low = middle;
        }
        else {
            found_root = true;
        }
    }

    printf("sqrt(%lf) is: %25.15lf\n", n, middle);
}
