#include <iostream>

int main() {
  int begin = 50, begin_org = begin, end = 100;
  int sum = 0;
  while (begin <= end) { sum += begin++; }
  std::cout << "The sum of " << begin_org << " to " << end << " is " << sum << std::endl;
  return 0;
}
