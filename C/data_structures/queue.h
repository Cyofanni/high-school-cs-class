#include "types.h"

QUEUE_NODE *init_queue_node(QUEUE_NODE *sn, TREE_NODE *t);

QUEUE_NODE *enqueue(QUEUE_NODE *tail, TREE_NODE *t);

QUEUE_NODE *dequeue(QUEUE_NODE *head);
