#include <stdio.h>

int main() {
    FILE *fptr_n = fopen("numbers_data", "r");
    FILE *fptr_e = fopen("evens_data", "w");

    int n;
    while (fscanf(fptr_n, "%d", &n) != -1) {
        if (!(n % 2)) {
            fprintf(fptr_e, "%d ", n);
        }
    }
    fputc('\n', fptr_e);
    fclose(fptr_n);
    fclose(fptr_e);
}
