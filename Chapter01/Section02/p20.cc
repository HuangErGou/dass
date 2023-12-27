#include <iostream>

unsigned long fibonacci_r(unsigned long n) {
  if (n <= 1) return 1;
  return fibonacci_r(n - 1) + fibonacci_r(n - 2);
}

void test_fibonacci_r() {
  for (size_t i = 0; i < 10; i++) {
    std::cout << fibonacci_r(i) << " ";
  }
  std::cout << std::endl;
}

unsigned long fibonacci_l(unsigned long n) {
  if (n <= 1) return 1;

  unsigned long last_1 = 1;
  unsigned long last_2 = 1;
  unsigned long result = 0;

  for (unsigned long i = 2; i <= n; i++) {
    result = last_2 + last_1;
    last_2 = last_1;
    last_1 = result;
  }
  return result;
}

void test_fibonacci_l() {
  for (size_t i = 0; i < 10; i++) {
    std::cout << fibonacci_l(i) << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char const *argv[]) {
  test_fibonacci_r();
  test_fibonacci_l();
  return 0;
}
