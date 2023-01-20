#include "alloc_arrs.h"
#include <stdio.h>

#define SIZE_HEAP_ARRAY 8

int main(int argc, char *argv[]) {
  DOUBLE_ARRAYS d = alloc_2_d_arrs(SIZE_HEAP_ARRAY);
  for (int i = 0; i < SIZE_HEAP_ARRAY; i++) {
    printf("%f\t", d.ptr1[i]);
    printf("%f\n", d.ptr2[i]);
  }
 
  return 0;
}
