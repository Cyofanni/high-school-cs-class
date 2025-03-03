#include "bin_tree.h"

T_NODE* bst_insert_iter(T_NODE* t, int key) {
  T_NODE* it = t;
  T_NODE* parent = NULL;
  bool last_left;

  while (it) {
    parent = it;
    if (key > it -> key) {
      it = it -> right;
      last_left = false;
    }
    else {
      it = it -> left;
      last_left = true;
    }
  }

  T_NODE* new_node = (T_NODE*) malloc(sizeof(T_NODE));
  new_node -> key = key;
  new_node -> left = NULL;
  new_node -> right = NULL;

  if (!parent) {
    return new_node;
  }

  if (last_left) {
    parent -> left = new_node;
  }
  else {
    parent -> right = new_node;
  }

  return t;
}

T_NODE* bst_insert_rec(T_NODE* t, int key) {
  if (!t) {
    T_NODE* new_node = (T_NODE*) malloc(sizeof(T_NODE));
    new_node -> key = key;
    new_node -> left = NULL;
    new_node -> right = NULL;
    return new_node;
  }
  if (key <= t -> key) {
    t -> left = bst_insert_rec(t -> left, key);
  }
  else {
    t -> right = bst_insert_rec(t -> right, key);
  }

  return t;
}

T_NODE* bst_parent_insert_iter(T_NODE* t, int key) {
  T_NODE* new_node = (T_NODE*) malloc(sizeof(T_NODE));
  new_node -> key = key;
  new_node -> left = NULL;
  new_node -> right = NULL;
  new_node -> parent = NULL;

  T_NODE* root = t;
  T_NODE* p = NULL;
  bool left;
  while (t) {
    p = t;
    if (key <= t -> key) {
      t = t -> left;
      left = true;
    }
    else {
      t = t -> right;
      left = false;
    }
  }

  if (!root) {
    return new_node;
  }

  if (left) {
    p -> left = new_node;
  }
  else {
    p -> right = new_node;
  }
  new_node -> parent = p;

  return root;
}

void print_tree(T_NODE* t) {
  if (!t) {
    putchar('_');
    return;
  }
  printf("%d:%p", t -> key, t);
  putchar('(');
  print_tree(t -> left);
  putchar(',');
  print_tree(t -> right);
  putchar(')');
}

int height(T_NODE* t) {
  if (!t || (!t -> left && !t -> right)) {
    return 0;
  }
  int l_h = height(t -> left);
  int r_h = height(t -> right);
  if (l_h >= r_h) {
    return l_h + 1;
  }
  return r_h + 1;
}

int sum_keys(T_NODE* t) {
  if (!t) {
    return 0;
  }
  return t -> key + sum_keys(t -> left) + sum_keys(t -> right);
}

int count_nodes(T_NODE* t) {
  if (!t){
    return 0;
  }
  return 1 + count_nodes(t -> left) + count_nodes(t -> right);
}

T_NODE* minimum_rec(T_NODE* t) {
  if (!t) {
    return NULL;
  }
  if (!t -> left) {
    return t;
  }
  return minimum_rec(t -> left);
}

T_NODE* maximum_rec(T_NODE* t) {
  if (!t) {
    return NULL;
  }
  if (!t -> right) {
    return t;
  }
  return maximum_rec(t -> right);
}

T_NODE* minimum_iter(T_NODE* t) {
  while (t && t -> left) {
    t = t -> left;
  }

  return t;
}

T_NODE* maximum_iter(T_NODE* t) {
  while (t && t -> right) {
    t = t -> right;
  }

  return t;
}

T_NODE* successor(T_NODE* t, T_NODE* z) {
  if (!z) {
    return NULL;
  }
  if (z -> right) {
    return minimum_rec(z -> right);
  }

  while (z -> parent && z == z -> parent -> right) {
    z = z -> parent;
  }

  return z -> parent;
}

T_NODE* delete_node(T_NODE* t, T_NODE* z) {
  if (!z -> left && !z -> right) {
    if (z -> parent) {
      if (z == z -> parent -> left) {
	z -> parent -> left = NULL;
      }
      else if (z == z -> parent -> right) {
	z -> parent -> right = NULL;
      }
      free(z);
    }
    else if (!z -> parent) {
      free(z);
      return NULL;
    }
  }
  else if (z -> left && !z -> right) {
    if (z -> parent) {
      z -> parent -> left = z -> left;
      free(z);
    }
    else {
      T_NODE* new_root = z -> left;
      free(z);
      return new_root;
    }
  }
  else if (z -> right && !z -> left) {
    if (z -> parent) {
      z -> parent -> right = z -> right;
      free(z);
    }
    else {
      T_NODE* new_root = z -> right;
      free(z);
      return new_root;
    }
  }
  else {
    T_NODE* z_succ = successor(t, z);
    z -> key = z_succ -> key;
    printf("z_succ: %d\n", z_succ -> key);
    delete_node(t, z_succ);
  }

  return t;
}

bool bst_search_rec(T_NODE* t, int key) {
  if (!t) {
    return false;
  }
  if (t -> key == key) {
    return true;
  }
  if (key < t -> key) {
    return bst_search_rec(t -> left, key);
  }
  return bst_search_rec(t -> right, key);
}

bool bst_search_iter(T_NODE* t, int key) {
  bool found = false;
  while (t && !found) {
    if (t -> key == key) {
      found = true;
    }
    else if (key < t -> key) {
      t = t -> left;
    }
    else {
      t = t -> right;
    }
  }

  return found;
}

bool match(T_NODE* t1, T_NODE* t2) {
  if (!t1 && !t2) {
    return true;
  }
  if ((!t1 && t2) || (t1 && !t2)) {
    return false;
  }
  if (t1 -> key != t2 -> key) {
    return false;
  }
  return match(t1 -> left, t2 -> left) &&
         match(t1 -> right, t2 -> right);
}

int max_bin_tree(T_NODE* t, int max) {
  if (!t) {
    return max;
  }
  if (t -> key > max) {
    max = t -> key;
  }
  int max_left = max_bin_tree(t -> left, max);
  int max_right = max_bin_tree(t -> right, max);
  return max_left >= max_right ? max_left : max_right;
}

int max_bin_tree_alt(T_NODE* t) {
  if (!t) {
    return INT_MIN;
  }
  if (!t -> left && !t -> right) {
    return t -> key;
  }
  int max = t -> key;
  int max_left = max_bin_tree_alt(t -> left);
  if (max_left > max) {
    max = max_left;
  }
  int max_right = max_bin_tree_alt(t -> right);
  if (max_right > max) {
    max = max_right;
  }
  return max;
}

int min_bin_tree(T_NODE* t, int min) {
  if (!t) {
    return min;
  }
  if (t -> key < min) {
    min = t -> key;
  }
  int min_left = min_bin_tree(t -> left, min);
  int min_right = min_bin_tree(t -> right, min);
  return min_left <= min_right ? min_left : min_right;
}

bool verify_bst(T_NODE* t) {
  if (!t) {
    return true;
  }
  int max_left = max_bin_tree(t -> left, INT_MIN);
  int min_right = min_bin_tree(t -> right, INT_MAX);
  if (t -> key < max_left || t -> key >= min_right) {
    return false;
  }
  return verify_bst(t -> left) && verify_bst(t -> right);
}

void set_heights_1(T_NODE* t) {
  if (!t) {
    return;
  }
  t -> height = height(t);
  set_heights_1(t -> left);
  set_heights_1(t -> right);
}

void set_heights_2(T_NODE* t) {
  if (!t) {
    return;
  }
  if (!t -> left && !t -> right) {
    t -> height = 0;
    return;
  }
  set_heights_2(t -> left);
  set_heights_2(t -> right);
  int hl = 0, hr = 0;
  if (t -> left) {
    hl = t -> left -> height;
  }
  if (t -> right) {
    hr = t -> right -> height;
  }
  t -> height = hl >= hr ? hl + 1 : hr + 1;
}

void set_sizes(T_NODE* t) {
  if (!t) {
    return;
  }
  if (!t -> left && !t -> right) {
    t -> size = 1;
    return;
  }
  set_sizes(t -> left);
  set_sizes(t -> right);
  int sz_l = 0, sz_r = 0;
  if (t -> left) {
    sz_l = t -> left -> size;
  }
  if (t -> right) {
    sz_r = t -> right -> size;
  }
  t -> size = sz_l + sz_r + 1;
}

T_NODE* rotate_left(T_NODE* t, T_NODE* y) {
  if (!t) {
    return NULL;
  }
  if (!y) {
    return t;
  }
  if (!y -> parent) {
    return t;
  }
  if (y == y -> parent -> left) {
    return t;
  }

  bool is_left_subtree;
  T_NODE* x = y -> parent;

  if (x -> parent && x == x -> parent -> left) {
    is_left_subtree = true;
  }
  else {
    is_left_subtree = false;
  }

  y -> parent = x -> parent;
  T_NODE* beta = y -> left;
  y -> left = x;
  x -> parent = y;

  if (y -> parent) {
    if (is_left_subtree) {
      y -> parent -> left = y;
    }
    else {
      y -> parent -> right = y;
    }
  }
  x -> right = beta;
  if (beta) {
    beta -> parent = x;
  }

  if (!y -> parent) {
    return y;
  }

  return t;
}

T_NODE* rotate_right(T_NODE* t, T_NODE* y) {
  if (!t) {
    return NULL;
  }
  if (!y) {
    return t;
  }
  if (!y -> parent) {
    return t;
  }
  if (y == y -> parent -> right) {
    return t;
  }

  bool is_left_subtree;
  T_NODE* x = y -> parent;

  if (x -> parent && x == x -> parent -> left) {
    is_left_subtree = true;
  }
  else {
    is_left_subtree = false;
  }

  y -> parent = x -> parent;
  T_NODE* beta = y -> right;
  y -> right = x;
  x -> parent = y;

  if (y -> parent) {
    if (is_left_subtree) {
      y -> parent -> left = y;
    }
    else {
      y -> parent -> right = y;
    }
  }
  x -> left = beta;
  if (beta) {
    beta -> parent = x;
  }

  if (!y -> parent) {
    return y;
  }

  return t;
}

T_NODE* rotate_left_1(T_NODE* t, T_NODE* y) {
  //if either t or y are NULL, return t
  if (!t || !y) {
    return t;
  }
  //if pivot is root, do nothing
  if (y == t) {
    return t;
  }
  //if pivot is left child of its parent, do nothing
  if (y == y -> parent -> left) {
    return t;
  }

  //x is parent of y
  T_NODE* x = y -> parent;
  //xp is parent of x and grandparent of y
  T_NODE* xp = x -> parent;
  //beta is left child of y
  T_NODE* beta = y -> left;

  bool is_x_left_child = false;

  if (xp && x == xp -> left) {
    is_x_left_child = true;
  }
  else if (xp && x == xp -> right) {
    is_x_left_child = false;
  }

  y -> parent = xp;
  if (xp && is_x_left_child == true) {
    xp -> left = y;
  }
  else if (xp && is_x_left_child == false) {
    xp -> right = y;
  }

  y -> left = x;
  x -> parent = y;

  x -> right = beta;

  if (beta) {
    beta -> parent = x;
  }

  if (!xp) {
    return y;
  }

  return t;
}

T_NODE* deep_copy_tree(T_NODE* t) {
  if (!t) {
    return NULL;
  }
  T_NODE* t_copy = (T_NODE*) malloc(sizeof(T_NODE));
  t_copy -> key = t -> key;
  t_copy -> left = deep_copy_tree(t -> left);
  t_copy -> right = deep_copy_tree(t -> right);

  return t_copy;
}
