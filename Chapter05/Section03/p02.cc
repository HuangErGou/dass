#include <iostream>

template <typename T>
T** make_2D_array(size_t r, size_t c) {
  T** p = new T*[r];

  for (size_t i = 0; i < r; i++) {
    p[i] = new T[c];
  }
  return p;
}

template <typename T>
void release_2D(T**& p, size_t c) {
  for (size_t i = 0; i < c; i++) {
    delete p[i];
    p[i] = nullptr;
  }

  delete p;
  p = nullptr;
}

int main(int argc, char const* argv[]) {
  char** p = make_2D_array<char>(5, 4);
  release_2D(p, 4);
  return 0;
}
