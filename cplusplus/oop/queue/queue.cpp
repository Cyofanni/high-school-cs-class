#include "queue.h"
#include <iostream>
using namespace std;

queue::queue(int cap) {
  capacity = cap;
  ar = new int[capacity];
  size = 0;
  head = 0;
  tail = -1;
}

queue::~queue() {
  delete[] ar;
}

bool queue::is_full() {
  return size == capacity;
}

bool queue::is_empty() {
  return size == 0;
}

void queue::enqueue(int item) {
  if (!is_full()) {
    tail = (tail + 1) % capacity;
    ar[tail] = item;
    size++;
  }
  else {
    throw queue_full_exception();
  }
}

void queue::dequeue() {
  if (!is_empty()) {
    head = (head + 1) % capacity;
    size--;
  }
  else {
    throw queue_empty_exception();
  }
}

void queue::print() {
  if (head <= tail) {
    for (int i = head; i <= tail; i++) {
      cout << ar[i] << '\t';
    }
  }
  else {
    for (int i = head; i <= capacity -1; i++) {
      cout << ar[i] << '\t';
    }
    for (int i = 0; i <= tail; i++) {
      cout << ar[i] << '\t';
    }
  }

  cout << endl;
}
