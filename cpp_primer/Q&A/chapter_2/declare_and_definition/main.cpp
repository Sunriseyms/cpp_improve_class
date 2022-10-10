#include <iostream>
int func();
extern int val;

int main() {
  func();
  std::cout << "val=" << val << std::endl;
  return 0;
}
