#include <iostream>
#include <string>
#include <vector>

int main() {
  std::cout << std::endl << "Exercise 3.17" << std::endl;
  std::string word;
  std::vector<std::string> words;
  while (std::cin >> word) { words.push_back(word); }
  for (auto& w : words) {
    for (auto& c : w) { c = toupper(c); }
    std::cout << w << std::endl;
  }

  return 0;
}
