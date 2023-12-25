#include <assert.h>

#include <iostream>

template <typename T>
size_t mismatch(const T* a, size_t len_a, const T* b, size_t len_b) {
  if (nullptr == a || nullptr == b) return 0;

  size_t min_count = len_a <= len_b ? len_a : len_b;

  size_t i = 0;
  for (; i < min_count; i++) {
    if (a[i] != b[i]) break;
  }
  return i;
}

void test_mismatch_all_match() {
  char a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  char b[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  size_t len_a = sizeof(a) / sizeof(a[0]);
  size_t len_b = sizeof(b) / sizeof(b[0]);

  assert(mismatch(a, len_a, b, len_b) == len_a);
}

void test_mismatch_not_match() {
  char a[10] = {1, 2, 3, 5, 6, 7, 8, 9};
  char b[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  size_t len_a = sizeof(a) / sizeof(a[0]);
  size_t len_b = sizeof(b) / sizeof(b[0]);

  assert(mismatch(a, len_a, b, len_b) == 3);
}

int main(int argc, char* argv[]) {
  test_mismatch_all_match();
  test_mismatch_not_match();
  return 0;
}