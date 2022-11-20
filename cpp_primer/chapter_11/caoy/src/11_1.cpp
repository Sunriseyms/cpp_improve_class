#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

void WordCounter() {
  std::map<std::string, int> word_cnt;
  std::string line =
      "Nory was a Catholic because her mother was a Catholic, and Nory's mother was a Catholic because her father was "
      "a Catholic, and her father was a Catholic because his mother was a Catholic, or had been.";
  std::string word = "";
  for (auto it = line.begin(); it != line.end(); ++it) {
    if (isspace(*it) || it + 1 == line.end()) {
      if (!isalpha(word.back())) { word = word.substr(0, word.size() - 1); }
      word_cnt[word] += 1;
      word = "";
    } else {
      word += *it;
    }
  }
  for (auto it = word_cnt.begin(); it != word_cnt.end(); ++it) {
    std::cout << "word: \"" << it->first << "\" occurs " << it->second << " times" << std::endl;
  }
}

void WordCounterPlus() {
  std::map<std::string, int> word_cnt;
  std::string line =
      "Nory was. a Catholic because her mother, was a catholic, and nory's mother was a Catholic because her father "
      "was a Catholic, and her Father was, a Catholic because his mother was a Catholic, or had been.";
  std::string word = "";
  for (auto it = line.begin(); it != line.end(); ++it) {
    if (isspace(*it) || it + 1 == line.end()) {
      if (!isalpha(word.back())) { word = word.substr(0, word.size() - 1); }
      word_cnt[word] += 1;
      word = "";
    } else {
      word += tolower(*it);
    }
  }
  for (auto it = word_cnt.begin(); it != word_cnt.end(); ++it) {
    std::cout << "word: \"" << it->first << "\" occurs " << it->second << " times" << std::endl;
  }
}

void WordCounterInsert() {
  std::map<std::string, int> word_cnt;
  std::string line =
      "Nory was a Catholic because her mother was a Catholic, and Nory's mother was a Catholic because her father was "
      "a Catholic, and her father was a Catholic because his mother was a Catholic, or had been.";
  std::string word = "";
  for (auto it = line.begin(); it != line.end(); ++it) {
    if (isspace(*it) || it + 1 == line.end()) {
      if (!isalpha(word.back())) { word = word.substr(0, word.size() - 1); }
      auto ret = word_cnt.insert({word, 1});
      if (!ret.second) { ++ret.first->second; }
      word = "";
    } else {
      word += *it;
    }
  }
  for (auto it = word_cnt.begin(); it != word_cnt.end(); ++it) {
    std::cout << "word: \"" << it->first << "\" occurs " << it->second << " times" << std::endl;
  }
}

void WordCounterUnordered() {
  std::unordered_map<std::string, int> word_cnt;
  std::string line =
      "Nory was a Catholic because her mother was a Catholic, and Nory's mother was a Catholic because her father was "
      "a Catholic, and her father was a Catholic because his mother was a Catholic, or had been.";
  std::string word = "";
  for (auto it = line.begin(); it != line.end(); ++it) {
    if (isspace(*it) || it + 1 == line.end()) {
      if (!isalpha(word.back())) { word = word.substr(0, word.size() - 1); }
      word_cnt[word] += 1;
      word = "";
    } else {
      word += *it;
    }
  }
  for (auto it = word_cnt.begin(); it != word_cnt.end(); ++it) {
    std::cout << "word: \"" << it->first << "\" occurs " << it->second << " times" << std::endl;
  }
}

int main() {
  std::cout << std::endl << "Exercise 11.3" << std::endl;
  WordCounter();

  std::cout << std::endl << "Exercise 11.4" << std::endl;
  WordCounterPlus();

  std::cout << std::endl << "Exercise 11.7" << std::endl;
  std::map<std::string, std::vector<std::string>> family_names;
  std::string new_family = "Green";
  family_names[new_family] = {"Rachel", "Amy"};
  family_names["Green"].push_back("Jill");
  for (auto it = family_names.begin(); it != family_names.end(); ++it) {
    std::cout << "Family " << it->first << " has children: ";
    for (auto n : it->second) { std::cout << n << " "; }
  }
  std::cout << std::endl;

  std::cout << std::endl << "Exercise 11.8" << std::endl;
  std::vector<std::string> non_repeated_words;
  std::string line =
      "Nory was a Catholic because her mother was a Catholic, and Nory's mother was a Catholic because her father was "
      "a Catholic, and her father was a Catholic because his mother was a Catholic, or had been.";
  std::string word = "";
  for (auto it = line.begin(); it != line.end(); ++it) {
    if (isspace(*it) || it + 1 == line.end()) {
      if (!isalpha(word.back())) { word = word.substr(0, word.size() - 1); }
      if (std::find(non_repeated_words.begin(), non_repeated_words.end(), word) == non_repeated_words.end()) {
        non_repeated_words.push_back(word);
      }
      word = "";
    } else {
      word += *it;
    }
  }
  std::cout << "Non repeated words are: ";
  for (auto n : non_repeated_words) { std::cout << n << " "; }
  std::cout << std::endl;

  std::cout << std::endl << "Exercise 11.12" << std::endl;
  std::vector<std::string> num_str{"one", "two", "three"};
  std::vector<int> num_int{1, 2, 3};
  std::vector<std::pair<std::string, int>> num_pair;
  for (int i = 0; i < num_str.size(); ++i) { num_pair.emplace_back(num_str[i], num_int[i]); }
  for (auto i : num_pair) { std::cout << "num pair: " << i.first << " -> " << i.second << std::endl; }

  std::cout << std::endl << "Exercise 11.13" << std::endl;
  num_pair.emplace_back(std::pair<std::string, int>("four", 4));
  auto p = std::make_pair("five", 5);
  num_pair.emplace_back(p);
  for (auto i : num_pair) { std::cout << "num pair: " << i.first << " -> " << i.second << std::endl; }

  std::cout << std::endl << "Exercise 11.14" << std::endl;
  std::map<std::string, std::vector<std::pair<std::string, std::string>>> family_names2;
  std::string new_family2 = "Green";
  family_names2[new_family2] = {std::make_pair("Rachel", "021203"), std::make_pair("Amy", "000824")};
  family_names2["Green"].push_back(std::make_pair("Jill", "040506"));
  for (auto it = family_names2.begin(); it != family_names2.end(); ++it) {
    std::cout << "Family " << it->first << " has children: " << std::endl;
    for (auto n : it->second) { std::cout << n.first << " born on " << n.second << std::endl; }
  }
  std::cout << std::endl << "Exercise 11.20" << std::endl;
  WordCounterInsert();

  std::cout << std::endl << "Exercise 11.23" << std::endl;
  std::multimap<std::string, std::vector<std::string>> family_names3;
  std::string new_family3 = "Green";
  family_names3.insert({new_family3, {"Rachel", "Amy"}});
  family_names3.insert({new_family3, {"Jill"}});
  for (auto it = family_names3.begin(); it != family_names3.end(); ++it) {
    std::cout << "Family " << it->first << " has children: ";
    for (auto n : it->second) { std::cout << n << " "; }
    std::cout << std::endl;
  }

  std::cout << std::endl << "Exercise 11.31" << std::endl;
  std::multimap<std::string, std::vector<std::string>> collections;
  collections.insert({"Mike", {"book1", "book2", "book3"}});
  collections.insert({"Emily", {"book4", "book5"}});
  collections.insert({"Tom", {"book1", "book5"}});
  collections.insert({"Mike", {"book1", "book2"}});
  auto its = collections.equal_range("Mike");
  if (its.first != its.second) { collections.erase(its.first, its.second); }
  for (auto it = collections.begin(); it != collections.end(); ++it) {
    std::cout << "Author " << it->first << " has book: ";
    for (auto n : it->second) { std::cout << n << " "; }
    std::cout << std::endl;
  }
  std::cout << std::endl << "Exercise 11.32" << std::endl;
  for (auto it = collections.begin(); it != collections.end(); ++it) {
    std::cout << "Author " << it->first << " has book: ";
    for (auto n : it->second) { std::cout << n << " "; }
    std::cout << std::endl;
  }

  std::cout << std::endl << "Exercise 11.33" << std::endl;
  std::vector<std::string> shorts = {"r are", "k okay?", "u you", "y why", "pic picture"};
  std::vector<std::string> lines = {"where r u", "y dont u send me a pic", "r u k", "k", "pic", " "};
  std::vector<std::string> transformed_lines;
  std::map<std::string, std::string> shorts_map;
  for (auto s : shorts) {
    int space_index = s.find(" ");
    shorts_map.insert({s.substr(0, space_index), s.substr(space_index + 1, s.size())});
  }
  for (auto line : lines) {
    std::string transformed_line = "";
    std::string word = "";
    for (auto it = line.begin(); it != line.end(); ++it) {
      if (!isspace(*it)) {
        word += *it;
      } else {
        auto find_it = shorts_map.find(word);
        if (find_it != shorts_map.end()) {
          transformed_line += find_it->second;
        } else {
          transformed_line += word;
        }
        transformed_line += " ";
        word = "";
      }
    }
    (shorts_map.find(word) == shorts_map.end()) ? transformed_line += word
                                                : transformed_line += shorts_map.find(word)->second;

    transformed_lines.push_back(transformed_line);
  }
  std::cout << "After transformation: " << std::endl;
  for (auto line : transformed_lines) { std::cout << line << std::endl; }

  std::cout << std::endl << "Exercise 11.38" << std::endl;
  WordCounterUnordered();
  {
    std::vector<std::string> shorts = {"r are", "k okay?", "u you", "y why", "pic picture"};
    std::vector<std::string> lines = {"where r u", "y dont u send me a pic", "r u k", "k", "pic", " "};
    std::vector<std::string> transformed_lines;
    std::unordered_map<std::string, std::string> shorts_map;
    for (auto s : shorts) {
      int space_index = s.find(" ");
      shorts_map.insert({s.substr(0, space_index), s.substr(space_index + 1, s.size())});
    }
    for (auto line : lines) {
      std::string transformed_line = "";
      std::string word = "";
      for (auto it = line.begin(); it != line.end(); ++it) {
        if (!isspace(*it)) {
          word += *it;
        } else {
          auto find_it = shorts_map.find(word);
          if (find_it != shorts_map.end()) {
            transformed_line += find_it->second;
          } else {
            transformed_line += word;
          }
          transformed_line += " ";
          word = "";
        }
      }
      (shorts_map.find(word) == shorts_map.end()) ? transformed_line += word
                                                  : transformed_line += shorts_map.find(word)->second;

      transformed_lines.push_back(transformed_line);
    }
    std::cout << "After transformation: " << std::endl;
    for (auto line : transformed_lines) { std::cout << line << std::endl; }
  }
  return 0;
}
