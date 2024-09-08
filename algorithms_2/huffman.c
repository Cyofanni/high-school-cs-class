#include <stdio.h>
#include <stdlib.h>

typedef struct sym {
  char name;
  double prob;
} SYM;

typedef struct node {
  SYM key;
  struct node* left;
  struct node* right;
} NODE;

NODE* extract_min(NODE* table[], int size) {
  NODE* min = (NODE*) malloc(sizeof(NODE));
  min -> key.name = '$';
  min -> key.prob = 1;
  int min_ind = -1;
  for (int i = 0; i < size; i++) {
    if (table[i] -> key.name != '$') {
      if (table[i] -> key.prob < min -> key.prob) {
	min -> key.name = table[i] -> key.name;
	min -> key.prob = table[i] -> key.prob;
	min -> left = table[i] -> left;
	min -> right = table[i] -> right;
	min_ind = i;
      }
    }
  }
  table[min_ind] -> key.name = '$';
  return min;
}

void put_new(NODE* table[], int size, NODE* new) {
  int i;
  for (i = 0; i < size && table[i] -> key.name != '$'; i++);
  table[i] = new;
}

int len_table(NODE* table[], int size) {
  int len = 0;
  for (int i = 0; i < size; i++) {
    if (table[i] -> key.name != '$') {
      len++;
    }
  }
  return len;
}

NODE* huffman(NODE* table[], int size) {
  NODE* new = NULL;

  while (len_table(table, size) >= 2) {
    NODE* x = extract_min(table, size);
    NODE* y = extract_min(table, size);
    new = (NODE*) malloc(sizeof(NODE));
    new -> key.name = 'z';
    new -> key.prob = x -> key.prob + y -> key.prob;
    new -> left = x;
    new -> right = y;
    put_new(table, size, new);
  }

  return new;
}

void print_tree(NODE* root) {
  if (!root) {
    return;
  }
  printf("%c_%.2f", root -> key.name, root -> key.prob);
  putchar('(');
  print_tree(root -> left);
  putchar(',');
  print_tree(root -> right);
  putchar(')');
}

int main() {
  NODE* n1 = (NODE*) malloc(sizeof(NODE));
  SYM k1 = {'f', 0.05};
  n1 -> key = k1;
  n1 -> left = NULL;
  n1 -> right = NULL;

  NODE* n2 = (NODE*) malloc(sizeof(NODE));
  SYM k2 = {'e', 0.09};
  n2 -> key = k2;
  n2 -> left = NULL;
  n2 -> right = NULL;

  NODE* n3 = (NODE*) malloc(sizeof(NODE));
  SYM k3 = {'c', 0.12};
  n3 -> key = k3;
  n3 -> left = NULL;
  n3 -> right = NULL;

  NODE* n4 = (NODE*) malloc(sizeof(NODE));
  SYM k4 = {'b', 0.13};
  n4 -> key = k4;
  n4 -> left = NULL;
  n4 -> right = NULL;

  NODE* n5 = (NODE*) malloc(sizeof(NODE));
  SYM k5 = {'d', 0.16};
  n5 -> key = k5;
  n5 -> left = NULL;
  n5 -> right = NULL;

  NODE* n6 = (NODE*) malloc(sizeof(NODE));
  SYM k6 = {'a', 0.45};
  n6 -> key = k6;
  n6 -> left = NULL;
  n6 -> right = NULL;

  NODE* table[] = {n1, n2, n3, n4, n5, n6};

  NODE* tree = huffman(table, 6);
  print_tree(tree);
  putchar('\n');
}
