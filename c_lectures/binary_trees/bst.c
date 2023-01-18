#include <stdio.h>
#include <stdlib.h>

#define BASE_TREE_LEVEL 0

typedef enum bool {FALSE, TRUE} BOOL;

typedef struct tree_node {
  int key;
  struct tree_node *left, *right, *parent;
  BOOL visited_left, visited_right;
  unsigned int level;
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
    new_stack_pointer = init_stack_node(st_ptr, NULL, t);
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

QUEUE_NODE *init_queue_node(QUEUE_NODE *sn, TREE_NODE *t) {
    sn = (QUEUE_NODE*) malloc(sizeof(QUEUE_NODE));
    sn->t = t;
    sn->next = NULL;

    return sn;
}

QUEUE_NODE *enqueue(QUEUE_NODE *tail, TREE_NODE *t) {
  QUEUE_NODE *new_tail_ptr = NULL;
  new_tail_ptr = init_queue_node(tail, t);

  if (tail) {
    tail->next = new_tail_ptr;
  }

  return new_tail_ptr;
}

QUEUE_NODE *dequeue(QUEUE_NODE *head) {
  if (head) {
    QUEUE_NODE *new_head_ptr = NULL;
    new_head_ptr = head->next;
    free(head);
    return new_head_ptr;
  }
  else {
    return NULL;
  }
}

TREE_NODE *bst_insert_rec(TREE_NODE *node, int k, unsigned level) {
  if (!node) {
    TREE_NODE *new_node = (TREE_NODE*) malloc(sizeof(TREE_NODE));
    new_node->key = k;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->visited_left = FALSE;
    new_node->visited_right = FALSE;
    new_node->level = level;
    return new_node;
  }
  else if (k <= node->key) {
    level++;
    node->left = bst_insert_rec(node->left, k, level);
  }
  else {
    level++;
    node->right = bst_insert_rec(node->right, k, level);
  }

  return node;
}

TREE_NODE *bst_insert_rec_p(TREE_NODE *node, TREE_NODE *p_node, int k, unsigned level) {
  if (!node) {
    TREE_NODE *new_node = (TREE_NODE*) malloc(sizeof(TREE_NODE));
    new_node->key = k;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->parent = p_node;
    new_node->visited_left = FALSE;
    new_node->visited_right = FALSE;
    new_node->level = level;
    return new_node;
  }
  else if (k <= node->key) {
    node->left = bst_insert_rec_p(node->left, node, k, level + 1);
  }
  else {
    node->right = bst_insert_rec_p(node->right, node, k, level + 1);
  }

  return node;
}

TREE_NODE *bst_insert_iterative(TREE_NODE *t, int key, unsigned int level) {
  TREE_NODE *current_pointer = t;  //tree iterator
  TREE_NODE *parent_pointer = NULL;
  BOOL last_left = FALSE;  //TRUE if went left in last iteration

  while (current_pointer) {
    parent_pointer = current_pointer;
    if (key <= current_pointer->key) {
      current_pointer = current_pointer->left;
      last_left = TRUE;
    }
    else {
      current_pointer = current_pointer->right;
      last_left = FALSE;
    }
    level++;
  }

  TREE_NODE *new_node = (TREE_NODE*) malloc(sizeof(TREE_NODE));
  new_node->key = key;
  new_node->left = NULL;
  new_node->right = NULL;
  new_node->visited_left = FALSE;
  new_node->visited_right = FALSE;
  new_node->level = level;

  if (parent_pointer) {
    if (last_left) {
      parent_pointer->left = new_node;
    }
    else {
      parent_pointer->right = new_node;
    }
    return t;
  }

  return new_node;
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
      printf("[%d ", stack_pointer->t->key);
      printf("*%d] ", stack_pointer->t->level);
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

void print_n_chars(int n, char c) {
  unsigned i;
  for (i = 1; i <= n; i++) {
    putchar(c);
  }
}

void breadth_first_search(TREE_NODE *t) {
  if (t) {
    QUEUE_NODE *q_head = NULL, *q_tail = NULL;
    q_tail = enqueue(q_tail, t);
    q_head = q_tail;
    printf("%d\n", q_head->t->key);
    unsigned current_level = q_head->t->level;
    unsigned old_level;

    while (q_head) {
      unsigned old_level = current_level;
      unsigned star_counter;
      current_level = q_head->t->level;
      //if level changed, print newline
      if (current_level != old_level) {
        putchar('\n');
      }
      if (q_head->t->left) {
        //n stars means level n
        print_n_chars(q_head->t->left->level, '*');
        printf("%d ", q_head->t->left->key);
        q_tail = enqueue(q_tail, q_head->t->left);
      }
      if (q_head->t->right) {
        //n stars means level n
        print_n_chars(q_head->t->right->level, '*');
        printf("%d ", q_head->t->right->key);
        q_tail = enqueue(q_tail, q_head->t->right);
      }
      q_head = dequeue(q_head);
    }
  }
}

TREE_NODE *search_bst_recursive(TREE_NODE *t, int k) {
  if (!t){
    return NULL;
  }
  if (k == t->key) {
    return t;
  }
  if (k < t->key) {
    return search_bst_recursive(t->left, k);
  }
  return search_bst_recursive(t->right, k);
}

TREE_NODE *search_bst_iterative(TREE_NODE *t, int k) {
  TREE_NODE *p = t;
  BOOL found_key = FALSE;
  while (p && !found_key) {
    if (k == p->key) {
      found_key = TRUE;
    }
    else if (k < p->key) {
      p = p->left;
    }
    else {
      p = p->right;
    }
  }

  return p;
}

TREE_NODE *bst_minimum_recursive(TREE_NODE *t) {
  if (t) {
    if (!t->left) {
      return t;
    }
    return bst_minimum_recursive(t->left);
  }
  else {
    return NULL;
  }
}

TREE_NODE *bst_minimum_iterative(TREE_NODE *t) {
  TREE_NODE *p = t;
  while (p && p->left) {
    p = p->left;
  }

  return p;
}

TREE_NODE *bst_maximum_recursive(TREE_NODE *t) {
  if (t) {
    if (!t->right) {
      return t;
    }
    return bst_maximum_recursive(t->right);
  }
  else {
    return NULL;
  }
}

TREE_NODE *bst_maximum_iterative(TREE_NODE *t) {
  TREE_NODE *p = t;
  while (p && p->right) {
    p = p->right;
  }

  return p;
}

TREE_NODE *bst_successor(TREE_NODE *t) {
  if (t) {
    if (t->right) {
      return bst_minimum_iterative(t->right);
    }
    TREE_NODE *iter = t->parent;
    while (iter && t == iter->right) {
      t = iter;
      iter = iter->parent;
    }
    return iter;
  }

  return NULL;
}

int main() {
  //bst with initialized parent pointers
  TREE_NODE *t_p = NULL;
  t_p = bst_insert_rec_p(t_p, NULL, 12, BASE_TREE_LEVEL);
  t_p = bst_insert_rec_p(t_p, NULL, 16, BASE_TREE_LEVEL);
  t_p = bst_insert_rec_p(t_p, NULL, 8, BASE_TREE_LEVEL);
  t_p = bst_insert_rec_p(t_p, NULL, 4, BASE_TREE_LEVEL);
  t_p = bst_insert_rec_p(t_p, NULL, 10, BASE_TREE_LEVEL);
  t_p = bst_insert_rec_p(t_p, NULL, 15, BASE_TREE_LEVEL);
  t_p = bst_insert_rec_p(t_p, NULL, 20, BASE_TREE_LEVEL);

  TREE_NODE *s = bst_successor(t_p->right->right);
  if (s) {
    printf("%d\n\n\n", s->key);
  }

  //bst with initialized parent pointers
  TREE_NODE *t_1 = NULL;
  t_1 = bst_insert_rec(t_1, 12, BASE_TREE_LEVEL);
  t_1 = bst_insert_rec(t_1, 16, BASE_TREE_LEVEL);
  t_1 = bst_insert_rec(t_1, 8, BASE_TREE_LEVEL);
  t_1 = bst_insert_rec(t_1, 4, BASE_TREE_LEVEL);
  t_1 = bst_insert_rec(t_1, 10, BASE_TREE_LEVEL);
  t_1 = bst_insert_rec(t_1, 15, BASE_TREE_LEVEL);
  t_1 = bst_insert_rec(t_1, 20, BASE_TREE_LEVEL);

  puts("breadth first search on BST built iteratively:");
  breadth_first_search(t_1);
  puts("\n");

  puts("in order, recursive and iterative:");
  in_order(t_p);
  puts("\n");
  in_order_iter(t_p);
  puts("\n");

  set_visited_false(t_p);

  puts("pre order, recursive and iterative:");
  pre_order(t_p);
  puts("\n");
  pre_order_iter(t_p);
  puts("\n");

  set_visited_false(t_p);

  puts("post order, recursive and iterative:");
  post_order(t_p);
  puts("\n");
  post_order_iter(t_p);
  fputs("\n", stdout);

  return 0;
}
