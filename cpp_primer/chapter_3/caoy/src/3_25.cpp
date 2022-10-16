#include <iostream>
#include <string>
#include <vector>

int main() {
  std::cout << std::endl << "Exercise 3.25" << std::endl;
  std::vector<unsigned> grades = {42, 65, 95, 100, 39, 67, 95, 76, 88, 76, 83, 92, 76, 93};
  std::vector<unsigned> scores(11);
  for (auto it = grades.begin(); it != grades.end(); ++it) { scores[(*it) / 10]++; }
  for (auto it = scores.begin(); it != scores.end(); ++it) { std::cout << *it << std::endl; }
  return 0;
}
