#include <iostream>

int main() {
  std::cout << "============ex.1.13============" << std::endl;
  std::cout << "----------ex.1.9(for)----------" << std::endl;
  int sum = 0, val = 50;
  for (int val = 50; val <= 100; val++) { sum += val; }
  std::cout << "Sum of 50 to 100 inclusive is " << sum << std::endl;

  std::cout << "----------ex.1.10(for)----------" << std::endl;
  int sum1 = 0, val1 = 10;
  for (int val1 = 10; val1 >= 0; val1--) { sum1 += val1; }

  std::cout << "Sum of 10 to 0 inclusive is " << sum1 << std::endl;

  std::cout << "----------ex.1.10(for)----------" << std::endl;
  std::cout << "Please enter two integers " << std::endl;
  int num1, num2;
  std::cin >> num1 >> num2;
  int upper = std::max(num1, num2);
  int lower = std::min(num1, num2);
  for (lower; lower <= upper; lower++) { std::cout << "The present integer is " << lower << std::endl; }

  return 0;
}
