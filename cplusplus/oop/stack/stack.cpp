#include "stack.h"
#include <iostream>
using namespace std;

stack::stack(int cap) {
  capacity = cap;
  size = 0;
  ar = new int[capacity];
  top = -1;
}

stack::~stack() {
  delete[] ar;
}

bool stack::is_full() {
  return top == capacity - 1;
}

bool stack::is_empty() {
  return top == -1;
}

void stack::push(int item) {
  if (!is_full()) {
    top++;
    ar[top] = item;
    size++;
  }
  else {
    throw stack_full_exception();
  }
}

void stack::pop() {
  if (!is_empty()) {
    top--;
    size--;
  }
  else {
    throw stack_empty_exception();
  }
}

void stack::print() {
  for (int i = top; i >= 0; i--) {
    cout << ar[i] << endl;
    cout << "____" << endl;
  }
}
