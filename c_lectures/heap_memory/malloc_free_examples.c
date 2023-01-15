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

int *compute_fibonacci_numbers(int n) {
  int *fib_array = (int*) malloc((n + 2) * sizeof(int));
  fib_array[1] = 1;
  for (int i = 2; i <= n; i++) {
    fib_array[i]= fib_array[i - 1] + fib_array[i - 2];
  }

  return fib_array;
}

int main(int argc, char *argv[]) {
  int *fib_numbers = compute_fibonacci_numbers(15);
  for (int i = 0; i <= 15; i++) {
    printf("%d-th fibonacci number:\t\t%d\n", i, fib_numbers[i]);
  }
  putchar('\n');
  free(fib_numbers);
}
