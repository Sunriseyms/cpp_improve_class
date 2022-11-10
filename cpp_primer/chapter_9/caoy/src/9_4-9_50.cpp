#include <deque>
#include <forward_list>
#include <iostream>
#include <list>
#include <string>
#include <vector>

bool FindIntByIter(std::vector<int>::iterator left, std::vector<int>::iterator right, int i) {
  while (left != right) {
    if ((*left) == i) {
      return true;
    } else {
      left++;
    }
  }
  return false;
}

std::vector<int>::iterator FindIntByIter2(std::vector<int>::iterator left, std::vector<int>::iterator right, int i) {
  while (left != right) {
    if ((*left) == i) {
      return left;
    } else {
      left++;
    }
  }
  return right;
}

void InsertForwardList(std::forward_list<std::string> for_ls_str, std::string str_to_find, std::string str_to_insert) {
  bool find_succ = false;
  auto prev_it = for_ls_str.before_begin();
  for (auto it = for_ls_str.begin(); it != for_ls_str.end(); ++prev_it, ++it) {
    if (*it == str_to_find) {
      for_ls_str.insert_after(it, str_to_insert);
      find_succ = true;
    }
  }
  if (!find_succ) { for_ls_str.insert_after(prev_it, str_to_insert); }
  for (auto it = for_ls_str.begin(); it != for_ls_str.end(); ++it) { std::cout << *it << " "; }
  std::cout << std::endl;
}

void InsertAndEraseString(std::string s, std::string old_val, std::string new_val) {
  int old_val_size = old_val.size();
  for (auto it = s.begin(); it != s.end(); ++it) {
    std::string sub_str;
    for (int i = 0; i < old_val_size; ++i) { sub_str += *(it + i); }
    if (sub_str == old_val) {
      it = s.erase(it, it + old_val_size);
      it = s.insert(it, new_val.begin(), new_val.end());
    }
  }
  std::cout << s << std::endl;
}

void ReplaceString(std::string s, std::string old_val, std::string new_val) {
  int old_val_size = old_val.size();
  int pos = s.find(old_val);
  while (pos >= 0) {
    s.replace(pos, old_val_size, new_val);
    pos = s.find(old_val);
  }
  std::cout << s << std::endl;
}

std::string FullName(std::string name, std::string prefix, std::string suffix) {
  prefix.append(" ");
  suffix.insert(0, " ");
  name.insert(name.begin(), prefix.begin(), prefix.end());
  name.append(suffix);
  return name;
}

std::string FullName2(std::string name, std::string prefix, std::string suffix) {
  prefix.insert(prefix.size(), " ");
  suffix.insert(0, " ");
  name.insert(name.begin(), prefix.begin(), prefix.end());
  name.insert(name.end(), suffix.begin(), suffix.end());
  return name;
}




int main() {
  std::cout << std::endl << "Exercise 9.4" << std::endl;
  std::vector<int> int_vec = {1, 6, 7, 5, 8, 9};
  std::cout << "6 is in vector: " << FindIntByIter(int_vec.begin(), int_vec.end(), 6) << std::endl;
  std::cout << "4 is in vector: " << FindIntByIter(int_vec.begin(), int_vec.end(), 4) << std::endl;

  std::cout << std::endl << "Exercise 9.5" << std::endl;
  std::cout << "6 is in vector: " << *FindIntByIter2(int_vec.begin(), int_vec.end(), 6) << std::endl;
  std::cout << "4 is in vector: " << *FindIntByIter2(int_vec.begin(), int_vec.end(), 4) << std::endl;

  std::cout << std::endl << "Exercise 9.13" << std::endl;
  std::list<int> ls = {0, 1, 3, 5};
  std::vector<int> vec_int = {0, 1, 3, 5};
  std::vector<double> vec_double(ls.begin(), ls.end());
  for (auto i : vec_double) {
    {
      std::cout << i << std::endl;
    }
  }
  std::vector<double> vec_double2(vec_int.begin(), vec_int.end());
  for (auto i : vec_double2) {
    {
      std::cout << i << std::endl;
    }
  }

  std::cout << std::endl << "Exercise 9.14" << std::endl;
  std::list<const char*> ls_ch = {"abc", "def", "ghi"};
  std::vector<std::string> vec_str(ls_ch.begin(), ls_ch.end());
  for (auto i : vec_str) {
    {
      std::cout << i << std::endl;
    }
  }

  std::cout << std::endl << "Exercise 9.15" << std::endl;
  std::vector<int> vec1{1, 2, 3};
  std::vector<int> vec2{1, 2, 3};
  std::vector<int> vec3{1, 2, 3, 4};
  std::cout << "vec1 equals to vec2: " << (vec1 == vec2) << std::endl;
  std::cout << "vec1 equals to vec3: " << (vec1 == vec3) << std::endl;

  std::cout << std::endl << "Exercise 9.15" << std::endl;
  auto it_vec = vec3.begin();
  for (auto it_ls = ls.begin(); it_ls != ls.end(); ++it_ls, ++it_vec) {
    std::cout << (*it_ls) << " equals to " << (*it_vec) << ": " << ((*it_ls) == (*it_vec)) << std::endl;
  }

  std::cout << std::endl << "Exercise 9.18" << std::endl;
  std::deque<std::string> deq_str;
  deq_str.emplace_back("hi");
  deq_str.emplace_back("there");
  deq_str.emplace_back("how");
  deq_str.emplace_back("are");
  deq_str.emplace_back("you");
  for (auto it = deq_str.begin(); it != deq_str.end(); ++it) { std::cout << *it << std::endl; }

  std::cout << std::endl << "Exercise 9.20" << std::endl;
  std::list<int> ls_int_all{10, 5, 8, 3, 6, 9};
  std::deque<int> deq_odd, deq_even;
  for (auto it = ls_int_all.begin(); it != ls_int_all.end(); ++it) {
    if ((*it) % 2 == 0) {
      deq_even.push_back(*it);
    } else {
      deq_odd.push_back(*it);
    }
  }
  std::cout << "Odd numbers are: " << std::endl;
  for (auto it = deq_odd.begin(); it != deq_odd.end(); ++it) { std::cout << *it << std::endl; }
  std::cout << "Even numbers are: " << std::endl;
  for (auto it = deq_even.begin(); it != deq_even.end(); ++it) { std::cout << *it << std::endl; }

  std::cout << std::endl << "Exercise 9.26" << std::endl;
  int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
  std::vector<int> vec_ia;
  std::list<int> ls_ia;
  for (int i = 0; i < (sizeof(ia) / sizeof(ia[0])); ++i) {
    vec_ia.push_back(ia[i]);
    ls_ia.push_back(ia[i]);
  }
  auto it1 = vec_ia.begin();
  auto it2 = ls_ia.begin();
  for (; it1 != vec_ia.end(), it2 != ls_ia.end();) {
    if ((*it1) % 2 == 0) {
      it1 = vec_ia.erase(it1);
    } else {
      ++it1;
    }
    if ((*it2) % 2 != 0) {
      it2 = ls_ia.erase(it2);
    } else {
      ++it2;
    }
  }
  std::cout << "Odd numbers are: " << std::endl;
  for (auto it = vec_ia.begin(); it != vec_ia.end(); ++it) { std::cout << *it << std::endl; }
  std::cout << "Even numbers are: " << std::endl;
  for (auto it = ls_ia.begin(); it != ls_ia.end(); ++it) { std::cout << *it << std::endl; }

  std::cout << std::endl << "Exercise 9.27" << std::endl;
  std::forward_list<int> for_ls_ia{0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
  auto prev_it = for_ls_ia.before_begin();
  for (auto it = for_ls_ia.begin(); it != for_ls_ia.end();) {
    if (*it % 2 != 0) {
      it = for_ls_ia.erase_after(prev_it);
      prev_it++;
    } else {
      prev_it++;
      ++it;
    }
  }
  std::cout << "Even numbers are: " << std::endl;
  for (auto it = for_ls_ia.begin(); it != for_ls_ia.end(); ++it) { std::cout << *it << std::endl; }

  std::cout << std::endl << "Exercise 9.28" << std::endl;
  std::forward_list<std::string> for_ls_str{"hi", "there", "how", "are", "you"};
  std::string str_to_find1 = "how";
  std::string str_to_find2 = "ho";
  std::string str_to_insert = "good";

  InsertForwardList(for_ls_str, str_to_find1, str_to_insert);
  InsertForwardList(for_ls_str, str_to_find2, str_to_insert);

  std::cout << std::endl << "Exercise 9.41" << std::endl;
  std::vector<char> vec_ch{'a', 'b', 'c', 'd'};
  std::string str_ch(vec_ch.data(), vec_ch.size());
  std::cout << str_ch << std::endl;

  std::cout << std::endl << "Exercise 9.43" << std::endl;
  std::string s = "MC drive tho increase profits tho promotion";
  std::string old_val = "tho";
  std::string new_val = "through";
  InsertAndEraseString(s, old_val, new_val);

  std::cout << std::endl << "Exercise 9.44" << std::endl;
  ReplaceString(s, old_val, new_val);

  std::cout << std::endl << "Exercise 9.45" << std::endl;
  std::string full_name = FullName("Elizabeth", "Queen", "II");
  std::cout << full_name << std::endl;

  std::cout << std::endl << "Exercise 9.46" << std::endl;
  std::string full_name2 = FullName2("Elizabeth", "Queen", "II");
  std::cout << full_name2 << std::endl;

  std::cout << std::endl << "Exercise 9.47" << std::endl;
  std::string s_find = "ab2c3d7R4E6";
  std::string s_all_int = "0123456789";
  int int_pos = s_find.find_first_of(s_all_int);
  std::string s_int, s_letter;
  if (int_pos >= 0) {
    s_int += s_find[int_pos];
    for (int i = 0; i < s_find.size(); ++i) {
      int left_int_pos = s_find.substr(int_pos + 1).find_first_of(s_all_int);
      if (left_int_pos >= 0) {
        int_pos += left_int_pos + 1;
        s_int += s_find[int_pos];
      }
    }
  }
  std::cout << "Numbers are: " << s_int << std::endl;
  int letter_pos = s_find.find_first_not_of(s_all_int);
  if (letter_pos >= 0) {
    s_letter += s_find[letter_pos];
    for (int i = 0; i < s_find.size(); ++i) {
      int left_letter_pos = s_find.substr(letter_pos + 1).find_first_not_of(s_all_int);
      if (left_letter_pos >= 0) {
        letter_pos += left_letter_pos + 1;
        s_letter += s_find[letter_pos];
      }
    }
  }
  std::cout << "Letters are: " << s_letter << std::endl;

  std::cout << std::endl << "Exercise 9.49" << std::endl;
  std::string ascender_or_descender = "bdfhkltgjpqy";
  // std::string test_str = "bsdhcvsyvncsleqbvaowacunmvnwnndld";
  std::string test_str = "vaowacunmvnwnnbcazumnocvaowacunmvnwnn";

  int max_length = 0;
  std::string qulified_letters;
  for (int i = 0; i < test_str.size(); ++i) {
    int sub_index = test_str.substr(i).find_first_of(ascender_or_descender);
    if (max_length > 0 && sub_index == std::string::npos) {
      max_length = test_str.substr(i).size();
      qulified_letters = test_str.substr(i);
      break;
    }
    if (sub_index > max_length) {
      max_length = sub_index;
      qulified_letters = test_str.substr(i).substr(0, sub_index);
    }
  }
  std::cout << qulified_letters << std::endl;

  std::cout << std::endl << "Exercise 9.50" << std::endl;
  std::vector<std::string> num_str{"15", "50", "78"};
  int sum_int = 0;
  for (auto i : num_str) { sum_int += stoi(i); }
  std::cout << sum_int << std::endl;
  double sum_double = 0.0;
  for (auto i : num_str) { sum_double += stod(i); }
  std::cout << sum_double << std::endl;
  return 0;
}
