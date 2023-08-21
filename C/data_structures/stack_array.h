#include <stdio.h>
#include <stdbool.h>

#define STACK_CAPACITY 8

typedef struct stack {
  int arr[STACK_CAPACITY];
  int top;
  int size;
} STACK;

void push(STACK*, int);

void pop(STACK*);

bool is_stack_full(STACK*);

bool is_stack_empty(STACK*);

void print_stack(STACK*);
