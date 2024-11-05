#include "queue_2_stacks.h"

q_2_s::q_2_s(int capacity): capacity(capacity), s1(capacity), s2(capacity) {
}

void q_2_s::enqueue(int item) {
  s1.push(item);
}

void q_2_s::dequeue() {
  int s1_size = s1.get_size();
  for (int i = 0; i < s1_size; i++) {
    int popped_item = s1.pop();
    s2.push(popped_item);
  }
  s2.pop();

  int s2_size = s2.get_size();
  for (int i = 0; i < s2_size; i++) {
    int popped_item = s2.pop();
    s1.push(popped_item);
  }
}

void q_2_s::print() const {
  s1.print();
}
