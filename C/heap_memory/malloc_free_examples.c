#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_HEAP_BYTES 32

void alloc_chars_heap(const char *str) {
  const char *p_str = str;
  char * const heap_bytes = (char*) malloc(N_HEAP_BYTES);

  for (size_t i = 0; i < N_HEAP_BYTES; ++i) {
    if (!*p_str) {
      p_str = str;
    }
    else {
      *(heap_bytes + i) = *p_str++;
    }
  }
  for (size_t i = 0; i < N_HEAP_BYTES; ++i) {
    putchar(heap_bytes[i]);
  }
  putchar('\n');
  free(heap_bytes);
}

void alloc_doubles_heap(double d) {
  double * const heap_bytes = (double*) malloc(N_HEAP_BYTES);
  for (int i = 0; i < N_HEAP_BYTES / sizeof(double); ++i) {
    printf("%p\n", heap_bytes + i);
  }
  for (size_t i = 0; i < N_HEAP_BYTES / sizeof(double); ++i) {
    heap_bytes[i] = d;
  }
  for (size_t i = 0; i < N_HEAP_BYTES / sizeof(double); ++i) {
    printf("%f ", heap_bytes[i]);
  }
  putchar('\n');

  free(heap_bytes);
}

int main(int argc, char *argv[]) {
}
