#include <iostream>

template <typename T>
class The2DArray {
 public:
  The2DArray(size_t row, size_t col) {
    _row_capability = get_capablity(row);
    _col_capability = get_capablity(col);

    _data = new T*[_row_capability];

    for (size_t i = 0; i < _row_capability; i++) {
      _data[i] = new T[_col_capability];
    }
  }

  ~The2DArray() {
    for (size_t i = 0; i < _row_capability; i++) {
      delete _data[i];
      _data[i] = nullptr;
    }
    delete _data;
    _data = nullptr;
  }

  void resize(size_t row, size_t col) {
    if (row == 0 || col == 0) return;

    bool resize_row = false;
    bool resize_col = false;

    T** data_new = _data;
    size_t new_row_capability = _row_capability;
    size_t new_col_capability = _col_capability;

    if (row > _row_capability || row < _row_capability / 4) {
      std::cout << "row need resize" << std::endl;
      resize_row = true;
      new_row_capability = get_capablity(row);

      std::cout << "old row is:" << _row_capability << std::endl;
      std::cout << "new row is:" << get_capablity(row) << std::endl;
      data_new = new T*[get_capablity(row)];
    }

    if (col > _col_capability || col < _col_capability / 4) {
      std::cout << "col need resize" << std::endl;
      resize_col = true;
      new_col_capability = get_capablity(col);

      std::cout << "old col is:" << _col_capability << std::endl;
      std::cout << "new col is:" << new_col_capability << std::endl;
    }

    if (!resize_row && !resize_col) return;

    for (size_t i = 0; i < new_row_capability; i++) {
      if (resize_row) {
        size_t copy_len = std::min(_col_capability, new_col_capability);
        data_new[i] = new T[new_col_capability];

        if (i >= std::min(_row_capability, new_row_capability)) continue;

        for (size_t j = 0; j < copy_len; j++) {
          T t = _data[i][j];
          data_new[i][j] = t;
        }
      } else {
        T* tmp = new T[new_col_capability];

        size_t copy_len = std::min(_col_capability, new_col_capability);

        for (size_t j = 0; j < copy_len; j++) {
          tmp[j] = data_new[i][j];
        }
        delete data_new[i];
        data_new[i] = tmp;
      }
    }

    if (resize_row) {
      for (size_t i = 0; i < _row_capability; i++) {
        delete _data[i];
        _data[i] = nullptr;
      }
    }

    _data = data_new;
    _col_capability = new_col_capability;
    _row_capability = new_row_capability;
  }

 private:
  size_t get_capablity(size_t n) { return n * 2; }
  size_t capablity_down_limit(size_t n) { return n >> 1; }

 private:
  const size_t _DEFAULT_ROW_NUMBER = 10;
  const size_t _DEFAULT_COL_NUMBER = 10;

 private:
  T** _data = nullptr;
  size_t _row_capability = 0;
  size_t _col_capability = 0;
};

int main(int argc, char const* argv[]) {
  The2DArray<char>* array = new The2DArray<char>(3, 7);

  for (size_t i = 0; i < 20; i++) {
    std::cout << "row, col: 3," << i << std::endl;
    array->resize(3, i);
  }

  array->resize(20, 7);
  array->resize(200, 7);

  for (size_t i = 0; i < 20; i++) {
    std::cout << "row, col: " << i << ", " << 5 << std::endl;
    array->resize(i, 5);
  }

  delete array;
  return 0;
}
