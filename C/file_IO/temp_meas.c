#include <stdio.h>

int main() {
    FILE *fptr = fopen("hour_temp", "r");

    int h;
    double t;
    while (fscanf(fptr, "%d", &h) != -1) {
        fscanf(fptr, "%lf", &t);
        printf("%d\t%4.2lf\n", h, t);
    }
    fclose(fptr);
}
