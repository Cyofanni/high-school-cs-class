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

void max_heapify(MAX_HEAP* h, int i) {
  int l = left(h, i);
  int r = right(h, i);
  int largest = i;

  if (l <= h->heap_size && h->array[l] > h->array[i]) {
    largest = l;
  }
  if (r <= h->heap_size && h->array[r] > h->array[largest]) {
    largest = r;
  }

  if (largest != i) {
    swap(&h->array[i], &h->array[largest]);
    max_heapify(h, largest);
  }
}

void print_heap(MAX_HEAP* h, int i) {
  if (i > h->heap_size) {
    putchar('_');
    return;
  }
  printf("%d", h->array[i]);
  putchar('(');
  print_heap(h, left(h, i));
  putchar(',');
  print_heap(h, right(h, i));
  putchar(')');
}

void build_max_heap(MAX_HEAP* h) {
  for (int i = h->heap_size / 2; i >= 1; i--) {
    max_heapify(h, i);
  }
}

void heap_sort(MAX_HEAP* h) {
  build_max_heap(h);
  for (int i = h->heap_size; i >= 2; i--) {
    swap(&h->array[1], &h->array[i]);
    h->heap_size--;
    max_heapify(h, 1);
  }
}
