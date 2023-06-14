#include "queue_array.h"

void enqueue(QUEUE* q, int key) {
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
    }
  }
}

void dequeue(QUEUE* q) {
  q -> arr[q -> head] = 0;
  q -> head++;
  if (q -> head == QUEUE_SIZE) {
    q -> head = 0;
    q -> size--;
  }
}

void print(QUEUE* q) {
  for (int i = 0; i < QUEUE_CAPACITY; i++) {
    printf("%d ", q -> arr[i]);
  }
  putchar('\n');
}
