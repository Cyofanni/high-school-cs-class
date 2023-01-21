#include "ex.h"
#include <stdlib.h>

DOUBLE_ARRAYS alloc_2_arrays(unsigned int sz) {
  DOUBLE_ARRAYS da;
  double *p = (double*) calloc(sz, sizeof(double));
  double *q = (double*) calloc(sz, sizeof(double));
  da.ptr1 = p;
  da.ptr2 = q;

  return da;
}

