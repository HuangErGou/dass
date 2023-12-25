#include <assert.h>

#include <iostream>

template <typename T>
bool make_2d_array(T**& x, size_t row_number, size_t* row_size) {
  try {
    x = new T*[row_number];

    for (size_t i = 0; i < row_number; i++) {
      x[i] = new T[row_size[i]];
    }
    return true;
  } catch (const std::bad_alloc& e) {
    std::cerr << e.what() << '\n';
    return false;
  }
}

template <typename T>
void release_2d_array(T**& x, size_t row_number) {
  for (size_t i = 0; i < row_number; i++) {
    delete[] x[i];
    x[i] = nullptr;
  }

  delete[] x;
  x = nullptr;
}

void test_2d_array() {
  int** x;
  size_t row_size[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  assert(make_2d_array(x, 10, row_size) == true);
  release_2d_array(x, 10);
  assert(x == nullptr);
}

int main(int argc, char* argv[]) {
  test_2d_array();
  return 0;
}