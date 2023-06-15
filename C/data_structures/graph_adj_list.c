#include "graph_adj_list.h"

void init_graph(GRAPH* g) {
  L_NODE* v1 = (L_NODE*) malloc(sizeof(L_NODE));
  v1 -> key = 1;
  L_NODE* v2 = (L_NODE*) malloc(sizeof(L_NODE));
  v2 -> key = 2;
  L_NODE* v3 = (L_NODE*) malloc(sizeof(L_NODE));
  v3 -> key = 3;
  L_NODE* v4 = (L_NODE*) malloc(sizeof(L_NODE));
  v4 -> key = 4;
  L_NODE* v5 = (L_NODE*) malloc(sizeof(L_NODE));
  v5 -> key = 5;

  g -> adj_lists_array[0] = v1;
  g -> adj_lists_array[0] = insert_back_iter(g -> adj_lists_array[0], 2);
  g -> adj_lists_array[0] = insert_back_iter(g -> adj_lists_array[0], 5);

  g -> adj_lists_array[1] = v2;
  g -> adj_lists_array[1] = insert_back_iter(g -> adj_lists_array[1], 1);
  g -> adj_lists_array[1] = insert_back_iter(g -> adj_lists_array[1], 5);
  g -> adj_lists_array[1] = insert_back_iter(g -> adj_lists_array[1], 3);
  g -> adj_lists_array[1] = insert_back_iter(g -> adj_lists_array[1], 4);

  g -> adj_lists_array[2] = v3;
  g -> adj_lists_array[2] = insert_back_iter(g -> adj_lists_array[2], 2);
  g -> adj_lists_array[2] = insert_back_iter(g -> adj_lists_array[2], 4);

  g -> adj_lists_array[3] = v4;
  g -> adj_lists_array[3] = insert_back_iter(g -> adj_lists_array[3], 2);
  g -> adj_lists_array[3] = insert_back_iter(g -> adj_lists_array[3], 5);
  g -> adj_lists_array[3] = insert_back_iter(g -> adj_lists_array[3], 3);

  g -> adj_lists_array[4] = v5;
  g -> adj_lists_array[4] = insert_back_iter(g -> adj_lists_array[4], 4);
  g -> adj_lists_array[4] = insert_back_iter(g -> adj_lists_array[4], 1);
  g -> adj_lists_array[4] = insert_back_iter(g -> adj_lists_array[4], 2);

  for (int i = 0; i < 5; i++) {
    print_rec(g -> adj_lists_array[i]);
    putchar('\n');
  }
}
