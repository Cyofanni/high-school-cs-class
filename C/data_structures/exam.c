#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct list_node {
  int key;
  struct list_node* next;
} LNODE;

//count even keys in linked list
//1
int count_even(LNODE* n) {
  int c = 0;
  while (n) {
    if (n -> key % 2 == 0) {
      c++;
    }
    n = n -> next;
  }
  return c;
}

//4
void remove_all(LNODE* n) {
  if (!n) {
    return;
  }
  remove_all(n -> next);
  free(n);
}

void f() {
  f();
}

//5
bool linear_search(LNODE* n, int key) {
  if (!n) {
    return false;
  }
  if (n -> key == key) {
    return true;
  }
  return linear_search(n -> next, key);
}

//linked lists: sequential access
//arrays: random access

LNODE* insert_back(LNODE* n, int key) {
  //code
  return NULL;
}

//8
int main() {
  LNODE* l = NULL;
  for (int i = 1; i <= 50; i++) {
    l = insert_back(l, i * 8);
  }
}
