#include "types.h"

STACK_NODE *init_stack_node(STACK_NODE *sn, STACK_NODE *psn, TREE_NODE *t);

STACK_NODE *push(STACK_NODE *st_ptr, TREE_NODE *t);

STACK_NODE *pop(STACK_NODE *st_ptr);
