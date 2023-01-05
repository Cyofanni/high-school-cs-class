#include <stdio.h>
#include <stdlib.h>

typedef enum bool {FALSE, TRUE} BOOL;

typedef struct tree_node {
  int key;
  struct tree_node *left, *right;
  BOOL visited_left, visited_right;
} TREE_NODE;

typedef struct stack_node {
  TREE_NODE *t;
  struct stack_node *prev, *next;
} STACK_NODE;

typedef struct queue_node {
  TREE_NODE *t;
  struct queue_node *next;
} QUEUE_NODE;

STACK_NODE *init_stack_node(STACK_NODE *sn, STACK_NODE *psn, TREE_NODE *t) {
    sn = (STACK_NODE*) malloc(sizeof(STACK_NODE));
    sn->t = t;
    sn->prev = psn;
    sn->next = NULL;

    return sn;
}

STACK_NODE *push(STACK_NODE *st_ptr, TREE_NODE *t) {
  STACK_NODE *new_stack_pointer = NULL;
  if (!st_ptr) {
    st_ptr = init_stack_node(st_ptr, NULL, t);
    new_stack_pointer = st_ptr;
  }
  else {
    st_ptr->next = init_stack_node(st_ptr->next, st_ptr, t);
    new_stack_pointer = st_ptr->next;
  }

  return new_stack_pointer;
}

STACK_NODE *pop(STACK_NODE *st_ptr) {
  STACK_NODE *new_stack_pointer = NULL;
  if (st_ptr != NULL) {
    new_stack_pointer = st_ptr->prev;
    free(st_ptr);
  }
  return new_stack_pointer;
}

TREE_NODE *bst_insert(TREE_NODE *node, int k) {
  if (!node) {
    TREE_NODE *new_node = (TREE_NODE*) malloc(sizeof(TREE_NODE));
    new_node->key = k;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->visited_left = FALSE;
    new_node->visited_right = FALSE;
    return new_node;
  }
  else if (k <= node->key) {
    node->left = bst_insert(node->left, k);
  }
  else {
    node->right = bst_insert(node->right, k);
  }

  return node;
}

void set_visited_false(TREE_NODE *node) {
  if (node == NULL) {
    return;
  }
  node->visited_left = FALSE;
  node->visited_right = FALSE;
  set_visited_false(node->left);
  set_visited_false(node->right);
}

void in_order(TREE_NODE *node) {
  if (node == NULL) {
    return;
  }
  in_order(node->left);
  printf("%d ", node->key);
  in_order(node->right);
}

void pre_order(TREE_NODE *node) {
  if (!node) {
    return;
  }
  printf("%d ", node->key);
  pre_order(node->left);
  pre_order(node->right);
}

void post_order(TREE_NODE *node) {
  if (!node) {
    return;
  }
  post_order(node->left);
  post_order(node->right);
  printf("%d ", node->key);
}

void in_order_iter(TREE_NODE *t_node) {
  STACK_NODE *stack_pointer = NULL;
  stack_pointer = push(stack_pointer, t_node);

  while (stack_pointer != NULL) {
    //either child of leaf (NULL) or visited left and right subtrees
    if (stack_pointer->t == NULL || (stack_pointer->t->visited_left
                     && stack_pointer->t->visited_right)) {
      stack_pointer = pop(stack_pointer);
    }
    else if (!stack_pointer->t->visited_left) {
      stack_pointer = push(stack_pointer, stack_pointer->t->left);
      stack_pointer->prev->t->visited_left = TRUE;
    }
    else if (!stack_pointer->t->visited_right) {
      printf("%d ", stack_pointer->t->key);
      stack_pointer = push(stack_pointer, stack_pointer->t->right);
      stack_pointer->prev->t->visited_right = TRUE;
    }
  }
}

void pre_order_iter(TREE_NODE *t_node) {
  STACK_NODE *stack_pointer = NULL;
  stack_pointer = push(stack_pointer, t_node);

  while (stack_pointer != NULL) {
    if (stack_pointer->t == NULL || (stack_pointer->t->visited_left
                     && stack_pointer->t->visited_right)) {
        stack_pointer = pop(stack_pointer);
    }
    else {
        if (!stack_pointer->t->visited_left && !stack_pointer->t->visited_right) {
            printf("%d ", stack_pointer->t->key);
            stack_pointer = push(stack_pointer, stack_pointer->t->left);
            stack_pointer->prev->t->visited_left = TRUE;
        }
        else if (!stack_pointer->t->visited_right) {
            stack_pointer = push(stack_pointer, stack_pointer->t->right);
            stack_pointer->prev->t->visited_right = TRUE;
        }
    }
  }
}

void post_order_iter(TREE_NODE *t_node) {
  STACK_NODE *stack_pointer = NULL;
  stack_pointer = push(stack_pointer, t_node);

  while (stack_pointer != NULL) {
    if (stack_pointer->t == NULL) {
      stack_pointer = pop(stack_pointer);
    }
    //not a leaf and did not visit subtrees
    else if (!stack_pointer->t->visited_left) {
      stack_pointer = push(stack_pointer, stack_pointer->t->left);
      stack_pointer->prev->t->visited_left = TRUE;
    }
    //visited left subtree and did not visit right subtree
    else if (!stack_pointer->t->visited_right) {
      stack_pointer = push(stack_pointer, stack_pointer->t->right);
      stack_pointer->prev->t->visited_right = TRUE;
    }
    //visited subtrees, print and pop
    else {
      printf("%d ", stack_pointer->t->key);
      stack_pointer = pop(stack_pointer);
    }
  }
}

int main() {
  TREE_NODE *t = NULL;
  t = bst_insert(t, 20);
  t = bst_insert(t, 10);
  t = bst_insert(t, 30);
  t = bst_insert(t, 8);
  t = bst_insert(t, 12);
  t = bst_insert(t, 25);
  t = bst_insert(t, 40);
  t = bst_insert(t, 70);
  t = bst_insert(t, 60);
  t = bst_insert(t, 4);

  STACK_NODE *st = NULL;
  st = push(st, t);

  puts("in order, recursive and iterative:");
  in_order(t);
  puts("\n");
  in_order_iter(t);
  puts("\n");

  set_visited_false(t);

  puts("pre order, recursive and iterative:");
  pre_order(t);
  puts("\n");
  pre_order_iter(t);
  puts("\n");

  set_visited_false(t);

  puts("post order, recursive and iterative:");
  post_order(t);
  puts("\n");
  post_order_iter(t);
  fputs("\n", stdout);

  return 0;
}
