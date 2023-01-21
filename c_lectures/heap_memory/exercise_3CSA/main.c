#include <stdio.h>
#include <stdlib.h>
#include "ex.h"

#define SIZE 16

int main() {
  DOUBLE_ARRAYS d = alloc_2_arrays(SIZE); 
  for (int i = 0; i < SIZE; i++) {
    printf("%f\t", d.ptr1[i]);
    printf("%f\t", d.ptr2[i]);
    putchar('\n');
  }

  free(d.ptr1);
  free(d.ptr2);
}
