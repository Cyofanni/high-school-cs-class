#include "list.h"
#include "bin_tree.h"

int main() {
  L_NODE* l = NULL;
  for (int i = 20; i >= 0; i -= 2) {
    l = insert_back_iter(l, i);
  }
  print_rec(l);
  putchar('\n');

  T_NODE* t = NULL;
  t = bst_parent_insert_iter(t, 11);
  t = bst_parent_insert_iter(t, 9);
  t = bst_parent_insert_iter(t, 18);
  t = bst_parent_insert_iter(t, 14);
  t = bst_parent_insert_iter(t, 19);
  t = bst_parent_insert_iter(t, 12);
  t = bst_parent_insert_iter(t, 17);
  t = bst_parent_insert_iter(t, 22);
  t = bst_parent_insert_iter(t, 20);

  print_tree(t);

  putchar('\n');
  t = rotate_left(t, t);
  print_tree(t);
  putchar('\n');
}
