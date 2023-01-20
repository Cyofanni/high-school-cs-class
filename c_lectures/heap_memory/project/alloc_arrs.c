#include "alloc_arrs.h"
#include <stdlib.h>

DOUBLE_ARRAYS alloc_2_d_arrs(unsigned int sz) {
  DOUBLE_ARRAYS ret;
  double *p1 = (double*) calloc(sz, sizeof(double));
  double *p2 = (double*) calloc(sz, sizeof(double));
  ret.ptr1 = p1;
  ret.ptr2 = p2;
  
  return ret;
}
