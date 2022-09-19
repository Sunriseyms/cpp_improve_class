#include <iostream>

int main() {
  std::cout << "Please input interges:" << std::endl;
  int in = 0, sum = 0;
  while (std::cin >> in) { sum += in; }
  std::cout << "Sum of input integers: " << sum << std::endl;
  return 0;
}
