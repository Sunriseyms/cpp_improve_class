#include <iostream>
#include <string>
#include <vector>

int Sum(std::initializer_list<int> ls) {
  int sum = 0;
  for (auto it = ls.begin(); it != ls.end(); ++it) { sum += *it; }
  return sum;
}

void RecurseVector(std::vector<int> vec) {
  if (vec.size() > 0) {
    std::cout << vec[0] << std::endl;
    if (vec.size() > 1) {
      vec.erase(vec.begin());
      RecurseVector(vec);
    }
  }
}
std::string MakePlural(size_t ctr, const std::string& word, const std::string& ending = "s") {
  return (ctr > 1) ? word + ending : word;
}

int main() {
  std::cout << std::endl << "Exercise 6.27" << std::endl;
  std::initializer_list<int> ls = {1, 2, 3, 4, 5};
  std::cout << Sum(ls) << std::endl;

  std::cout << std::endl << "Exercise 6.33" << std::endl;
  std::vector<int> vec{0, 1, 2, 3, 4, 5};
  RecurseVector(vec);

  std::cout << std::endl << "Exercise 6.42" << std::endl;
  std::cout << "single form of failure is: " << MakePlural(1, "failure") << std::endl;
  std::cout << "plural form of failure is: " << MakePlural(2, "failure") << std::endl;
  std::cout << "single form of success is: " << MakePlural(1, "success", "es") << std::endl;
  std::cout << "plural form of success is: " << MakePlural(2, "success", "es") << std::endl;

  return 0;
}
