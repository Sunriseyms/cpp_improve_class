#include <iostream>
#include <string>
#include <vector>

int main() {
  std::cout << std::endl << "Exercise 3.21" << std::endl;
  std::vector<int> v1;
  std::vector<int> v2(10);
  std::vector<int> v3(10, 42);
  std::vector<int> v4{10};
  std::vector<int> v5{10, 42};
  std::vector<std::vector<int>> int_vec = {v1, v2, v3, v4, v5};
  std::vector<std::string> v6{10};
  std::vector<std::string> v7{10, "hi"};
  std::vector<std::vector<std::string>> str_vec = {v6, v7};
  for (auto it = int_vec.begin(); it != int_vec.end(); ++it) {
    std::cout << it->size() << std::endl;
    if (it->size() > 0) {
      for (auto num_it = it->begin(); num_it != it->end(); ++num_it) { std::cout << *num_it << std::endl; }
    }
    std::cout << "=========" << std::endl;
  }
  for (auto it = str_vec.begin(); it != str_vec.end(); ++it) {
    std::cout << it->size() << std::endl;
    if (it->size() > 0) {
      for (auto str_it = it->begin(); str_it != it->end(); ++str_it) { std::cout << *str_it << std::endl; }
    }
    std::cout << "=========" << std::endl;
  }

  std::cout << std::endl << "Exercise 3.22" << std::endl;
  std::vector<std::string> text;
  text.emplace_back("hello ");
  text.emplace_back("how are you ");
  text.emplace_back("\0");
  text.emplace_back("left");

  for (auto it = text.begin(); it != text.end() && !it->empty(); ++it) {
    for (auto& c : *it) { c = toupper(c); }
    std::cout << *it << std::endl;
  }

  std::cout << std::endl << "Exercise 3.23" << std::endl;
  std::vector<int> ten_int;
  for (int i = 0; i < 10; ++i) { ten_int.push_back(i); }
  for (auto it = ten_int.begin(); it != ten_int.end(); ++it) {
    *it = *it * 2;
    std::cout << *it << std::endl;
  }

  std::cout << std::endl << "Exercise 3.24" << std::endl;
  int num;
  std::vector<int> num_vec;
  while (std::cin >> num) { num_vec.push_back(num); }
  for (auto it = num_vec.begin(); it != num_vec.end(); ++it) {
    if ((it + 1) != num_vec.end()) {
      std::cout << *it + *(it + 1) << std::endl;
      ++it;
    } else {
      std::cout << *it << std::endl;
    }
  }
  std::cout << "=============" << std::endl;
  for (auto it = num_vec.begin(); (it - num_vec.begin()) <= (num_vec.end() - num_vec.begin()) / 2; ++it) {
    if ((it - num_vec.begin()) < (num_vec.end() - num_vec.begin()) / 2) {
      std::cout << *it + *(num_vec.end() - it + num_vec.begin() - 1) << std::endl;
    } else {
      std::cout << *it << std::endl;
    }
  }
  return 0;
}
