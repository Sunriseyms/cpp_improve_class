#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

int main() {
  // 11.1
  {
    std::cout << "\n 11.1: \n";
    std::vector<std::string> words = {"ABC.", "Abc", "abc"};
    std::unordered_map<std::string, int> words_map;
    for (auto word : words) {
      std::string trans_word;
      for (int i = 0; i < word.size(); i++) {
        if (word[i] >= 'a' && word[i] <= 'z') {
          trans_word.push_back(word[i]);
        } else if (word[i] >= 'A' && word[i] <= 'Z') {
          trans_word.push_back(word[i] - ('Z' - 'z'));
        } else {
          continue;
        }
      }
      words_map[trans_word]++;
    }
    for (const auto& elem : words_map) { std::cout << elem.first << " : " << elem.second << std::endl; }
  }

  // 11.8
  {
    std::cout << "\n 11.8: \n";
    std::vector<std::string> names_vec = {"B", "A", "C", "A"};
    std::vector<std::string> unique_vec;
    std::set<std::string> unique_set;
    for (const auto& name : names_vec) {
      if (std::find(unique_vec.begin(), unique_vec.end(), name) == unique_vec.end()) { unique_vec.push_back(name); }
      unique_set.insert(name);
    }

    std::cout << "Unique vector : ";
    for (const auto& name : unique_vec) { std::cout << name << " "; }
    std::cout << std::endl;

    std::cout << "Unique Set : ";
    for (const auto& name : unique_set) { std::cout << name << " "; }
    std::cout << std::endl;
  }

  // 11.22
  {
    std::cout << "\n 11.22: \n";
    std::map<std::string, std::vector<int>> vec_map;
    vec_map.insert(std::make_pair<std::string, std::vector<int>>("aa", {1, 3, 5}));
    for (const auto& elem : vec_map) {
      std::cout << elem.first << " the size of the vector is " << elem.second.size() << std::endl;
    }
    std::cout << "参数类型 ： std::pair<std::string, std::vector<int>>" << std::endl;
    std::cout << "返回值类型:"
              << "std::pair<std::map<std::string, std::vector<int>>::iterator,bool>" << std::endl;
  }

  return 0;
}
