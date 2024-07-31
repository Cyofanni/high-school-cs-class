#include "list.h"
#include "bin_tree.h"

int main() {
  T_NODE* t = NULL;
  t = bst_parent_insert_iter(t, 18);
  t = bst_parent_insert_iter(t, 15);
  t = bst_parent_insert_iter(t, 10);
  t = bst_parent_insert_iter(t, 6);
  t = bst_parent_insert_iter(t, 17);

  print_tree(t);

  t = rotate_right(t, t);

  putchar('\n');
  print_tree(t);
  putchar('\n');
}
