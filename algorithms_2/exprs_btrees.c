#include <stdio.h>
#include <stdlib.h>

typedef struct btree_node {
  char item;
  struct btree_node *left, *right;
} BTNODE;

void in_order(BTNODE* t) {
  if (!t) {
    return;
  }
  in_order(t -> left);
  printf("%c ", t -> item);
  in_order(t -> right);
}

int eval(BTNODE* t) {
  if (!t) {
    return 0;
  }
  if (!t -> left && !t -> right) {
    return t -> item - '0';
  }
  switch (t -> item) {
    case '+':
      return eval(t -> left) + eval(t -> right);
    break;
   case '*':
      return eval(t -> left) * eval(t -> right);
    break;
  }
}

int main() {
  BTNODE* n1 = (BTNODE*) malloc(sizeof(BTNODE));
  n1 -> item = '+';
  BTNODE* n2 = (BTNODE*) malloc(sizeof(BTNODE));
  n2 -> item = '5';
  BTNODE* n3 = (BTNODE*) malloc(sizeof(BTNODE));
  n3 -> item = '*';
  BTNODE* n4 = (BTNODE*) malloc(sizeof(BTNODE));
  n4 -> item = '9';
  BTNODE* n5 = (BTNODE*) malloc(sizeof(BTNODE));
  n5 -> item = '2';

  n1 -> left = n2;
  n1 -> right = n3;
  n2 -> left = NULL;
  n2 -> right = NULL;
  n3 -> left = n4;
  n3 -> right = n5;
  n4 -> left = NULL;
  n4 -> right = NULL;
  n5 -> left = NULL;
  n5 -> right = NULL;

  in_order(n1);
  putchar('\n');
  printf("%d\n", eval(n1));
}
