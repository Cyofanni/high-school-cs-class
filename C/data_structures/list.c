#include "list.h"

L_NODE* insert_back_iter(L_NODE* n, int key) {
  if (!n) {
    L_NODE* new_node = (L_NODE*) malloc(sizeof(L_NODE));
    new_node -> key = key;
    new_node -> next = NULL;
    return new_node;
  }
  L_NODE* it = n;
  while (it -> next) {
    it = it->next;
  }
  it -> next = (L_NODE*) malloc(sizeof(L_NODE));
  it -> next -> key = key;
  return n;
}

L_NODE* insert_back_rec(L_NODE* n, int key) {
  if (!n) {
    L_NODE* new_node = (L_NODE*) malloc(sizeof(L_NODE));
    new_node -> key = key;
    new_node -> next = NULL;
    return new_node;
  }
  n -> next = insert_back_rec(n -> next, key);
  return n;
}

L_NODE* insert_front(L_NODE* n, int key) {
  L_NODE* new_node = (L_NODE*) malloc(sizeof(L_NODE));
  new_node -> key = key;
  new_node -> next = n;
  return new_node;
}

L_NODE* insert_iter(L_NODE* n, int key, int pos) {
  if (!n || pos == 0) {
    return insert_front(n, key);
  }

  L_NODE* curr = n;
  L_NODE* prev = NULL;
  while (curr && pos != 0) {
    prev = curr;
    curr = curr -> next;
    pos--;
  }
  L_NODE* new_node = (L_NODE*) malloc(sizeof(L_NODE));
  new_node -> key = key;
  new_node -> next = curr;
  prev -> next = new_node;

  return n;
}

L_NODE* insert_rec(L_NODE* n, int key, int pos) {
  if (!n || !pos) {
    L_NODE* new_node = (L_NODE*) malloc(sizeof(L_NODE));
    new_node -> key = key;
    if (!n) {
      new_node -> next = NULL;
    }
    else {
      new_node -> next = n;
    }
    return new_node;
  }
  n -> next = insert_rec(n -> next, key, pos - 1);
  return n;
}

L_NODE* remove_iter(L_NODE* n, int pos) {
  if (n) {
    if (pos == 0) {
      L_NODE* new_head = n -> next;
      free(n);
      return new_head;
    }

    L_NODE* curr = n;
    L_NODE* prev = NULL;
    while (curr && pos) {
      prev = curr;
      curr = curr -> next;
      pos--;
    }
    if (curr) {
      prev -> next = curr -> next;
      free(curr);
    }
  }

  return n;
}

void print_rec(L_NODE* n) {
  if (!n) {
    return;
  }
  printf("%d ", n -> key);
  print_rec(n -> next);
}