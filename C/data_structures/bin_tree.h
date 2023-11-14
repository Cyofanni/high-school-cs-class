#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tree_node {
  int key;
  struct tree_node* left;
  struct tree_node* right;
} T_NODE;

T_NODE* bst_insert_iter(T_NODE*, int);

T_NODE* bst_insert_rec(T_NODE*, int);

void print_tree(T_NODE*);

int height(T_NODE*);
