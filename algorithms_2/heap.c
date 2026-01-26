#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct t_node {
  int key;
  struct t_node* left;
  struct t_node* right;
};

void print_tree(struct t_node* t) {
  if (!t) {
    putchar('_');
    return;
  }
  printf("%d", t -> key);
  putchar('(');
  print_tree(t -> left);
  putchar(',');
  print_tree(t -> right);
  putchar(')');
}

bool is_max_heap(struct t_node* t) {
  if (!t) {
    return true;
  }
  if (!t -> left && !t -> right) {
    return true;
  }
  if (t -> left && t -> left -> key > t -> key) {
    return false;
  }
  if (t -> right && t -> right -> key > t -> key) {
    return false;
  }
  return is_max_heap(t -> left) && is_max_heap(t -> right);
}

void swap(int* a, int* b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void max_heapify(struct t_node* x) {
  if (!x) {
    return;
  }
  if (!x -> left && !x -> right) {
    return;
  }
  int m = x -> key;
  bool max_root = true, max_left = false, max_right = false;

  if (x -> left && x -> left -> key > m) {
    m = x -> left -> key;
    max_root = false;
    max_left = true;
  }
  if (x -> right && x -> right -> key > m) {
    m = x -> right -> key;
    max_root = false;
    max_left = false;
    max_right = true;
  }
  if (max_left == true) {
    swap(&x -> key, &x -> left -> key);
    max_heapify(x -> left);
  }
  else if (max_right == true) {
    swap(&x -> key, &x -> right -> key);
    max_heapify(x -> right);
  }
}

int main() {
  struct t_node* a = malloc(sizeof(struct t_node));
  a -> key = 3;
  a -> left = NULL;
  a -> right = NULL;
  struct t_node* b = malloc(sizeof(struct t_node));
  b -> key = 2;
  b -> left = NULL;
  b -> right = NULL;
  struct t_node* c = malloc(sizeof(struct t_node));
  c -> key = 4;
  c -> left = NULL;
  c -> right = NULL;
  struct t_node* d = malloc(sizeof(struct t_node));
  d -> key = 8;
  d -> left = NULL;
  d -> right = NULL;
  struct t_node* e = malloc(sizeof(struct t_node));
  e -> key = 5;
  e -> left = NULL;
  e -> right = NULL;
  struct t_node* f = malloc(sizeof(struct t_node));
  f -> key = 8;
  f -> left = a;
  f -> right = b;
  struct t_node* g = malloc(sizeof(struct t_node));
  g -> key = 6;
  g -> left = c;
  g -> right = NULL;
  struct t_node* h = malloc(sizeof(struct t_node));
  h -> key = 10;
  h -> left = f;
  h -> right = g;
  struct t_node* i = malloc(sizeof(struct t_node));
  i -> key = 6;
  i -> left = d;
  i -> right = e;
  struct t_node* j = malloc(sizeof(struct t_node));
  j -> key = 16;
  j -> left = h;
  j -> right = i;

  print_tree(j);
  printf("\n%d\n", is_max_heap(j));
  max_heapify(i);
  putchar('\n');
  print_tree(j);
  putchar('\n');
}
