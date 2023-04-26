#include <stdio.h>

int main() {
    /*ex 0
    goto l1;
    while (1) {};
    l1:
        puts("code of p1 label.");
    */

    /*ex 1
    p1:
        goto p2;
    p2:
        goto p1;
    */

    /*ex 2
    unsigned int i = 1;
    begin_loop:
        if (i > 10)
            goto end_loop;
        printf("i: %u\n", i);
        i++;
        goto begin_loop;
    end_loop:
        printf("out of loop, i: %u\n", i);
    */
}
