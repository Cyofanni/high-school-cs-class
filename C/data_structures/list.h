#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct list_node {
  int key;
  struct list_node* next;
} L_NODE;

typedef struct list_node_d {
  int key;
  struct list_node_d* prev;
  struct list_node_d* next;
} L_NODE_D;

L_NODE* alloc_node(int);

L_NODE* insert_back_iter(L_NODE*, int);

L_NODE* insert_back_rec(L_NODE*, int);

L_NODE* insert_front(L_NODE*, int);

L_NODE* insert_iter(L_NODE*, int, int);

L_NODE* insert_rec(L_NODE*, int, int);

L_NODE* remove_iter(L_NODE*, int);

int lin_search_iter(L_NODE*, int);

L_NODE* node_at_ind(L_NODE*, int);

bool is_sorted(L_NODE*);

void bubble_sort(L_NODE*);

L_NODE_D* insert_back_iter_d(L_NODE_D*, int);

void print_rec(L_NODE*);
