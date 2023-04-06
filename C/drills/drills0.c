/* create the type for a graph node
   each graph points to 3 successor
   nodes at most.
   see what happens with a tree-like dfs
   visit.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct graph_node {
  int key;
  struct graph_node *p1, *p2, *p3;
} GRAPH_NODE;

void dfs(GRAPH_NODE *g) {
  if (!g) {
    return;
  }
  printf("%d\t", g->key);
  dfs(g->p1);
  dfs(g->p2);
  dfs(g->p3);
}

int main() {
  GRAPH_NODE *node1 = (GRAPH_NODE*) malloc(sizeof(GRAPH_NODE));
  node1->key = 5;

  GRAPH_NODE *node2 = (GRAPH_NODE*) malloc(sizeof(GRAPH_NODE));
  node2->key = 1;

  GRAPH_NODE *node5 = (GRAPH_NODE*) malloc(sizeof(GRAPH_NODE));
  node5->key = 18;

  node2->p1 = node5;

  GRAPH_NODE *node3 = (GRAPH_NODE*) malloc(sizeof(GRAPH_NODE));
  node3->key = 6;

  GRAPH_NODE *node4 = (GRAPH_NODE*) malloc(sizeof(GRAPH_NODE));
  node4->key = 9;

  node1->p1 = node2;
  node1->p2 = node3;
  node1->p3 = node4;

  node5->p1 = node1;

  dfs(node1);
  putchar('\n');
}
