#include "types.h"

TREE_NODE *bst_insert_rec(TREE_NODE *node, int k, unsigned level);

TREE_NODE *bst_insert_rec_p(TREE_NODE *node, TREE_NODE *p_node, int k, unsigned level);

TREE_NODE *bst_insert_iterative(TREE_NODE *t, int key, unsigned int level);

void set_visited_false(TREE_NODE *node);

void in_order(TREE_NODE *node);

void pre_order(TREE_NODE *node);

void post_order(TREE_NODE *node);

void in_order_iter(TREE_NODE *t_node);

void pre_order_iter(TREE_NODE *t_node);

void post_order_iter(TREE_NODE *t_node);

void print_n_chars(int n, char c);

void breadth_first_search(TREE_NODE *t);

TREE_NODE *search_bst_recursive(TREE_NODE *t, int k);

TREE_NODE *search_bst_iterative(TREE_NODE *t, int k);

TREE_NODE *bst_minimum_recursive(TREE_NODE *t);

TREE_NODE *bst_minimum_iterative(TREE_NODE *t);

TREE_NODE *bst_maximum_recursive(TREE_NODE *t);

TREE_NODE *bst_maximum_iterative(TREE_NODE *t);
