#include "stack.h"
#include <iostream>
using namespace std;

stack::stack() {
}

stack::stack(int cap) {
  capacity = cap;
  size = 0;
  ar = new int[capacity];
  top = -1;
}

stack::~stack() {
  delete[] ar;
}

bool stack::is_full() const {
  return top == capacity - 1;
}

bool stack::is_empty() const {
  return top == -1;
}

int stack::get_size() const {
  return size;
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

int stack::pop() {
  if (!is_empty()) {
    int top_item = ar[top];
    top--;
    size--;
    return top_item;
  }
  else {
    throw stack_empty_exception();
  }
}

void stack::print() const {
  for (int i = top; i >= 0; i--) {
    cout << ar[i] << endl;
    cout << "____" << endl;
  }
}
