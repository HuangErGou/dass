#include <assert.h>

#include <iostream>

unsigned long factorial(unsigned long n) {
  unsigned long result = 1;

  for (unsigned long i = 2; i <= n; i++) {
    result = result * i;
  }
  return result;
}

void test_factorial() {
  assert(factorial(0) == 1);
  assert(factorial(1) == 1);
  assert(factorial(2) == 2);
  assert(factorial(3) == 3 * factorial(2));
}

int main(int argc, char const *argv[]) {
  test_factorial();
  return 0;
}
