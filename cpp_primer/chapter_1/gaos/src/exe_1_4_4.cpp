#include <iostream>

int main() {
  std::cout << "============ex.1.18============" << std::endl;
  int curr_val = 0, val = 0;
  if (std::cin >> curr_val) {
    int count = 1;
    while (std::cin >> val) {
      if (val == curr_val) {
        count++;
      } else {
        std::cout << curr_val << " occurs " << count << " times" << std::endl;
        curr_val = val;
        count = 1;
      }
    }
    std::cout << curr_val << " occurs " << count << " times" << std::endl;
  }

  std::cout << "============ex.1.19============" << std::endl;
  std::cout << "Please enter two integers " << std::endl;
  int num1, num2, lower, upper;
  std::cin >> num1 >> num2;
  if (num1 < num2) {
    lower = num1;
    upper = num2;
  } else {
    lower = num2;
    upper = num1;
  }
  for (; lower <= upper; lower++) { std::cout << "The present integer is " << lower << std::endl; }
  return 0;
}
