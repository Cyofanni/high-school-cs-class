#include <stdio.h>

#define ARRAY_SIZE 33    //0 index is unused

typedef struct max_heap {
  int array[ARRAY_SIZE];
} MAX_HEAP;

int parent(MAX_HEAP*, int);

int left(MAX_HEAP*, int);

int right(MAX_HEAP*, int);

void max_heapify(MAX_HEAP*, int, int);

void print_heap(MAX_HEAP*, int, int);
