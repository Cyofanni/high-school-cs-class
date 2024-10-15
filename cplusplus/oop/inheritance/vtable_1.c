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
  void (*vptr[2])();
};

struct B {
  void (*vptr[2])();
};

int main(int argc, char* argv[]) {
  struct A a;
  struct B b;
  a.vptr[0] = &f_A;
  a.vptr[1] = &g_A;
  b.vptr[0] = &f_B;
  b.vptr[1] = &g_A;

  (*a.vptr[0])();
  (*a.vptr[1])();
  (*b.vptr[0])();
  (*b.vptr[1])();
}
