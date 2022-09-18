#include <iostream>
int main() {
  std::cout << std::endl << "Exercise 1.3" << std::endl;
  std::cout << "Hello World!" << std::endl;

  std::cout << std::endl << "Exercise 1.4" << std::endl;
  int v1 = 0, v2 = 0;
  std::cin >> v1 >> v2;
  std::cout << v1 << " times " << v2 << " is " << v1 * v2 << std::endl;

  std::cout << std::endl << "Exercise 1.5" << std::endl;
  std::cout << v1;
  std::cout << " times ";
  std::cout << v2;
  std::cout << " is ";
  std::cout << v1 * v2 << std::endl;

  std::cout << std::endl << "Exercise 1.6" << std::endl;
  std::cout << "Vaild, the output is same as what we have in the text book example" << std::endl;

  return 0;
}
