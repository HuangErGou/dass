#include <assert.h>

#include <iostream>

template <typename T>
void change_length_1d(T *&p, size_t old_length, size_t new_length) {
  T *p_new = new T[new_length];
  size_t min_len = old_length <= new_length ? old_length : new_length;

  for (size_t i = 0; i < min_len; i++) {
    p_new[i] = p[i];
  }
  delete[] p;
  p = p_new;
}

void test_change_len_1() {
  char *p = new char[3];
  size_t count = 3;
  for (size_t i = 0; i < count; i++) {
    p[i] = i;
  }

  char *p_old = p;
  change_length_1d(p, count, 100);
  assert(p_old != p);
  for (size_t i = 0; i < count; i++) {
    assert(p[i] == i);
  }
}

void test_change_len_2() {
  char *p = new char[100];
  size_t count = 100;
  for (size_t i = 0; i < count; i++) {
    p[i] = i;
  }

  char *p_old = p;
  size_t new_count = 3;
  change_length_1d(p, count, new_count);
  assert(p_old != p);
  for (size_t i = 0; i < new_count; i++) {
    assert(p[i] == i);
  }
}

int main(int argc, char const *argv[]) {
  test_change_len_1();
  test_change_len_2();
  return 0;
}
