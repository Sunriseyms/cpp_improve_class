#ifndef CPP_IMPROVE_CLASS_CPP_PRIMER_CHAPTER_2_GAOS_INCLUDE_SALES_DATA_H_
#define CPP_IMPROVE_CLASS_CPP_PRIMER_CHAPTER_2_GAOS_INCLUDE_SALES_DATA_H_

#include <iostream>
#include <string>

struct SalesData {
  std::string book_no;
  unsigned units_sold = 0;
  double revenue = 0.0;
  bool GetMessage() {
    double price = 0.0;
    if (std::cin >> book_no >> units_sold >> price) {
      revenue = units_sold * price;
      return true;
    }
    return false;
  }
  void PrintMessage() {
    std::cout << book_no << "  " << units_sold << "  " << revenue << "  " << revenue / units_sold << std::endl;
  }
  void AddMessage(const SalesData& msg) {
    if (book_no == msg.book_no) {
      revenue += msg.revenue;
      units_sold += msg.units_sold;
    } else {
      std::cout << "Not same ISBN!" << std::endl;
    }
  }
};
#endif  // CPP_IMPROVE_CLASS_CPP_PRIMER_CHAPTER_2_GAOS_INCLUDE_SALES_DATA_H_
