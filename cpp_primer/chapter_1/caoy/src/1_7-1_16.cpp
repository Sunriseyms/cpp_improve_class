#include <iostream>

int main() {
  std::cout << std::endl << "Exercise 1.7" << std::endl;
  //   /*
  //   invaild nested commont tese /* */
  //   * /
  std::cout << "error:" << std::endl;
  std::cerr << "expected primary-expression before '/' token" << std::endl;

  std::cout << std::endl << "Exercise 1.8" << std::endl;
  std::cout << "No.1:" << std::endl << "/*" << std::endl;
  std::cout << "No.2:" << std::endl << "*/" << std::endl;
  //   std::cout << "No.3:" << std::endl
  //             << /* "*/ " */<< std::endl;
  std::cout << "No.4:" << std::endl << /* "*/ " /* " /*" */ << std::endl;
  std::cout << "Only No.3 is statement invaild, can add one double quotes at end, then outpit is { */ }" << std::endl;

  std::cout << std::endl << "Exercise 1.9" << std::endl;
  int num = 50, sum = 0;
  while (num <= 100) {
    sum += num;
    num++;
  }
  std::cout << "Sum of 50 to 100 is " << sum << std::endl;

  std::cout << std::endl << "Exercise 1.10" << std::endl;
  int sub_num = 10;
  while (sub_num >= 0) {
    std::cout << sub_num << std::endl;
    sub_num--;
  }

  std::cout << std::endl << "Exercise 1.11" << std::endl;
  std::cout << "Please enter 2 integers: " << std::endl;
  int var1 = 0, var2 = 0;
  std::cin >> var1 >> var2;
  std::cout << "All the integers between " << var1 << " and " << var2 << " are:" << std::endl;
  while (var1 != var2) {
    std::cout << var1 << std::endl;
    if (var2 > var1) {
      var1++;
    } else {
      var1--;
    }
  }
  std::cout << var2 << std::endl;

  std::cout << std::endl << "Exercise 1.12" << std::endl;
  std::cout << "Calculate the sum of integers from -100 to 100, result should be 0" << std::endl;
  int sum_1_12 = 0;
  for (int i = -100; i < -100; i++) { sum_1_12 += i; }
  std::cout << "Sum calculated from code is: " << sum_1_12 << std::endl;

  std::cout << std::endl << "Exercise 1.13" << std::endl;
  int sum_1_13 = 0;
  for (int i = 50; i <= 100; i++) { sum_1_13 += i; }
  std::cout << "Sum of 50 to 100 is " << sum_1_13 << std::endl;

  for (int i = 10; i >= 0; i--) { std::cout << i << std::endl; }

  std::cout << "Please enter 2 integers: " << std::endl;
  int var1_prime = 0, var2_prime = 0;
  std::cin >> var1_prime >> var2_prime;
  std::cout << "All the integers between " << var1_prime << " and " << var2_prime << " are:" << std::endl;
  if (var1_prime > var2_prime) {
    for (var1_prime; var1_prime > var2_prime; var1_prime--) { std::cout << var1_prime << std::endl; }
  } else {
    for (var1_prime; var1_prime < var2_prime; var1_prime++) { std::cout << var1_prime << std::endl; }
  }
  std::cout << var2_prime << std::endl;

  std::cout << std::endl << "Exercise 1.14" << std::endl;
  std::cout << "for loop format is more compact, but coder must know the number of iterations when using a for loop"
            << std::endl;

  std::cout << std::endl << "Exercise 1.15" << std::endl;

  std::cout << std::endl << "Exercise 1.16" << std::endl;
  std::cout << "Please enter some integers" << std::endl;
  int var_1_16 = 0, sum_1_16 = 0;
  while (std::cin >> var_1_16) { sum_1_16 += var_1_16; }
  std::cout << "Sum is: " << sum_1_16 << std::endl;

}
