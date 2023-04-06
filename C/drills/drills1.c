/*
  write a recursive function that
  checks if two linked lists have
  the same content.
  e.g. consider the lists L1: 2->5->6->1
  and L2: 2->5->6->1, we could say that
  L1 is equal to L2

  write a recursive function that returns the sum of the keys
  of a linked list
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct list_node {
  char key;
  struct list_node *next;
} LIST_NODE;

int is_list_equal(LIST_NODE *l1, LIST_NODE *l2) {
  if (!l1 && !l2) {
    return 1;
  }
  if ((!l1 && l2) || (l1 && !l2)) {
    return 0;
  }
  if (l1->key != l2->key) {
    return 0;
  }

  return is_list_equal(l1->next, l2->next);
}

int main() {
  LIST_NODE *n = NULL;
  n = (LIST_NODE*) malloc(sizeof(LIST_NODE));
  n->key = 'a';

  n->next = (LIST_NODE*) malloc(sizeof(LIST_NODE));
  n->next->key = 'b';

  LIST_NODE *n1 = NULL;
  n1 = (LIST_NODE*) malloc(sizeof(LIST_NODE));
  n1->key = 'a';

  n1->next = (LIST_NODE*) malloc(sizeof(LIST_NODE));
  n1->next->key = 'b';

  printf("%d\n", is_list_equal(n, n1));
}
