#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp = fopen("fibonacci_data", "r");
  if (!fp) {
    fprintf(stderr, "%s", "cannot open file\n");
    exit(EXIT_FAILURE);
  }

  int fib, read;
  while ((read = fscanf(fp, "%d", &fib)) != -1) {
    fprintf(stdout, "%d\n", fib);
  }
}
