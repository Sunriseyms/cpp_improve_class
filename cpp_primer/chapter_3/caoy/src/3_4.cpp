#include <iostream>
#include <string>

int main() {
  std::cout << std::endl << "Exercise 3.4" << std::endl;
  std::string str1, str2;
  std::cout << "Please enter two strings" << std::endl;
  std::cin >> str1 >> str2;
  if (str1 == str2) {
    std::cout << str1 << " equals to " << str2 << std::endl;
  } else if (str1 > str2) {
    std::cout << str1 << " is bigger" << std::endl;
  } else {
    std::cout << str2 << " is bigger" << std::endl;
  }

  std::string str1_prime, str2_prime;
  std::cout << "Please enter two strings" << std::endl;
  std::cin >> str1_prime >> str2_prime;
  if (str1_prime.size() == str2_prime.size()) {
    std::cout << str1_prime << " has the same length as " << str2_prime << std::endl;
  } else if (str1_prime.size() > str2_prime.size()) {
    std::cout << str1_prime << " is longer" << std::endl;
  } else {
    std::cout << str2_prime << " is longer" << std::endl;
  }

  return 0;
}
