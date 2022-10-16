#include <iostream>
#include <string>
#include <vector>

int main() {
  std::cout << std::endl << "Exercise 3.15" << std::endl;
  std::string sub_str;
  std::vector<std::string> str_vector;
  while (std::cin >> sub_str) { str_vector.push_back(sub_str); }
  for (auto s : str_vector) { std::cout << s << std::endl; }

  std::cout << std::endl << "Exercise 3.16" << std::endl;
  std::vector<int> v1;
  std::vector<int> v2(10);
  std::vector<int> v3(10, 42);
  std::vector<int> v4{10};
  std::vector<int> v5{10, 42};
  std::vector<std::vector<int>> int_vec = {v1, v2, v3, v4, v5};
  std::vector<std::string> v6{10};
  std::vector<std::string> v7{10, "hi"};
  std::vector<std::vector<std::string>> str_vec = {v6, v7};
  for (auto vec : int_vec) {
    std::cout << vec.size() << std::endl;
    for (auto num : vec) { std::cout << num << std::endl; }
    std::cout << "=========" << std::endl;
  }
  for (auto vec : str_vec) {
    std::cout << vec.size() << std::endl;
    for (auto str : vec) { std::cout << str << std::endl; }
    std::cout << "=========" << std::endl;
  }
  return 0;
}
