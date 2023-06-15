#include "dyn_int_vector.h"

dyn_int_vector::dyn_int_vector(int size, int val) {
  this -> size = size;
  ptr = new int[size];
  for (int i = 0; i < size; i++) {
    ptr[i] = val;
  }
}

dyn_int_vector :: ~dyn_int_vector() {
  delete[] ptr;
}
