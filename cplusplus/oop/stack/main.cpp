#include "stack.h"

int main(int argc, char* argv[]) {
  stack st = stack(8);
  st.push(7);
  st.push(9);
  st.push(10);
  st.push(1);
  st.push(7);
  st.push(0);
  st.push(7);
  st.push(6);
  st.pop();
  st.pop();
  st.pop();
  st.pop();
  st.pop();
  st.pop();
  st.pop();
  st.pop();
  st.pop();

  st.print();
}
