#include <iostream>
int main() {
  std::cout << "============ex.1.13============" << std::endl;
  std::cout << "----------ex.1.9(for)----------" << std::endl;
  int sum = 0, val = 50;
  for (; val <= 100; val++) { sum += val; }
  std::cout << "Sum of 50 to 100 inclusive is " << sum << std::endl;

  return 0;
}
