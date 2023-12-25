#include <assert.h>

#include <iostream>

template <typename T>
T* iota(T* ptr, size_t len, T start_value) {
  if (ptr == nullptr) return nullptr;

  for (size_t i = 0; i < len; i++) {
    ptr[i] = start_value + i;
  }

  return ptr;
}

void test_iota() {
  int array[10];
  int start_value = 3;

  assert(iota(array, sizeof(array) / sizeof(array[0]), start_value) == array);

  for (size_t i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
    std::cout << "item " << i << " is: " << array[i] << std::endl;
    assert(array[i] == start_value + i);
  }
}

int main(int argc, char* argv[]) {
  test_iota();
  return 0;
}