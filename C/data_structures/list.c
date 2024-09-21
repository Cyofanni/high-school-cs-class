#include "list.h"

L_NODE* alloc_node(int key) {
  L_NODE* new_node = (L_NODE*) malloc(sizeof(L_NODE));
  new_node -> key = key;
  new_node -> next = NULL;
  return new_node;
}

L_NODE* insert_back_iter(L_NODE* n, int key) {
  L_NODE* new_node = alloc_node(key);
  if (!n) {
    return new_node;
  }
  L_NODE* it = n;
  while (it -> next) {
    it = it -> next;
  }
  it -> next = new_node;
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

int lin_search_iter(L_NODE* n, int key) {
  int key_ind = -1;
  int ind = 0;
  while (n && key_ind == -1) {
    if (n -> key == key) {
      key_ind = ind;
    }
    n = n -> next;
    ind++;
  }

  return key_ind;
}

L_NODE* node_at_ind(L_NODE* n, int index) {
  L_NODE* ret_node = NULL;
  int counter = 0;
  while (n && counter <= index) {
    if (counter == index) {
      ret_node = n;
    }
    counter++;
    n = n -> next;
  }

  return ret_node;
}

bool is_sorted(L_NODE* n) {
  if (!n && !n -> next) {
    return true;
  }
  if (n -> key > n -> next -> key) {
    return false;
  }
  return is_sorted(n -> next);
}

void bubble_sort(L_NODE* n) {
  if (n && n -> next) {
    bool sorted = false;
    L_NODE* it;
    while (sorted == false) {
      it = n;
      sorted = true;
      while (it -> next != NULL) {
	if (it -> key > it -> next -> key) {
	  sorted = false;
	  int t = it -> key;
	  it -> key = it -> next -> key;
	  it -> next -> key = t;
	}
	it = it -> next;
      }
    }
  }
}

L_NODE_D* insert_back_iter_d(L_NODE_D* n, int key) {
  if (!n) {
    L_NODE_D* new_node = (L_NODE_D*) malloc(sizeof(L_NODE_D));
    new_node -> key = key;
    new_node -> prev = NULL;
    new_node -> next = NULL;
    return new_node;
  }
  L_NODE_D* it = n;
  while (it -> next) {
    it = it -> next;
  }
  it -> next = (L_NODE_D*) malloc(sizeof(L_NODE_D));
  it -> next -> key = key;
  it -> next -> prev = it;
  return n;
}

void print_rec(L_NODE* n) {
  if (!n) {
    return;
  }
  printf("%d ", n -> key);
  print_rec(n -> next);
}
