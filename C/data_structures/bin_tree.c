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
  printf("%d", t -> key);
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

T_NODE* rotate_right(T_NODE* t, T_NODE* y) {
  if (!t) {
    return t;
  }

  T_NODE* x = y -> left;

  if (x) {
    y -> left = x -> right;
    x -> parent = y -> parent;
    x -> right = y;

    if (y -> parent) {
      if (y == y -> parent -> left) {
	y -> parent -> left = x;
      }
      else {
	y -> parent -> right = x;
      }
    }

    if (x -> parent == NULL) {
      return x;
    }
  }

  return t;
}

T_NODE* rotate_left(T_NODE* t, T_NODE* y) {
  if (!t) {
    return t;
  }

  T_NODE* x = y -> right;

  if (x) {
    y -> right = x -> left;
    x -> parent = y -> parent;
    x -> left = y;

    if (y -> parent) {
      if (y == y -> parent -> left) {
	y -> parent -> left = x;
      }
      else {
	y -> parent -> right = x;
      }
    }

    if (x -> parent == NULL) {
      return x;
    }
  }

  return t;
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
