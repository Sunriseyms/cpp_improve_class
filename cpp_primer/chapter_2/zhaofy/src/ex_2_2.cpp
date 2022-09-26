#include "sales_data.h"

int main() {
  std::cout << "============ex.2.6.2============" << std::endl;
  std::cout << "------------ex.1.20------------" << std::endl;
  std::cout << "Please enter a Sales_data(book number, sold numbers, unit price)" << std::endl;
  Sales_data book;
  while (std::cin >> book.book_no >> book.units_sold >> book.units_price) {
    std::cout << "Book number is " << book.book_no << std::endl;
    std::cout << "Sold numbers is " << book.units_sold << std::endl;
    std::cout << "Unit price is " << book.units_price << std::endl;
    std::cout << "Total revenue is " << book.units_sold * book.units_price << std::endl;
  }

  std::cout << "------------ex.1.21------------" << std::endl;
  std::cout << "Please enter TWO Sales_data(book_no, sold_numbers, price)" << std::endl;
  Sales_data item1, item2;
  std::cin >> item1.book_no >> item1.units_sold >> item1.units_price >> item2.book_no >> item2.units_sold >>
      item2.units_price;
  if (item1.book_no == item2.book_no) {
    std::cout << "Total revenue is = " << item1.units_sold * item1.units_price + item2.units_sold * item2.units_price
              << std::endl;
  }

  std::cout << "------------ex.1.22------------" << std::endl;
  Sales_data item_sum, item;
  std::string curr_isbn;
  std::cout << "Please enter TWO Sales_data(book_no, sold_numbers, price)" << std::endl;
  if (std::cin >> item.book_no >> item.units_sold >> item.units_price) {
    curr_isbn = item.book_no;
    while (std::cin >> item.book_no) {
      if (item.book_no == curr_isbn) { item_sum.revenue += item.units_sold * item.units_price; }
    }
    std::cout << "Total item revenue is " << item_sum.revenue << std::endl;
  }

  std::cout << "------------ex.1.23------------" << std::endl;
  std::cout << "Please enter TWO Sales_data(book_no, sold_numbers, price)" << std::endl;
  Sales_data curr_item, item0;
  std::string curr_ibsn;
  if (std::cin >> curr_item.book_no) {
    int count = 1;
    curr_ibsn = curr_item.book_no;
    while (std::cin >> item0.book_no) {
      if (item0.book_no == curr_ibsn) {
        count++;
      } else {
        std::cout << "ISBN" << curr_ibsn << " has " << count << " sales records." << std::endl;
        curr_ibsn = item0.book_no;
        count = 1;
      }
    }
    std::cout << "ISBN" << curr_ibsn << " has " << count << " sales records." << std::endl;
  }

  return 0;
}
