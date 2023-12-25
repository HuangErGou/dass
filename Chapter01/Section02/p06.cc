#include <assert.h>

#include <iostream>

template <typename T>
bool is_sorted(const T* a, size_t n) {
  if (a == nullptr) return false;

  bool sorted = true;

  T last_value = a[0];
  for (size_t i = 0; i < n; i++) {
    if (last_value > a[i]) {
      sorted = false;
      break;
    }
  }
  return sorted;
}

void test_sorted() {
  int a1[] = {1, 3, 5, 6, 6, 7, 7, 89, 100, 1000, 12345, 22135};
  char a2[] = {1, 3, 5, 6, 6, 7, 7, 89, 100, 0, 1, 4};

  assert(is_sorted(a1, sizeof(a1) / sizeof(a1[0])) == true);
  assert(is_sorted(a2, sizeof(a2) / sizeof(a2[0])) == false);
}

int main(int argc, char const* argv[]) {
  test_sorted();
  return 0;
}
