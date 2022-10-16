#include <iostream>
#include <string>
#include <vector>

int main() {
  std::cout << std::endl << "Exercise 3.5.1" << std::endl;
  std::string word;
  std::string line;
  while (std::cin >> word) {
    if (word == "break~") {
      break;
    } else {
      line += word;
      std::cout << "enter break~ if you want to stop, enter new word to continue" << std::endl;
    }
  }
  std::cout << line << std::endl;

  std::cout << std::endl << "Exercise 3.5.2" << std::endl;
  std::string word1;
  std::string line1;
  while (std::cin >> word1) {
    if (word1 == "break~") {
      break;
    } else {
      if (line1 != "") { line1 += " "; }
      line1 += word1;
      std::cout << "enter break~ if you want to stop, enter new word to continue" << std::endl;
    }
  }
  std::cout << line1 << std::endl;

  std::cout << std::endl << "Exercise 3.6" << std::endl;
  std::string x_input;
  std::cout << "Please enter a string" << std::endl;
  std::cin >> x_input;
  std::string x_input_copy = x_input;
  for (auto& c : x_input) { c = 'X'; }
  std::cout << x_input << std::endl;

  std::cout << std::endl << "Exercise 3.7" << std::endl;
  for (char& c : x_input_copy) { c = 'X'; }
  std::cout << x_input_copy << std::endl;

  std::cout << std::endl << "Exercise 3.8" << std::endl;
  std::string x_input_while;
  std::cout << "Please enter a string" << std::endl;
  std::cin >> x_input_while;
  std::string x_input_while_copy = x_input_while;
  decltype(x_input_while.size()) i = 0;
  while (i < x_input_while.size()) {
    x_input_while[i] = 'X';
    i++;
  }
  std::cout << x_input_while << std::endl;
  i = 0;
  for (decltype(x_input_while.size()) ii = 0; ii < x_input_while_copy.size(); ii++) { x_input_while_copy[ii] = 'X'; }
  std::cout << x_input_while_copy << std::endl;

  std::cout << std::endl << "Exercise 3.10" << std::endl;
  std::string str_with_punct;
  std::cout << "Please enter a string" << std::endl;
  std::cin >> str_with_punct;
  for (char& c : str_with_punct) {
    if (ispunct(c)) { c = '\0'; }
  }
  std::cout << str_with_punct << std::endl;

  std::cout << std::endl << "Exercise 3.14" << std::endl;
  int num;
  std::vector<int> num_vec;
  while (std::cin >> num) { num_vec.push_back(num); }
  for (auto n : num_vec) { std::cout << n << std::endl; }

  return 0;
}
