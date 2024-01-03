#include <iostream>

template <typename T>
class LinearList {
 public:
  virtual ~LinearList() {}
  virtual bool empty() const = 0;
  virtual size_t size() const = 0;
  virtual T& get(int index) const = 0;
  virtual int indexOf(const T& element) const = 0;
  virtual void erase(int index) = 0;
  virtual void insert(int index, const T& element) = 0;
};

template <typename T>
class ArrayList : public LinearList<T> {
  template <typename T2>
  friend std::ostream& operator<<(std::ostream& os,
                                  const ArrayList<T2>& arrayList);

 public:
  ArrayList(size_t capability = 10) : _capablity(capability) {
    _element = new T[_capablity];
  }

  ArrayList(const ArrayList& array) {
    _element = new T[array._size];
    _capablity = array._capablity;
    _size = array._size;
    std::copy(array._element, array._element + array._size, _element);
  }

  ~ArrayList() { delete _element; }

  bool empty() const override { return _size == 0; }

  size_t size() const override { return _size; };

  T& get(int index) const override {
    if (index < 0 || index >= _size)
      throw std::invalid_argument("invalid argument");

    return _element[index];
  }

  int indexOf(const T& element) const override {
    for (size_t i = 0; i < _size; i++) {
      if (element == _element[i]) return i;
    }
    return -1;
  }

  void erase(int index) override {
    if (index < 0 || index >= _size)
      throw std::invalid_argument("invalid argument");

    if (_size - 1 < _capablity / 4) {
      size_t new_capability = _capablity / 2;
      T* p = new T[new_capability];

      std::copy(_element, _element + index, p);
      std::copy(_element + index + 1, _element + _size, p + index);
      _capablity = new_capability;

      delete _element;
      _element = p;
    } else {
      std::copy_backward(_element + index + 1, _element + _size,
                         _element + _size - 1);
    }
    _size--;
  }

  void insert(int index, const T& element) override {
    if ((_size + 1) > _capablity) {
      T* p = new T[_capablity * 2];
      std::copy(_element, _element + index, p);
      // p[index + 1] = element;
      std::copy(_element + index, _element + _size, p + index + 1);

      delete _element;
      _element = p;
      _capablity = _capablity * 2;
    } else {
      std::copy(_element + index, _element + _size + 1, _element + index + 1);
    }

    _size++;
    _element[index] = element;
  }

  void push_back(const T& element) {
    if ((_size + 1) > _capablity) {
      T* p = new T[_capablity * 2];
      std::copy(_element, _element + _size, p);

      delete _element;
      _element = p;
      _capablity = _capablity * 2;
    }
    _element[_size] = element;
    _size++;
  }

  void pop_back() {
    if (_size <= 0) return;

    _size--;
    if (_size < _capablity / 4) {
      size_t new_capalibity = _capablity / 2;
      T* p = new T[new_capalibity];

      std::copy(_element, _element + _size, p);
      delete _element;
      _element = p;
    }
  }

  void swap(ArrayList<T>& arrayList) {
    T* p = _element;
    size_t size = _size;
    size_t capability = _capablity;

    _element = arrayList._element;
    _size = arrayList._size;
    _capablity = arrayList._capablity;

    arrayList._element = p;
    arrayList._size = size;
    arrayList._capablity = capability;
  }

  void reverse() {
    for (size_t i = 0; i < _size; i++) {
      if (i < _size - i - 1) {
        std::swap(_element[i], _element[_size - i - 1]);
      } else {
        break;
      }
    }
  }

  T& operator[](int index) { return get(index); }
  bool operator==(const ArrayList<T>& arrayList) const;
  bool operator!=(const ArrayList<T>& arrayList) const {
    return !((*this) == arrayList);
  }

 private:
  T* _element = nullptr;
  size_t _capablity;
  size_t _size = 0;
};

int main(int argc, char const* argv[]) {
  ArrayList<int>* list = new ArrayList<int>(2);

  for (size_t i = 0; i < 19; i++) {
    list->push_back(i);
  }
  std::cout << *list << std::endl;

  ArrayList<int> list2(*list);
  for (size_t i = 0; i < 11; i++) {
    list2.pop_back();
  }
  list->swap(list2);
  std::cout << *list << std::endl;

  list2.reverse();
  std::cout << list2 << std::endl;

  delete list;
  list = nullptr;
  return 0;
}

template <typename T2>
std::ostream& operator<<(std::ostream& os, const ArrayList<T2>& arrayList) {
  for (size_t i = 0; i < arrayList.size(); i++) {
    os << arrayList._element[i] << " ";
  }
  return os;
}

template <typename T>
bool ArrayList<T>::operator==(const ArrayList<T>& arrayList) const {
  if (arrayList._size != _size) return false;

  for (size_t i = 0; i < arrayList._size; i++) {
    if (arrayList._element[i] != _element[i]) return false;
  }
  return true;
}
