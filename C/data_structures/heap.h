#include <stdio.h>

#define ARRAY_SIZE 33    //0 index is unused

typedef struct max_heap {
  int array[ARRAY_SIZE];
  int heap_size;
} MAX_HEAP;

int parent(MAX_HEAP*, int);

int left(MAX_HEAP*, int);

int right(MAX_HEAP*, int);

void max_heapify(MAX_HEAP*, int);

void build_max_heap(MAX_HEAP*);

void print_heap(MAX_HEAP*, int);

void heap_sort(MAX_HEAP*);
