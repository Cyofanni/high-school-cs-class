#include "list.h"
#include "queue_array.h"

int main() {
  L_NODE* l1 = NULL;
  l1 = insert_back_iter(l1, 2);
  l1 = insert_back_iter(l1, 4);
  l1 = insert_back_iter(l1, 6);
  l1 = insert_back_iter(l1, 8);
  l1 = insert_back_iter(l1, 10);
  l1 = insert_back_iter(l1, 12);
  l1 = insert_back_iter(l1, 14);

  print_rec(l1);
  putchar('\n');

  L_NODE* l2 = NULL;
  l2 = insert_back_rec(l2, 3);
  l2 = insert_back_rec(l2, 8);
  l2 = insert_back_rec(l2, 10);
  l2 = insert_back_rec(l2, 18);
  l2 = insert_back_rec(l2, 20);
  l2 = insert_back_rec(l2, 30);
  l2 = insert_back_rec(l2, 40);
  print_rec(l2);
  putchar('\n');

  L_NODE* l3 = NULL;
  l3 = insert_front(l3, 1024);
  l3 = insert_front(l3, 512);
  l3 = insert_front(l3, 256);
  l3 = insert_front(l3, 128);
  l3 = insert_front(l3, 64);
  l3 = insert_front(l3, 32);
  l3 = insert_front(l3, 16);
  print_rec(l3);
  putchar('\n');

  L_NODE* l4 = NULL;
  l4 = insert_iter(l4, 200, 0);
  l4 = insert_iter(l4, 199, 0);
  l4 = insert_iter(l4, 198, 0);
  print_rec(l4);
  putchar('\n');
  l4 = insert_iter(l4, 201, 1);
  print_rec(l4);
  putchar('\n');
  l4 = insert_iter(l4, 250, 2);
  print_rec(l4);
  putchar('\n');
  l4 = insert_iter(l4, 300, 5);
  print_rec(l4);
  putchar('\n');
  l4 = insert_iter(l4, 315, 15);
  print_rec(l4);
  putchar('\n');
  l4 = insert_iter(l4, 99, 3);
  print_rec(l4);
  putchar('\n');
  l4 = insert_iter(l4, 299, 8);
  print_rec(l4);
  putchar('\n');

  QUEUE q = {{}, 0, -1, 0};
  print(&q);
  enqueue(&q, 4);
  print(&q);
  enqueue(&q, 5);
  print(&q);
  enqueue(&q, 6);
  print(&q);
  enqueue(&q, 7);
  print(&q);
  enqueue(&q, 8);
  print(&q);
  enqueue(&q, 9);
  print(&q);
  enqueue(&q, 10);
  print(&q);
  enqueue(&q, 11);
  print(&q);
  dequeue(&q);
  print(&q);
  enqueue(&q, 12);
  print(&q);
  enqueue(&q, 13);
  print(&q);
}
