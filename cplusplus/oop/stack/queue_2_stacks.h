#include "stack.h"

class q_2_s {
  private:
    int capacity;
    stack s1, s2;
  public:
    q_2_s(int);
    void enqueue(int);
    void dequeue();
    void print() const;
};
