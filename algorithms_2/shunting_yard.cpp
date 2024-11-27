#include <iostream>
#include <cstring>
using namespace std;

class stack {
 private:
  char* ar;
  int top, capacity, size;
 public:
  stack();
  stack(int);
  ~stack();
  bool is_full() const;
  bool is_empty() const;
  int get_size() const;
  void push(int);
  char pop();
  char peek() const;
  void print() const;
};

stack::stack(int cap) {
  capacity = cap;
  size = 0;
  ar = new char[capacity];
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

char stack::pop() {
  if (!is_empty()) {
    int top_item = ar[top];
    top--;
    size--;
    return top_item;
  }
  else {
    return '\0';
  }
}

char stack::peek() const {
  if (!is_empty()) {
    return ar[top];
  }
  return '\0';
}

void stack::print() const {
  for (int i = top; i >= 0; i--) {
    cout << ar[i] << endl;
    cout << "____" << endl;
  }
}

char* shunting_yard(char* str) {
  int str_size = strlen(str);
  stack s(str_size);
  char* str_rpn = new char[str_size];
  int k = -1;    //index of last-added item

  for (int i = 0; i < str_size; i++) {
    if (str[i] == '*') {
      s.push('*');
    }
    else if (str[i] == '+') {
      if (s.peek() == '*') {
        //empty stack
        while (s.get_size()) {
          k++;
          str_rpn[k] = s.pop();
        }
        s.push('+');
      }
      else {
        s.push('+');
      }
    }
    else {
      k++;
      str_rpn[k] = str[i];
    }
  }

  while (s.get_size()) {
    k++;
    str_rpn[k] = s.pop();
  }

  return str_rpn;
}

int main() {
  char e1[] = "A*B+C";
  char* e1_rpn = shunting_yard(e1);
  cout << e1 << '\t' << e1_rpn << endl;
  char e2[] = "A+B*C";
  char* e2_rpn = shunting_yard(e2);
  cout << e2 << '\t' << e2_rpn << endl;
  char e3[] = "5+6+9";
  char* e3_rpn = shunting_yard(e3);
  cout << e3 << '\t' << e3_rpn << endl;
}
