#include <stdio.h>
#include <stdlib.h>

#define BASE_LEVEL 0

typedef enum bool {FALSE, TRUE} BOOL;

typedef struct tree_node {
  int key;
  struct tree_node *left, *right;
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

TREE_NODE *bst_insert(TREE_NODE *node, int k, unsigned level) {
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
    node->left = bst_insert(node->left, k, level);
  }
  else {
    level++;
    node->right = bst_insert(node->right, k, level);
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

int main() {
  TREE_NODE *t = NULL;
  unsigned int level = 0;
  t = bst_insert(t, 20, BASE_LEVEL);
  t = bst_insert(t, 10, BASE_LEVEL);
  t = bst_insert(t, 30, BASE_LEVEL);
  t = bst_insert(t, 8, BASE_LEVEL);
  t = bst_insert(t, 12, BASE_LEVEL);
  t = bst_insert(t, 25, BASE_LEVEL);
  t = bst_insert(t, 40, BASE_LEVEL);
  t = bst_insert(t, 5, BASE_LEVEL);
  t = bst_insert(t, 9, BASE_LEVEL);
  t = bst_insert(t, 38, BASE_LEVEL);
  t = bst_insert(t, 42, BASE_LEVEL);
  t = bst_insert(t, 11, BASE_LEVEL);
  t = bst_insert(t, 13, BASE_LEVEL);
  t = bst_insert(t, 23, BASE_LEVEL);
  t = bst_insert(t, 27, BASE_LEVEL);
  t = bst_insert(t, 60, BASE_LEVEL);
  
  puts("breadth first search:");
  breadth_first_search(t);
  puts("\n");
  
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
