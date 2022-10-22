#include <iostream>
#include <string>

int Fact(int num) {
  if (num < 0) { return -1; }
  int fact = 1;
  while (num > 1) {
    fact *= num;
    num -= 1;
  }
  return fact;
}

int Fact() {
  std::cout << "Please enter a num to calc its factorial\n";
  int num;
  std::cin >> num;
  if (num < 0) { return -1; }
  int fact = 1;
  while (num > 1) {
    fact *= num;
    num -= 1;
  }
  return fact;
}

double Abs() {
  std::cout << "Please enter a num to calc its abs value\n";
  double num;
  std::cin >> num;
  return std::abs(num);
}

void ValCompare(int param) {
  std::cout << "function parameter is: " << param << std::endl;
  int local_val = 0;
  std::cout << "local var is: " << local_val << std::endl;
  static int static_val = 1;
  std::cout << "static_val is: " << static_val << " aka. function called times" << std::endl;
  static_val += 1;
  std::cout << "===========" << std::endl;
}

int FunctionCallCnt() {
  static int static_val = -1;
  static_val += 1;
  return static_val;
}

int main() {
  std::cout << std::endl << "Exercise 6.3" << std::endl;
  int fact_5 = Fact(5);
  std::cout << "Factorial of 5 is : " << fact_5 << std::endl;

  std::cout << std::endl << "Exercise 6.4" << std::endl;
  int fact = Fact();
  std::cout << "Factorial is : " << fact << std::endl;

  std::cout << std::endl << "Exercise 6.5" << std::endl;
  double abs_val = Abs();
  std::cout << "Absolute value is : " << abs_val << std::endl;

  std::cout << std::endl << "Exercise 6.6" << std::endl;
  int param1 = 10, param2 = 20;
  ValCompare(param1);
  ValCompare(param2);

  std::cout << std::endl << "Exercise 6.7" << std::endl;
  for (int i = 0; i < 10; ++i) {
    int cnt = FunctionCallCnt();
    std::cout << "This func is called " << cnt << " times\n=========\n" << std::endl;
  }

  return 0;
}
