#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  char item[2];
  struct node *p0, *p1, *p2, *p3;
} NODE;

NODE* term(char* str, int len, int index) {
  NODE* leaf = (NODE*) malloc(sizeof(NODE));
  switch (str[index]) {
  case '0':
    leaf -> item[1] = '0';
    break;
  case '1':
    leaf -> item[1] = '1';
    break;
  case '2':
    leaf -> item[1] = '2';
    break;
  case '3':
    leaf -> item[1] = '3';
    break;
  case '4':
    leaf -> item[1] = '4';
    break;
  case '5':
    leaf -> item[1] = '5';
    break;
  case '6':
    leaf -> item[1] = '6';
    break;
  case '7':
    leaf -> item[1] = '7';
    break;
  case '8':
    leaf -> item[1] = '8';
    break;
  case '9':
    leaf -> item[1] = '9';
    break;
  }

  leaf -> item[0] = 'P';
  leaf -> p0 = NULL;
  leaf -> p1 = NULL;
  leaf -> p2 = NULL;
  leaf -> p3 = NULL;
  return leaf;
}

NODE* rest(char* str, int len, int index) {
  if (index >= len) {
    return NULL;
  }
  NODE* c0 = (NODE*) malloc(sizeof(NODE));
  NODE* c2 = (NODE*) malloc(sizeof(NODE));
  if (str[index] == '+') {
    c0 -> item[0] = '+';
    c2 -> item[0] = 'P';
    c2 -> item[1] = '+';
  }
  else if (str[index] == '-') {
    c0 -> item[0] = '-';
    c2 -> item[0] = 'P';
    c2 -> item[1] = '-';
  }
  c0 -> p0 = NULL;
  c0 -> p1 = NULL;
  c0 -> p2 = NULL;
  c0 -> p3 = NULL;
  c2 -> p0 = NULL;
  c2 -> p1 = NULL;
  c2 -> p2 = NULL;
  c2 -> p3 = NULL;

  NODE* c1 = (NODE*) malloc(sizeof(NODE));
  c1 = term(str, len, index + 1);
  NODE* c3 = (NODE*) malloc(sizeof(NODE));
  c3 = rest(str, len, index + 1);
  NODE* root = (NODE*) malloc(sizeof(NODE));
  root -> item[0] = 'R';

  root -> p0 = c0;
  root -> p1 = c1;
  root -> p2 = c2;
  root -> p3 = c3;

  return root;
}

NODE* expr(char* str, int len, int index) {
  NODE* root = (NODE*) malloc(sizeof(NODE));
  root -> item[0] = 'E';
  root -> p0 = term(str, len, index);
  root -> p1 = rest(str, len, index + 1);
  root -> p2 = NULL;
  return root;
}

void print(NODE* tree) {
  if (!tree) {
    return;
  }
  if (tree -> item[0] == 'P') {
    putchar(tree -> item[1]);
    return;
  }
  print(tree -> p0);
  print(tree -> p1);
  print(tree -> p2);
  print(tree -> p3);
}

int main() {
  char infix_expr[] = "6-7+6-0";
  NODE* tree = expr(infix_expr, strlen(infix_expr), 0);
  print(tree);
  putchar('\n');
}
