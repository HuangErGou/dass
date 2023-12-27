#include <iostream>
#include <iterator>
#include <ostream>

template <typename T>
void permutations(T *list, size_t k, size_t m) {
  if (k == m) {
    std::copy(list, list + m + 1, std::ostream_iterator<T>(std::cout, " "));
    std::cout << std::endl;
  } else {
    for (size_t i = k; i <= m; i++) {
      std::swap(list[k], list[i]);
      permutations(list, k + 1, m);
      std::swap(list[k], list[i]);
    }
  }
}

int main(int argc, char const *argv[]) {
  char a[] = {'a', 'b', 'c'};

  permutations(a, 0, 2);
  return 0;
}
