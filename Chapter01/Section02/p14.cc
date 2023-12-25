#include <assert.h>

#include <iostream>

template <typename T>
void make_2d_array(T **&p, size_t row, size_t column) {
  p = new T *[row];

  for (size_t i = 0; i < column; i++) {
    p[i] = new T[column];
  }
}

template <typename T>
void delete_2d_array(T **&p, size_t row) {
  for (size_t i = 0; i < row; i++) {
    delete[] p[i];
    p[i] = nullptr;
  }

  delete[] p;
  p = nullptr;
}

template <typename T>
void change_2d_array_size(T **&p, size_t row_old, size_t column_old,
                          size_t row_new, size_t column_new) {
  size_t min_row = row_old <= row_new ? row_old : row_new;
  size_t min_column = column_old <= column_new ? column_old : column_new;

  T **p_new = new T *[row_new];
  for (size_t i = 0; i < row_new; i++) {
    p_new[i] = new T[column_new];

    if (i < min_row) {
      T *ptr = p[i];
      T *ptr_new = p_new[i];

      for (size_t j = 0; j < min_column; j++) {
        ptr_new[j] = ptr[j];
      }
    }
  }
  delete_2d_array(p, row_old);
  p = p_new;
}

void test_2d_resize() {
  int **p = nullptr;
  size_t row_cnt = 3, column_cnt = 3;

  make_2d_array(p, row_cnt, column_cnt);
  for (size_t row = 0; row < row_cnt; row++) {
    int *p_row = p[row];

    for (size_t col = 0; col < column_cnt; col++) {
      p_row[col] = row * col;
    }
  }

  size_t new_row_cnt = 100, new_column_cnt = 100;
  change_2d_array_size(p, row_cnt, column_cnt, new_row_cnt, new_column_cnt);

  for (size_t row = 0; row < row_cnt; row++) {
    for (size_t col = 0; col < column_cnt; col++) {
      assert(p[row][col] == row * col);
    }
  }

  change_2d_array_size(p, new_row_cnt, new_column_cnt, row_cnt, column_cnt);
  for (size_t row = 0; row < row_cnt; row++) {
    for (size_t col = 0; col < column_cnt; col++) {
      assert(p[row][col] == row * col);
    }
  }

  delete_2d_array(p, row_cnt);
  assert(p == nullptr);
}

int main(int argc, char const *argv[]) {
  test_2d_resize();
  return 0;
}
