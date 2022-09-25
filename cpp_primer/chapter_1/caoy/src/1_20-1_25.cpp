#include <iostream>
#include <vector>
#include "Sales_item.h"

int main() {
  std::cout << std::endl << "Exercise 1.20" << std::endl;
  std::cout << "Please enter a sale record, format: isbn  number of book sold  unit price" << std::endl;
  Sales_item item;
  std::cin >> item;
  std::cout << item << std::endl;

  std::cout << std::endl << "Exercise 1.21" << std::endl;
  std::cout << "Please enter two sale records, format: isbn  number of book sold  unit price" << std::endl;
  Sales_item item1, item2;
  std::cin >> item1 >> item2;
  if (item1.isbn() == item2.isbn()) { std::cout << "Sum is: " << item1 + item2 << std::endl; }

  std::cout << std::endl << "Exercise 1.22" << std::endl;
  std::cout << "Please enter some sale records, format: isbn  number of book sold  unit price" << std::endl;
  Sales_item sum, cur_item;
  while (std::cin >> cur_item) { sum += cur_item; }
  std::cout << "Sum is: " << sum << std::endl;

  std::cout << std::endl << "Exercise 1.23" << std::endl;
  std::cout << "Please enter some sale records, format: isbn  number of book sold  unit price" << std::endl;
  Sales_item last_book;
  Sales_item cur_book;
  int count = 1;
  std::vector<int> counts;
  std::vector<std::string> isbns;
  if (std::cin >> cur_book) {
    last_book = cur_book;
    while (std::cin >> cur_book) {
      if (last_book.isbn() == cur_book.isbn()) {
        count += 1;
      } else {
        counts.push_back(count);
        isbns.push_back(last_book.isbn());
        last_book = cur_book;
        count = 1;
      }
    }
    counts.push_back(count);
    isbns.push_back(last_book.isbn());
    int num_book = counts.size();
    for (int i = 0; i < num_book; i++) { std::cout << counts[i] << " records for book: " << isbns[i] << std::endl; }
  }
}
