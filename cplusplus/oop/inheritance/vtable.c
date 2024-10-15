#include <stdio.h>

void f_A() {
  printf("A::f\n");
}

void g_A() {
  printf("A::g\n");
}

void f_B() {
  printf("B::f\n");
}

struct A {
  void (*f_ptr) ();
  void (*g_ptr) ();
};

struct B {
  void (*f_ptr) ();
  void (*g_ptr) ();
};

int main(int argc, char* argv[]) {
  struct A a;
  struct B b;
  a.f_ptr = &f_A;
  a.g_ptr = &g_A;
  b.f_ptr = &f_B;
  b.g_ptr = &g_A;
  (*(a.f_ptr))();
  (*(b.f_ptr))();
}
