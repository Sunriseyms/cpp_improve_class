#include <iostream>

int main() {
  std::cout << "PLease input two numbers:" << std::endl;
  int a = 0, b = 0;
  std::cin >> a;
  std::cin >> b;
  std::cout << "The result of ";
  std::cout << a;
  std::cout << "*";
  std::cout << b;
  std::cout << " is ";
  std::cout << a * b;
  std::cout << std::endl;
  return 0;
}
