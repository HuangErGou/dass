#include <assert.h>

#include <iostream>

template <typename T>
bool is_exist(T* array, size_t index, T v) {
  if (nullptr == array) return false;

  if (0 == index) return array[0] == v;

  if (array[index] == v) return true;
  return is_exist(array, index - 1, v);
}

int main(int argc, char const* argv[]) {
  int array1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  size_t array_len = sizeof(array1) / sizeof(array1[0]);

  assert(is_exist(array1, array_len, 6) == true);
  assert(is_exist(array1, array_len, 11) == false);
  return 0;
}
