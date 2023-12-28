#include <iostream>
#include <iterator>
#include <ostream>

template <typename T>
void sub_generation(T *array, size_t n, int index, std::ostream &os) {
  if (index > n - 1) {
    os << std::endl;
    return;
  }

  for (size_t i = 0; i < n - index; i++) {
    std::copy(array + index, array + index + i + 1,
              std::ostream_iterator<T>(os, " "));
    os << std::endl;
  }
  sub_generation(array, n, index + 1, os);
}

int main(int argc, char const *argv[]) {
  int array[] = {1, 2, 3, 5};
  sub_generation(array, sizeof(array) / sizeof(array[0]), 0, std::cout);
  return 0;
}
