#include <iostream>
int main() {
  std::cout << "============ex.1.9============" << std::endl;
  int sum = 0, val = 100;
  while (val >= 50) {
    sum += val;
    val--;
  }
  std::cout << "Sum of 50 to 100 inclusive is " << sum << std::endl;

  std::cout << "============ex.1.10============" << std::endl;
  std::cout << "print each number from 10 to 0 " << std::endl;
  int sum1 = 0, val1 = 10;
  while (val1 >= 0) {
    std::cout << val1 << std::endl;
    val1--;
  }

  std::cout << "============ex.1.11============" << std::endl;
  std::cout << "Please enter two integers " << std::endl;
  int num1, num2;
  std::cin >> num1 >> num2;
  int upper = std::max(num1, num2);
  int lower = std::min(num1, num2);
  std::cout << "print each number from " << lower << " to " << upper << std::endl;
  while (lower <= upper) {
    std::cout << lower << std::endl;
    lower++;
  }

  return 0;
}
