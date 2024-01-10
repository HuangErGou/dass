#include <iostream>
#include <iterator>
#include <ostream>
#include <vector>

template <typename T>
class Heap {
  template <typename T2>
  friend std::ostream &operator<<(std::ostream &os, const Heap<T2> &heap);

 public:
  Heap() {
    _size = 0;
    _heap.reserve(DEFAULT_HEAP_SIZE);
  }

  Heap(size_t size) {
    _size = 0;
    _heap.reserve(size);
  }

  void push(const T &element) {
    int current_node = _size++;
    while (current_node > 0 && _heap[current_node / 2] < element) {
      _heap[current_node] = _heap[current_node / 2];
      current_node /= 2;
    }

    _heap[current_node] = element;
  }

  T top() {
    if (_size == 0) throw "empty quene";

    return _heap[0];
  }

  void pop() {
    if (_size == 0) throw "empty quene";

    T last_element = _heap[_size--];
    int current_node = 0, child = 1;

    while (child <= _size) {
      if (child + 1 < _size && _heap[child] < _heap[child + 1]) child++;

      if (last_element >= _heap[child]) break;
      _heap[current_node] = _heap[child];
      current_node = child;
      child *= 2;
    }
    _heap[current_node] = last_element;
  }

 private:
  const size_t DEFAULT_HEAP_SIZE = 10;

 private:
  size_t _size;
  std::vector<T> _heap;
};

int main(int argc, char const *argv[]) {
  int array[] = {3, 5, 6, 7, 20, 8, 2, 9, 12, 15, 30, 17};

  Heap<int> heap(30);

  for (size_t i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
    heap.push(array[i]);
  }

  std::cout << heap << std::endl;
  std::cout << "=============" << std::endl;
  for (size_t i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
    std::cout << heap.top() << std::endl;
    heap.pop();
  }
  return 0;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Heap<T> &heap) {
  for (int i = 0; i < heap._heap.capacity(); i++) {
    os << heap._heap[i] << " ";
  }
  return os;
}
