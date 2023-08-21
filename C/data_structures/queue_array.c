#include "queue_array.h"

void enqueue(QUEUE* q, int key) {
  if (!is_full(q)) {
    q -> tail = (q -> tail + 1) % QUEUE_CAPACITY;
    q -> arr[q -> tail] = key;
    q -> size++;
  }
}

void dequeue(QUEUE* q) {
  if (!is_empty(q)) {
    q -> arr[q -> head] = 0;
    q -> head = (q -> head + 1) % QUEUE_CAPACITY;
    q -> size--;
  }
}

bool is_full(QUEUE* q) {
  return q -> size == QUEUE_CAPACITY;
}

bool is_empty(QUEUE* q) {
  return q -> size == 0;
}

void print(QUEUE* q) {
  if (q -> head <= q -> tail) {
    for (int i = q -> head; i <= q -> tail; i++) {
      printf("%d ", q -> arr[i]);
    }
  }
  else {
    for (int i = q -> head; i < QUEUE_CAPACITY; i++) {
      printf("%d ", q -> arr[i]);
    }
    for (int i = 0; i <= q -> tail; i++) {
      printf("%d ", q -> arr[i]);
    }
  }
  putchar('\n');
}

void print_debug(QUEUE* q) {
  for (int i = 0; i < QUEUE_CAPACITY; i++) {
    printf("%d ", q -> arr[i]);
  }
  printf("\n");
}
