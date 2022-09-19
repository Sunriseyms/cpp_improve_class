#include <iostream>

int main() {
  std::cout << "============ex.1.16============" << std::endl;
  int sum = 0, val = 0;
  while (std::cin >> val) { sum += val; }
  std::cout << "Sum is " << sum << std::endl;

  return 0;
}
