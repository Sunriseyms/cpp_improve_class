#include <iostream>
#include "Sales_data.h"

#define exe_1_20 false
#define exe_1_21 false
#define exe_1_22 false
#define exe_1_23 false
#define exe_1_25 true

int main() {
  if (exe_1_20) {
    std::cout << "============ex.1.20============" << std::endl;
    std::cout << "Please enter a SalesData (ISBN, sold numbers, price)" << std::endl;
    SalesData book;
    double price = 0.0;
    while (std::cin >> book.book_no >> book.units_sold >> price) {
      book.revenue = book.units_sold * price;
      std::cout << book.book_no << "  " << book.units_sold << "  " << book.revenue << "  "
                << book.revenue / book.units_sold << std::endl;
    }
  }

  if (exe_1_21) {
    std::cout << "============ex.1.21============" << std::endl;
    std::cout << "Please enter TWO SalesDatas (ISBN, sold numbers, price)" << std::endl;
    SalesData item1, item2;
    double price1 = 0.0, price2 = 0.0;
    std::cin >> item1.book_no >> item1.units_sold >> price1;
    item1.revenue = item1.units_sold * price1;
    std::cin >> item2.book_no >> item2.units_sold >> price2;
    item2.revenue = item2.units_sold * price2;
    if (item1.book_no == item2.book_no) {
      double total_revenue = item1.revenue + item2.revenue;
      double total_unit = item1.units_sold + item2.units_sold;
      double average = total_revenue / total_unit;
      std::cout << "item1 + item2 = " << item1.book_no << "  " << total_unit << "  " << total_revenue << "  " << average
                << std::endl;
    }
  }

  if (exe_1_22) {
    std::cout << "============ex.1.22============" << std::endl;
    SalesData item_sum, item;
    std::string curr_isbn;
    double item_price = 0.0;
    if (std::cin >> item.book_no >> item.units_sold >> item_price) {
      item.revenue = item.units_sold * item_price;
      curr_isbn = item.book_no;
      item_sum = item;
      while (std::cin >> item.book_no >> item.units_sold >> item_price) {
        if (item.book_no.c_str() == curr_isbn) {
          item_sum.units_sold += item.units_sold;
          item_sum.revenue += item.units_sold * item_price;
        }
      }
      std::cout << "item_sum is " << item_sum.book_no << "  " << item_sum.units_sold << "  " << item_sum.revenue << "  "
                << item_sum.revenue / item_sum.units_sold << std::endl;
    }
  }

  if (exe_1_23) {
    std::cout << "============ex.1.23============" << std::endl;
    std::cout << "Please enter a SalesData (ISBN, sold numbers, price)" << std::endl;
    SalesData curr_item, item;
    std::string curr_ibsn;
    double item_price = 0.0;
    if (std::cin >> item.book_no >> item.units_sold >> item_price) {
      int count = 1;
      curr_ibsn = item.book_no;
      while (std::cin >> item.book_no >> item.units_sold >> item_price) {
        if (item.book_no == curr_ibsn) {
          count++;
        } else {
          std::cout << "ISBN" << curr_ibsn << " has " << count << " sales records." << std::endl;
          curr_ibsn = item.book_no;
          count = 1;
        }
      }
      std::cout << "ISBN" << curr_ibsn << " has " << count << " sales records." << std::endl;
    }
  }

  if (exe_1_25) {
    std::cout << "============ex.1.25============" << std::endl;
    std::cout << "Please enter a SalesData (ISBN, sold numbers, price)" << std::endl;
    SalesData total;  // variable to hold data for the next transaction
                      // read the first transaction and ensure that there are data to process
    double price = 0.0;
    if (std::cin >> total.book_no >> total.units_sold >> price) {
      total.revenue = total.units_sold * price;
      SalesData trans;  // variable to hold the running sum
      // read and process the remaining transactions
      double trans_price = 0.0;
      while (std::cin >> trans.book_no >> trans.units_sold >> trans_price) {
        trans.revenue = trans.units_sold * trans_price;
        // if we're still processing the same book
        if (total.book_no == trans.book_no) {
          total.revenue += trans.revenue;  // update the running total
          total.units_sold += trans.units_sold;
        } else {
          // print results for the previous book
          std::cout << "total is " << total.book_no << "  " << total.units_sold << "  " << total.revenue << "  "
                    << total.revenue / total.units_sold << std::endl;
          total = trans;
          // total now refers to the next book
        }
      }
      std::cout << "total is " << total.book_no << "  " << total.units_sold << "  " << total.revenue << "  "
                << total.revenue / total.units_sold << std::endl;  // print the last transaction
    } else {
      // no input! warn the user
      std::cerr << "No data?!" << std::endl;
      return -1;
      // indicate failure
    }
  }

  return 0;
}
