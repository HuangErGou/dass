#include <assert.h>

#include <iostream>

template <typename T>
T innter_product(const T* a, const T* b, size_t len) {
  T result = 0;

  for (size_t i = 0; i < len; i++) {
    result = result + a[i] * b[i];
  }
  return result;
}

void test_innter_product() {
  int a[] = {1, 2, 3}, b[] = {4, 5, 6};
  assert(innter_product(a, b, sizeof(a) / sizeof(a[0])) ==
         a[0] * b[0] + a[1] * b[1] + a[2] * b[2]);
}

int main(int argc, char const* argv[]) {
  test_innter_product();
  return 0;
}
