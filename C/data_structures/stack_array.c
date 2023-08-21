#include "stack_array.h"

void push(STACK* s, int key) {
  if (!is_stack_full(s)) {
    s -> top++;
    s -> arr[s -> top] = key;
    s -> size++;
  }
}

void pop(STACK* s) {
  if (!is_stack_empty(s)) {
    s -> top--;
    s -> size--;
  }
}

bool is_stack_full(STACK* s) {
  return s -> size == STACK_CAPACITY;
}

bool is_stack_empty(STACK* s) {
  return s -> size == 0;
}

void print_stack(STACK* s) {
  for (int i = s -> top; i >= 0; i--) {
    printf("%d\n", s -> arr[i]);
    puts("----");
  }
  putchar('\n');
}
