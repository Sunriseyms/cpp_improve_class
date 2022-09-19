#include <iostream>

int main() {
  int begin = 50, end = 100, sum = 0;
  for (int begin_tmp = begin; begin_tmp <= end; begin_tmp++) { sum += begin_tmp; }
  std::cout << "The sum of " << begin << " to " << end << " is " << sum << std::endl;
  return 0;
}
