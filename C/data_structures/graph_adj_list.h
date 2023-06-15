#include "list.h"

#define V 12   //max number of vertices

typedef struct graph_adj_list {
  L_NODE* adj_lists_array[V];
} GRAPH;

void init_graph(GRAPH* g);
