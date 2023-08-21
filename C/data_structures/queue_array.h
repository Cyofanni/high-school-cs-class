#include <stdio.h>
#include <stdbool.h>

#define QUEUE_CAPACITY 8

typedef struct queue {
  int arr[QUEUE_CAPACITY];
  int head;
  int tail;
  int size;
} QUEUE;

void enqueue(QUEUE*, int);

void dequeue(QUEUE*);

bool is_queue_full(QUEUE*);

bool is_queue_empty(QUEUE*);

void print_queue(QUEUE*);

void print_queue_debug(QUEUE*);
