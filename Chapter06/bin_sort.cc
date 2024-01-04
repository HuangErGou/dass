#include <iostream>
#include <list>
#include <map>
#include <string>

class StudentRecord {
  friend std::ostream& operator<<(std::ostream& os, const StudentRecord& v);

 public:
  StudentRecord(const std::string& name, int score)
      : _name(name), _score(score) {}

  bool operator==(const StudentRecord& other) const {
    return _score == other._score;
  }

  bool operator!=(const StudentRecord& other) const {
    return _score != other._score;
  }

  operator int() const { return _score; }

 private:
  std::string _name;
  int _score;
};

template <typename T>
void bin_sort(std::list<T>& theList, int range) {
  if (range <= 0) throw "invalid range";

  std::map<int, std::list<T>> bin;
  for (size_t i = 0; i < range; i++) {
    bin[i] = std::list<T>();
  }

  while (!theList.empty()) {
    T v = theList.front();
    theList.pop_front();

    std::list<T> l = bin[(int)v];
    l.push_front(v);
    bin[(int)v] = l;
  }

  for (size_t i = 0; i < range; i++) {
    std::list<T> theBin = bin[i];

    while (!theBin.empty()) {
      T v = theBin.front();
      theBin.pop_front();
      theList.push_front(v);
    }
  }
}

int main(int argc, char const* argv[]) {
  srand((int)time(0));

  std::list<StudentRecord> data;

  data.push_back(StudentRecord("1", 70));
  data.push_back(StudentRecord("2", 70));
  data.push_back(StudentRecord("3", 70));
  for (size_t i = 0; i < 20; i++) {
    data.push_back(StudentRecord("", rand() % 100));
  }

  bin_sort(data, 99);
  for (std::list<StudentRecord>::iterator iter = data.begin();
       iter != data.end(); iter++) {
    std::cout << *iter;
  }
  std::cout << std::endl;
  return 0;
}

std::ostream& operator<<(std::ostream& os, const StudentRecord& v) {
  os << "name is: " << v._name << ", score is: " << v._score;
  os << std::endl;
  return os;
}
