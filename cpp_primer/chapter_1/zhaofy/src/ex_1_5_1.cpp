#include <iostream>
#include "Sales_item.h"

int main() {
  std::cout << "============ex.1.20============" << std::endl;
  std::cout << "Please enter a Sales_item (ISBN, sold numbers, price)" << std::endl;
  Sales_item book;
  while (std::cin >> book) { std::cout << book << std::endl; }

  std::cout << "============ex.1.21============" << std::endl;
  std::cout << "Please enter TWO Sales_items (ISBN, sold numbers, price)" << std::endl;
  Sales_item item1, item2;
  std::cin >> item1 >> item2;
  if (item1.isbn() == item2.isbn()) { std::cout << "item1 + item2 = " << item1 + item2 << std::endl; }

  std::cout << "============ex.1.22============" << std::endl;
  Sales_item item_sum, item;
  std::string curr_isbn;
  if (std::cin >> item) {
    curr_isbn = item.isbn();
    while (std::cin >> item) {
      if (item.isbn() == curr_isbn) { item_sum += item; }
    }
    std::cout << "item_sum is " << item_sum << std::endl;
  }

  return 0;
}
