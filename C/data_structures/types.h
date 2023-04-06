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
