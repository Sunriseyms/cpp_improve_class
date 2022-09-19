#include <iostream>
#include "Sales_item.h"

int main() {
  std::cout << "============ex.1.23============" << std::endl;
  std::cout << "Please enter a Sales_item (ISBN, sold numbers, price)" << std::endl;
  Sales_item curr_item, item;
  std::string curr_ibsn;
  if (std::cin >> curr_item) {
    int count = 1;
    curr_ibsn = curr_item.isbn();
    while (std::cin >> item) {
      if (item.isbn() == curr_ibsn) {
        count++;
      } else {
        std::cout << "ISBN" << curr_ibsn << " has " << count << " sales records." << std::endl;
        curr_ibsn = item.isbn();
        count = 1;
      }
    }
    std::cout << "ISBN" << curr_ibsn << " has " << count << " sales records." << std::endl;
  }

  return 0;
}
