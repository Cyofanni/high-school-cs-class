#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

int main() {
    /*ex 1
    b:
        fputc('a', stdout);
        goto a;
    a:
        goto b;
    */

    /*ex 2
    for(; true; ) {
        char c = fgetc(stdin);
        fputc(c, stdout);
        if (c == 'q') {
            break;
        }
    }*/

    /*ex 3
    unsigned int i = 0;
    while (i < 10) {
        fprintf(stdout, "%u\n", i);
        unsigned int j = 0;
        while (j <= 10) {
            break;
        }
        ++i;
    }*/

    /*ex 4
    uint8_t k = 0;
    while (k < 128) {
        k += 1;
        if (k % 2 == 0) {
            continue;
        }
        printf("k: %u, ", k);
        fputs("hello world\n", stdout);
    }
    */

    /*ex 5
        i: 1 --> j: 1 (k: 1, k: 2, k: 3, k: 4, k: 5), j: 2 (k: 1, k: 2, k: 3, k: 4, k: 5)
        i: 2 --> j: 1 (k: 1, k: 2, k: 3, k: 4, k: 5), j: 2 (k: 1, k: 2, k: 3, k: 4, k: 5)
        i: 3 --> j: 1 (k: 1, k: 2, k: 3, k: 4, k: 5), j: 2 (k: 1, k: 2, k: 3, k: 4, k: 5)
    */

    /*
    int i = 1;
    int inp;
    int count = 0;
    while (i <= 3) {
        int j = 1;
        while (j <= 2) {
            int k = 1;
            while (k <= 5) {
                fscanf(stdin, "%d", &inp);
	        k++;
	        count++;
            }
            j++;
        }
        i++;
    }
    printf("number of iterations: %d\n", count);
    */
    /*
    int i = 1;
    while (i <= 10) {
        printf("%d\n", i);
        i++;
    }
    */

    /*ex 6
    int i = 1;
    start_loop:
        if (i == 11) {
            goto end_loop;
        }
        printf("%d\n", i);
        i++;
        goto start_loop;
    end_loop:
    */
}
