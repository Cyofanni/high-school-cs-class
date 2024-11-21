#include <iostream>
#include <cstring>
using namespace std;

class stack {
 private:
  int* ar;
  int top, capacity, size;
 public:
  stack();
  stack(int);
  ~stack();
  bool is_full() const;
  bool is_empty() const;
  int get_size() const;
  void push(int);
  int pop();
  void print() const;
};

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
}

int stack::pop() {
  if (!is_empty()) {
    int top_item = ar[top];
    top--;
    size--;
    return top_item;
  }
  else {
    return -1;
  }
}

void stack::print() const {
  for (int i = top; i >= 0; i--) {
    cout << ar[i] << endl;
    cout << "____" << endl;
  }
}

int rpn_eval(char* str) {
  int str_size = strlen(str);
  stack s(str_size);
  int res = 0;

  for (int i = 0; i < str_size; i++) {
    int op1, op2;
    if (str[i] == '+') {
      op1 = s.pop();
      op2 = s.pop();
      s.push(op1 + op2);
    }
    else if (str[i] == '*') {
      op1 = s.pop();
      op2 = s.pop();
      s.push(op1 * op2);
    }
    else {
      s.push(str[i] - '0');
    }
  }

  res = s.pop();
  return res;
}

int main() {
  char e[] = "58*96+2*+";
  cout << rpn_eval(e) << endl;
}
