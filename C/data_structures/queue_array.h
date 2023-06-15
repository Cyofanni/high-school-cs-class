#include <stdio.h>

#define QUEUE_CAPACITY 8
#define FULL_QUEUE_ERR 4096

typedef struct queue {
  int arr[QUEUE_CAPACITY];
  int head;
  int tail;
  int size;
} QUEUE;

void enqueue(QUEUE*, int);

void dequeue(QUEUE*);

void print(QUEUE*);

void print_debug(QUEUE*);
