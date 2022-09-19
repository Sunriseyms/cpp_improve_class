#include <cmath>
#include <iostream>

int main() {
  std::cout << "PLease input two integers:" << std::endl;
  int a = 0, b = 0;
  std::cin >> a >> b;
  if (abs(a - b) <= 1) {
    std::cout << "There is no interger between " << a << " and " << b << std::endl;
    return 0;
  }
  std::cout << "The intergers between " << a << " and " << b << ": ";
  int tmp = a;
  do {
    tmp += copysign(1, b - a);
    std::cout << tmp << " ";
  } while (abs(tmp - b) > 1);

  std::cout << std::endl;
  return 0;
}
