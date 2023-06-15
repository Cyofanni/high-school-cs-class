#include "queue_array.h"

void enqueue(QUEUE* q, int key) {
  if (q -> size < QUEUE_CAPACITY) {
    q -> tail++;
    if (q -> tail == QUEUE_CAPACITY) {
      q -> tail = 0;
    }

    if (q -> size == 0) {
      q -> arr[q -> tail] = key;
      q -> size++;
    }
    else {
      if (q -> head != q -> tail) {
	q -> arr[q -> tail] = key;
	q -> size++;
      }
    }
  }
}

void dequeue(QUEUE* q) {
  if (q -> size > 0) {
    q -> arr[q -> head] = 0;
    q -> head++;
    if (q -> head == QUEUE_CAPACITY) {
      q -> head = 0;
    }
    q -> size--;
  }
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
