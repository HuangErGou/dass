#include <iostream>

long gcd_r(long x, long y) {
  if (x <= y) std::swap(x, y);

  if (y == 0) return x;
  return gcd_r(y, x % y);
}

long gcd_l(long x, long y) {
  if (x <= y) std::swap(x, y);

  while (y != 0) {
    long m = x % y;
    if (m == 0) break;

    x, y = y <= m ? y, m : m, y;
  }
  return y;
}

int main(int argc, char const *argv[]) {
  std::cout << gcd_r(20, 30) << std::endl;
  std::cout << gcd_l(20, 31) << std::endl;
  return 0;
}
