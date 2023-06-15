#include <stdio.h>
#include <stdlib.h>

typedef struct list_node {
  int key;
  struct list_node* next;
} L_NODE;

L_NODE* insert_back_iter(L_NODE*, int);

L_NODE* insert_back_rec(L_NODE*, int);

L_NODE* insert_front(L_NODE*, int);

L_NODE* insert_iter(L_NODE*, int, int);

L_NODE* insert_rec(L_NODE*, int, int);

void print_rec(L_NODE*);
