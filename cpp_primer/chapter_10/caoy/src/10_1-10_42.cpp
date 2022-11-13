#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <numeric>
#include <string>
#include <vector>

bool IsShorter(const std::string& s1, const std::string& s2) { return s1.size() < s2.size(); }
class SalesData {
 public:
  SalesData() = default;
  SalesData(const std::string& s) { isbn = s; }
  std::string Isbn() { return isbn; }

 private:
  std::string isbn = "";
};

bool CompareIsbn(SalesData& sales_data1, SalesData& sales_data2) { return sales_data1.Isbn() < sales_data2.Isbn(); }
bool IsStrShort(const std::string s) { return s.size() >= 5; }

void biggies(std::vector<std::string> words, std::vector<std::string>::size_type sz) {
  std::sort(words.begin(), words.end());
  auto unique_end_it = std::unique(words.begin(), words.end());
  words.erase(unique_end_it, words.end());
  std::stable_sort(
      words.begin(), words.end(), [](const std::string& s1, const std::string& s2) { return s1.size() < s2.size(); });
  auto end_true_it = std::partition(words.begin(), words.end(), [sz](const std::string s) { return s.size() < sz; });
  auto count = words.end() - end_true_it;
  std::cout << count << " " << ((count > 1) ? "words" : "word") << " of length " << sz << " or longer" << std::endl;
  std::for_each(end_true_it, words.end(), [](const std::string& s) { std::cout << s << std::endl; });
}
void biggies2(std::vector<std::string> words, std::vector<std::string>::size_type sz) {
  std::stable_sort(words.begin(), words.end());
  auto unique_end_it = std::unique(words.begin(), words.end());
  words.erase(unique_end_it, words.end());
  std::stable_sort(
      words.begin(), words.end(), [](const std::string& s1, const std::string& s2) { return s1.size() < s2.size(); });
  auto end_true_it =
      std::stable_partition(words.begin(), words.end(), [sz](const std::string s) { return s.size() < sz; });
  auto count = words.end() - end_true_it;
  std::cout << count << " " << ((count > 1) ? "words" : "word") << " of length " << sz << " or longer" << std::endl;
  std::for_each(end_true_it, words.end(), [](const std::string& s) { std::cout << s << std::endl; });
}

bool IsShorterOrEqualsToSix(const std::string& s) { return s.size() <= 6; }

bool CheckSize(const int i, std::string::size_type sz) { return i >= sz; }
bool CheckSize2(const std::string& s, std::string::size_type sz) { return s.size() >= sz; }

void biggies3(std::vector<std::string> words, std::vector<std::string>::size_type sz) {
  std::stable_sort(words.begin(), words.end());
  auto unique_end_it = std::unique(words.begin(), words.end());
  words.erase(unique_end_it, words.end());
  std::stable_sort(
      words.begin(), words.end(), [](const std::string& s1, const std::string& s2) { return s1.size() < s2.size(); });
  auto end_true_it = std::find_if(words.begin(), words.end(), std::bind(CheckSize2, std::placeholders::_1, sz));
  auto count = words.end() - end_true_it;
  std::cout << count << " " << ((count > 1) ? "words" : "word") << " of length " << sz << " or longer" << std::endl;
  std::for_each(end_true_it, words.end(), [](const std::string& s) { std::cout << s << std::endl; });
}

int main() {
  std::cout << std::endl << "Exercise 10.1" << std::endl;
  std::vector<int> input_int_vec{2, 5, 6, 3, 4, 5, 9, 7, 5, 6};
  std::cout << std::count(input_int_vec.cbegin(), input_int_vec.cend(), 5) << " '5' in the input int vector"
            << std::endl;

  std::cout << std::endl << "Exercise 10.2" << std::endl;
  std::list<std::string> input_str_vec{"2", "5", "6", "5", "4", "5", "9", "7", "5", "6"};
  std::cout << std::count(input_str_vec.cbegin(), input_str_vec.cend(), "5") << " '5' in the input string list"
            << std::endl;

  std::cout << std::endl << "Exercise 10.3" << std::endl;
  std::cout << "Sum of int vecctor in exercise 10.1 is: "
            << std::accumulate(input_int_vec.cbegin(), input_int_vec.cend(), 0) << std::endl;

  std::cout << std::endl << "Exercise 10.6" << std::endl;
  std::fill_n(input_int_vec.begin(), input_int_vec.size(), 0);
  std::cout << "New vector with all zeros in exercise 10.1 is: " << std::endl;
  for (auto i : input_int_vec) { std::cout << i << " "; }
  std::cout << std::endl;

  std::cout << std::endl << "Exercise 10.9" << std::endl;
  std::vector<std::string> book_str{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
  std::sort(book_str.begin(), book_str.end());
  auto unique_end_it = std::unique(book_str.begin(), book_str.end());
  book_str.erase(unique_end_it, book_str.end());
  std::cout << "Unique word in book sentence are: " << std::endl;
  for (auto i : book_str) { std::cout << i << " "; }
  std::cout << std::endl;

  std::cout << std::endl << "Exercise 10.11" << std::endl;
  std::stable_sort(book_str.begin(), book_str.end(), IsShorter);
  std::cout << "After stable sort, book sentence is: " << std::endl;
  for (auto i : book_str) { std::cout << i << " "; }
  std::cout << std::endl;

  std::cout << std::endl << "Exercise 10.12" << std::endl;
  std::vector<SalesData> sales_data_vec{SalesData("0123"), SalesData("a123"), SalesData("012"), SalesData("01234")};
  std::cout << "Before sort, book isbns are: " << std::endl;
  for (auto i : sales_data_vec) { std::cout << i.Isbn() << " "; }
  std::cout << std::endl;
  std::sort(sales_data_vec.begin(), sales_data_vec.end(), CompareIsbn);
  std::cout << "After sort, book isbns are: " << std::endl;
  for (auto i : sales_data_vec) { std::cout << i.Isbn() << " "; }
  std::cout << std::endl;

  std::cout << std::endl << "Exercise 10.13" << std::endl;
  std::vector<std::string> words{"fox", "jumps", "over", "the", "turtle"};
  auto end_true_it = std::partition(words.begin(), words.end(), IsStrShort);
  std::cout << "length greater or equals to 5 words are: " << std::endl;
  for (auto it = words.begin(); it != end_true_it; ++it) { std::cout << *it << " "; }
  std::cout << std::endl;

  std::cout << std::endl << "Exercise 10.14" << std::endl;
  int int1 = 5, int2 = 6;
  auto f = [](const int i1, const int i2) { return i1 + i2; };
  std::cout << f(5, 6) << std::endl;
  std::cout << std::endl << "Exercise 10.15" << std::endl;
  auto f2 = [int1](const int i2) { return int1 + i2; };
  std::cout << f2(7) << std::endl;

  std::cout << std::endl << "Exercise 10.17" << std::endl;
  std::vector<SalesData> sales_data_vec2{SalesData("0123"), SalesData("a123"), SalesData("012"), SalesData("01234")};
  std::cout << "Before sort, book isbns are: " << std::endl;
  for (auto i : sales_data_vec2) { std::cout << i.Isbn() << " "; }
  std::cout << std::endl;
  std::sort(sales_data_vec2.begin(), sales_data_vec2.end(), [](SalesData& sales_data1, SalesData& sales_data2) {
    return sales_data1.Isbn() < sales_data2.Isbn();
  });
  std::cout << "After sort, book isbns are: " << std::endl;
  for (auto i : sales_data_vec2) { std::cout << i.Isbn() << " "; }
  std::cout << std::endl;

  std::cout << std::endl << "Exercise 10.18" << std::endl;
  std::vector<std::string> biggies_vec{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
  biggies(biggies_vec, 4);

  std::cout << std::endl << "Exercise 10.19" << std::endl;
  std::vector<std::string> biggies_vec2{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
  biggies2(biggies_vec2, 4);

  std::cout << std::endl << "Exercise 10.20" << std::endl;
  int ctr = std::count_if(biggies_vec2.begin(), biggies_vec2.end(), [](const std::string& s) { return s.size() >= 6; });
  std::cout << ctr << " " << ((ctr > 1) ? "words" : "word") << " of length 6 or longer" << std::endl;

  std::cout << std::endl << "Exercise 10.21" << std::endl;
  int local_int = 3;
  auto f_sub = [&local_int]() -> bool {
    if (local_int == 0) {
      return true;
    } else {
      while (local_int > 0) { local_int--; }
      return false;
    }
  };
  std::cout << "before: " << local_int << (f_sub() ? ", it is zero" : ", it's not zero") << ", after: " << local_int
            << std::endl;
  std::cout << "before: " << local_int << (f_sub() ? ", it is zero" : ", it's not zero") << ", after: " << local_int
            << std::endl;

  std::cout << std::endl << "Exercise 10.22" << std::endl;
  int ctr2 = std::count_if(biggies_vec2.begin(), biggies_vec2.end(), IsShorterOrEqualsToSix);
  std::cout << ctr2 << " " << ((ctr2 > 1) ? "words" : "word") << " of length 6 or shorter" << std::endl;

  std::cout << std::endl << "Exercise 10.24" << std::endl;
  std::string test_str = "abcd";
  std::vector<int> str_size_int_vec{0, 2, 3, 5, 6, 4, 1};
  auto it = std::find_if(
      str_size_int_vec.begin(), str_size_int_vec.end(), std::bind(CheckSize, std::placeholders::_1, test_str.size()));
  std::cout << *it << " is larger than '" << test_str << "''s length" << std::endl;
  ;

  std::cout << std::endl << "Exercise 10.25" << std::endl;
  std::vector<std::string> biggies_vec3{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
  biggies3(biggies_vec3, 4);

  std::cout << std::endl << "Exercise 10.27" << std::endl;
  std::vector<int> vec{1, 2, 5, 3, 4, 3, 5, 2};
  std::list<int> ls;
  std::stable_sort(vec.begin(), vec.end());
  std::unique_copy(vec.begin(), vec.end(), std::back_inserter(ls));
  std::cout << "After unique copy, ls have: " << std::endl;
  for (auto i : ls) { std::cout << i << " "; }
  std::cout << std::endl;

  std::cout << std::endl << "Exercise 10.34" << std::endl;
  std::vector<int> vec_prime{1, 2, 5, 3, 4, 3, 5, 2};
  std::cout << "using reverse iterator, reverse vector {1, 2, 5, 3, 4, 3, 5, 2} are: ";
  for (auto it = vec_prime.rbegin(); it != vec_prime.rend(); ++it) { std::cout << *it << " "; }
  std::cout << std::endl;

  std::cout << std::endl << "Exercise 10.35" << std::endl;
  std::cout << "using regular iterator, reverse vector {1, 2, 5, 3, 4, 3, 5, 2} are: ";
  for (auto it = vec_prime.begin(); it != vec_prime.end(); ++it) {
    std::cout << *(vec_prime.end() - (it - vec_prime.begin()) - 1) << " ";
  }
  std::cout << std::endl;

  std::cout << std::endl << "Exercise 10.36" << std::endl;
  std::list<int> zeros{1, 2, 0, 4, 0, 5, 0, 3, 5};
  auto last_zero_it = std::find_if(zeros.rbegin(), zeros.rend(), [](const int& i) { return (i == 0); });
  std::cout << *last_zero_it << std::endl;
  std::cout << "the int before is: " << *(++last_zero_it) << std::endl;
  std::cout << "the int after is: " << *(--(--last_zero_it)) << std::endl;

  std::cout << std::endl << "Exercise 10.37" << std::endl;
  std::vector<int> ten_vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::list<int> ls_3_to_7;
  std::copy(ten_vec.begin() + 3, ten_vec.begin() + 8, std::front_inserter(ls_3_to_7));
  std::cout << "reverse 3 to 7 are: ";
  for (auto i : ls_3_to_7) { std::cout << i << " "; }
  std::cout << std::endl;

  std::cout << std::endl << "Exercise 10.42" << std::endl;
  std::list<std::string> book_str_ls{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
  book_str_ls.sort();
  book_str_ls.unique();
  std::cout << "Unique word in book sentence are: " << std::endl;
  for (auto i : book_str_ls) { std::cout << i << " "; }
  std::cout << std::endl;
  return 0;
}
