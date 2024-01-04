#include <iostream>
#include <stack>

void hanoi(int n, std::stack<int>& from, std::stack<int>& buffer,
           std::stack<int>& to) {
  if (n >= 1) {
    hanoi(n - 1, from, to, buffer);
    to.push(from.top());
    from.pop();
    hanoi(n - 1, buffer, from, to);
  }
}

int main() {
  std::stack<int> from, buffer, to;

  for (size_t i = 15; i > 0; i--) {
    from.push(i);
  }

  hanoi(from.size(), from, buffer, to);
  return 0;
}