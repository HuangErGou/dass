#include <assert.h>

#include <iostream>

template <typename T>
unsigned int count(const T* array, size_t length, T value) {
  unsigned int cnt = 0;

  for (size_t i = 0; i < length; i++) {
    if (array[i] == value) cnt++;
  }
  return cnt;
}

void test_cnt_int() {
  int array[100] = {1, 2, 2, 3, 3, 3, 4, 5, 6};

  assert(count(array, sizeof(array) / sizeof(array[0]), 1) == 1);
  assert(count(array, sizeof(array) / sizeof(array[0]), 2) == 2);
  assert(count(array, sizeof(array) / sizeof(array[0]), 3) == 3);
  assert(count(array, sizeof(array) / sizeof(array[0]), 4) == 1);
  assert(count(array, sizeof(array) / sizeof(array[0]), 5) == 1);
  assert(count(array, sizeof(array) / sizeof(array[0]), 6) == 1);
  assert(count(array, sizeof(array) / sizeof(array[0]), 7) == 0);
}

int main(int argc, char* argv[]) {
  test_cnt_int();
  return 0;
}