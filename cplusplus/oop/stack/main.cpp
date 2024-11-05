#include "queue_2_stacks.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
  q_2_s q(8);
  q.enqueue(4);
  q.enqueue(8);
  q.enqueue(10);
  q.enqueue(12);
  q.enqueue(13);
  q.enqueue(15);
  q.enqueue(17);
  q.enqueue(20);
  q.enqueue(32);

  q.print();
  cout << endl << endl;
  q.dequeue();
  q.print();
  cout << endl << endl;
  q.dequeue();
  q.print();
  cout << endl << endl;
  q.dequeue();
  q.print();
  cout << endl << endl;
  q.dequeue();
  q.print();
  cout << endl << endl;
}
