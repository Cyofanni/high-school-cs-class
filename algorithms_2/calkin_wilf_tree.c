#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node {
  unsigned int num, den;
  struct tree_node *left, *right;
} TNODE;

TNODE *create_node(unsigned int n, unsigned int d) {
  TNODE *new_node = (TNODE*) malloc(sizeof(TNODE));
  new_node -> num = n;
  new_node -> den = d;
  new_node -> left = NULL;
  new_node -> right = NULL;
  return new_node;
}

//r: (1, 1)
void create_cw_tree(TNODE *r, unsigned int height) {
  if (!height) {
    return;
  }

  unsigned int sum_n_d = r -> num + r -> den;

  TNODE *root_l = create_node(r -> num, sum_n_d);
  create_cw_tree(root_l, height - 1);

  TNODE *root_r = create_node(sum_n_d, r -> den);
  create_cw_tree(root_r, height - 1);

  r -> left = root_l;
  r -> right = root_r;
}

void print_cw_tree(TNODE *r) {
  if (!r) {
    return;
  }
  printf("%u/%u", r -> num, r -> den);
  putchar('(');
  print_cw_tree(r -> left);
  putchar(',');
  print_cw_tree(r -> right);
  putchar(')');
}

int main(int argc, char *argv[]) {
  TNODE *root = create_node(1, 1);
  create_cw_tree(root, 4);

  printf("%u / %u\n", root -> num, root -> den);

  printf("%u / %u    ", root -> left -> num, root -> left -> den);
  printf("%u / %u\n", root -> right -> num, root -> right -> den);

  printf("%u / %u    ", root -> left -> left -> num, root -> left -> left -> den);
  printf("%u / %u    ", root -> left -> right -> num, root -> left -> right -> den);
  printf("%u / %u    ", root -> right -> left -> num, root -> right -> left -> den);
  printf("%u / %u\n", root -> right -> right -> num, root -> right -> right -> den);

  printf("%u / %u    ", root -> left -> left -> left -> num,
                        root -> left -> left -> left -> den);
  printf("%u / %u    ", root -> left -> left -> right -> num,
                        root -> left -> left -> right -> den);
  printf("%u / %u    ", root -> left -> right -> left -> num,
                        root -> left -> right -> left -> den);
  printf("%u / %u    ", root -> left -> right -> right -> num,
                        root -> left -> right -> right -> den);
  printf("%u / %u    ", root -> right -> left -> left -> num,
                        root -> right -> left -> left -> den);
  printf("%u / %u    ", root -> right -> left -> right -> num,
                        root -> right -> left -> right -> den);
  printf("%u / %u    ", root -> right -> right -> left -> num,
                        root -> right -> right -> left -> den);
  printf("%u / %u\n\n", root -> right -> right -> right -> num,
                        root -> right -> right -> right -> den);

  print_cw_tree(root);
  putchar('\n');
}
