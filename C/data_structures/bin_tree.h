#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct tree_node {
  int key, height;
  struct tree_node* left;
  struct tree_node* right;
  struct tree_node* parent;
} T_NODE;

T_NODE* bst_insert_iter(T_NODE*, int);

T_NODE* bst_insert_rec(T_NODE*, int);

T_NODE* bst_parent_insert_iter(T_NODE*, int);

void print_tree(T_NODE*);

int height(T_NODE*);

int sum_keys(T_NODE*);

int count_nodes(T_NODE*);

T_NODE* minimum_rec(T_NODE*);

T_NODE* maximum_rec(T_NODE*);

T_NODE* minimum_iter(T_NODE*);

T_NODE* successor(T_NODE*, T_NODE*);

T_NODE* delete_node(T_NODE*, T_NODE*);

bool bst_search_rec(T_NODE*, int);

bool bst_search_iter(T_NODE*, int);

T_NODE* rotate_right(T_NODE*, T_NODE*);

T_NODE* rotate_left(T_NODE*, T_NODE*);

bool match(T_NODE*, T_NODE*);

int max_bin_tree(T_NODE*, int);

int min_bin_tree(T_NODE*, int);

bool verify_bst(T_NODE*);

void set_heights_1(T_NODE*);

void set_heights_2(T_NODE*);
