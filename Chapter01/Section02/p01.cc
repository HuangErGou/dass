#include <assert.h>
#include <math.h>

#include <iostream>

template <typename T>
void swap(T& x, T& y) {
  T t = y;
  y = x;
  x = t;
}

void test_int_swap() {
  int x = 1, y = 2;

  swap(x, y);
  assert(x == 2 && y == 1);
}

#define EPSILON 0.0000001
#define Equ(a, b) (fabs((a) - (b)) < EPSILON)

void test_float_swap() {
  float x = 1.2, y = 2.1;

  swap(x, y);
  assert(Equ(x, 2.1) && Equ(y, 1.2));
}

int main(int argc, char const* argv[]) {
  test_int_swap();
  test_float_swap();
  return 0;
}
