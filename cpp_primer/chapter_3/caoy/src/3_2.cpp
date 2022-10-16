#include <iostream>
#include <string>

int main() {
  std::cout << std::endl << "Exercise 3.2.1" << std::endl;
  std::string line;
  std::cout << "Please enter a line" << std::endl;
  while (getline(std::cin, line)) {
    std::cout << "Read line: " << line << std::endl;
    if (line == "break~") {
      break;
    } else {
      std::cout << "enter break~ if you want to stop,enter a new line to continue" << std::endl;
    }
  }

  std::cout << std::endl << "Exercise 3.2.2" << std::endl;
  std::string word;
  std::cout << "Please enter one word or more" << std::endl;
  while (std::cin >> word) {
    std::cout << "Read word: " << word << std::endl;
    if (word == "break~") {
      break;
    } else {
      std::cout << "enter break~ if you want to stop, enter new words to continue" << std::endl;
    }
  }
  return 0;
}
