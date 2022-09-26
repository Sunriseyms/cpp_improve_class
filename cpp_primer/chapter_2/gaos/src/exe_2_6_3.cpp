#include <iostream>
#include "Sales_data.h"

#define exe_1_20 false
#define exe_1_21 false
#define exe_1_22 true
#define exe_1_23 false
#define exe_1_25 false

int main() {
  if (exe_1_20) {
    std::cout << "============ex.1.20============" << std::endl;
    std::cout << "Please enter a SalesData (ISBN, sold numbers, price)" << std::endl;
    SalesData book;
    double price = 0.0;
    while (book.GetMessage()) {
      // book.revenue = book.units_sold * price;
      book.PrintMessage();
    }
  }

  if (exe_1_21) {
    std::cout << "============ex.1.21============" << std::endl;
    std::cout << "Please enter TWO SalesDatas (ISBN, sold numbers, price)" << std::endl;
    SalesData item1, item2;
    double price1 = 0.0, price2 = 0.0;
    item1.GetMessage();
    item2.GetMessage();
    item1.AddMessage(item2);
    item1.PrintMessage();
    // if (item1.book_no == item2.book_no) {
    //   double total_revenue = item1.revenue + item2.revenue;
    //   double total_unit = item1.units_sold + item2.units_sold;
    //   double average = total_revenue / total_unit;
    //   std::cout << "item1 + item2 = " << item1.book_no << "  " << total_unit << "  " << total_revenue << "  " <<
    //   average
    //             << std::endl;
    // }
  }

  if (exe_1_22) {
    std::cout << "============ex.1.22============" << std::endl;
    SalesData item_sum, item;
    std::string curr_isbn;
    double item_price = 0.0;
    if (item.GetMessage()) {
      // item.revenue = item.units_sold * item_price;
      curr_isbn = item.book_no;
      item_sum = item;
      while (item.GetMessage()) { item_sum.AddMessage(item); }
      std::cout << "item_sum is ";
      item_sum.PrintMessage();
    }
  }

  if (exe_1_23) {
    std::cout << "============ex.1.23============" << std::endl;
    std::cout << "Please enter a SalesData (ISBN, sold numbers, price)" << std::endl;
    SalesData curr_item, item;
    std::string curr_ibsn;
    double item_price = 0.0;
    if (item.GetMessage()) {
      int count = 1;
      curr_ibsn = item.book_no;
      while (item.GetMessage()) {
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
    // double price = 0.0;
    if (total.GetMessage()) {
      // total.revenue = total.units_sold * price;
      SalesData trans;  // variable to hold the running sum
      // read and process the remaining transactions
      // double trans_price = 0.0;
      while (trans.GetMessage()) {
        // trans.revenue = trans.units_sold * trans_price;
        // if we're still processing the same book
        if (total.book_no == trans.book_no) {
          total.AddMessage(trans);
        } else {
          // print results for the previous book
          std::cout << "total is ";
          total.PrintMessage();
          total = trans;
          // total now refers to the next book
        }
      }
      std::cout << "total is ";
      total.PrintMessage();
    } else {
      // no input! warn the user
      std::cerr << "No data?!" << std::endl;
      return -1;
      // indicate failure
    }
  }

  return 0;
}
