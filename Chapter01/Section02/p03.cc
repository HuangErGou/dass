#include <assert.h>

#include <iostream>

template <typename T>
void fill(T* a, T value, size_t start, size_t end) {
  for (size_t i = start; i < end; i++) {
    a[i] = value;
  }
}

void test_fill() {
  int a[10];

  fill(a, 1, 0, 1);
  assert(a[0] == 1);

  fill(a, 2, 1, 3);
  assert(a[1] == 2 && a[2] == 2);

  fill(a, 3, 4, 6);
  assert(a[4] == 3 && a[4] == 3 && a[5] == 3);
}

int main(int argc, char* argv[]) {
  test_fill();
  return 0;
}