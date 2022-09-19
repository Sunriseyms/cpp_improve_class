#include <iostream>

int main() {
  std::cout << "============ex.1.16============" << std::endl;
  int lower = 0;
  std::cout << "enter lower integer" << std::endl;
  while (std::cin >> lower) {
    int sum = 0;
    std::cout << "enter upper integer" << std::endl;
    int upper = 0;
    std::cin >> upper;
    if (lower > upper) { std::cout << "error: lower integer lager than upper integer" << std::endl; }
    for (; lower <= upper; lower++) { sum += lower; }
    std::cout << "Sum is " << sum << std::endl;
    std::cout << "enter lower integer" << std::endl;
  }

  return 0;
}
