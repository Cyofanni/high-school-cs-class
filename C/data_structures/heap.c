#include "heap.h"

int parent(MAX_HEAP* h, int i) {
  return i / 2;
}

int left(MAX_HEAP* h, int i) {
  return 2 * i;
}

int right(MAX_HEAP* h, int i) {
  return 2 * i + 1;
}

void swap(int* x, int* y) {
  int t = *x;
  *x = *y;
  *y = t;
}

void max_heapify(MAX_HEAP* h, int i, int heap_size) {
  int l = left(h, i);
  int r = right(h, i);
  int largest = i;

  if (l <= heap_size && h->array[l] > h->array[i]) {
    largest = l;
  }
  if (r <= heap_size && h->array[r] > h->array[largest]) {
    largest = r;
  }

  if (largest != i) {
    swap(&h->array[i], &h->array[largest]);
    max_heapify(h, largest, heap_size);
  }
}

void print_heap(MAX_HEAP* h, int i, int heap_size) {
  if (i > heap_size) {
    putchar('_');
    return;
  }
  printf("%d", h->array[i]);
  putchar('(');
  print_heap(h, left(h, i), heap_size);
  putchar(',');
  print_heap(h, right(h, i), heap_size);
  putchar(')');
}
