#include "queue.h"

int main(int argc, char* argv[]) {
  queue q1(8);
  q1.enqueue(10);
  q1.enqueue(9);
  q1.enqueue(5);
  q1.enqueue(1);
  q1.enqueue(2);
  q1.enqueue(8);
  q1.enqueue(1);
  q1.enqueue(2);
  q1.print();

  q1.dequeue();
  q1.dequeue();
  q1.print();
  q1.enqueue(60);
  q1.enqueue(70);
  q1.print();

  q1.dequeue();
  q1.dequeue();
  q1.dequeue();
  q1.dequeue();
  q1.dequeue();
  q1.dequeue();
  q1.print();

  q1.enqueue(10);
  q1.enqueue(11);
  q1.enqueue(12);
  q1.enqueue(13);
  q1.print();
}
