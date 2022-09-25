#include "sale_data.h"
int main() {
  std::cout << std::endl << "Exercise 2.42.1" << std::endl;
  std::cout << "Please enter a sale record, format: isbn  number of book sold  unit cost price  unit selling price"
            << std::endl;
  SalesData item;
  std::cin >> item.book_no >> item.units_sold >> item.unit_cost_price >> item.unit_selling_price;
  item.revenue = (item.unit_selling_price - item.unit_cost_price) * item.units_sold;
  std::cout << item.book_no << " " << item.units_sold << " " << item.unit_cost_price << " " << item.unit_selling_price
            << " " << item.revenue << std::endl;

  std::cout << std::endl << "Exercise 2.42.2" << std::endl;
  std::cout << "Please enter two sale records, format: isbn  number of book sold  unit cost price  unit selling price"
            << std::endl;
  SalesData item1, item2;
  std::cin >> item1.book_no >> item1.units_sold >> item1.unit_cost_price >> item1.unit_selling_price >> item2.book_no >>
      item2.units_sold >> item2.unit_cost_price >> item2.unit_selling_price;
  item1.revenue = (item1.unit_selling_price - item1.unit_cost_price) * item1.units_sold;
  item2.revenue = (item2.unit_selling_price - item2.unit_cost_price) * item2.units_sold;

  if (item1.book_no == item2.book_no) {
    std::cout << item1.book_no << " " << item1.units_sold + item2.units_sold << " "
              << (item1.units_sold * item1.unit_cost_price + item2.units_sold * item2.unit_cost_price) /
                     (item1.units_sold + item2.units_sold)
              << " "
              << (item1.units_sold * item1.unit_selling_price + item2.units_sold * item2.unit_selling_price) /
                     (item1.units_sold + item2.units_sold)
              << " " << (item1.revenue + item2.revenue) << std::endl;
  } else {
    std::cout << "Book isbn not match, cannot add" << std::endl;
  }

  std::cout << std::endl << "Exercise 2.42.3" << std::endl;
  std::cout
      << "Please enter some sale records, format:  isbn  number of book sold  unit cost price  unit selling price "
      << std::endl;
  SalesData sum, cur_item;
  while (std::cin >> cur_item.book_no >> cur_item.units_sold >> cur_item.unit_cost_price >>
         cur_item.unit_selling_price) {
    cur_item.revenue = (cur_item.unit_selling_price - cur_item.unit_cost_price) * cur_item.units_sold;
    if (sum.units_sold != 0 && sum.book_no != cur_item.book_no) {
      std::cout << "Not match book isbn" << std::endl;
      sum = cur_item;
    } else {
      sum.book_no = cur_item.book_no;
      sum.unit_cost_price = (sum.units_sold * sum.unit_cost_price + cur_item.units_sold * cur_item.unit_cost_price) /
                            (sum.units_sold + cur_item.units_sold);

      sum.unit_selling_price =
          (sum.units_sold * sum.unit_selling_price + cur_item.units_sold * cur_item.unit_selling_price) /
          (sum.units_sold + cur_item.units_sold);
      sum.revenue += cur_item.revenue;
      sum.units_sold += cur_item.units_sold;
    }
  }
  std::cout << std::endl
            << sum.book_no << " " << sum.units_sold << " " << sum.unit_cost_price << " " << sum.unit_selling_price
            << " " << sum.revenue << std::endl;

  std::cout << std::endl << "Exercise 2.42.4" << std::endl;
  std::cout
      << "Please enter some sale records, format:  isbn  number of book sold  unit cost price  unit selling price "
      << std::endl;
  SalesData last_item, new_item;
  int num_data = 0;
  while (std::cin >> new_item.book_no >> new_item.units_sold >> new_item.unit_cost_price >>
         new_item.unit_selling_price) {
    new_item.revenue = (new_item.unit_selling_price - new_item.unit_cost_price) * new_item.units_sold;
    if (num_data != 0 && new_item.book_no != last_item.book_no) {
      std::cout << "sale data for a new book" << std::endl;
      std::cout << std::endl << last_item.book_no << " has " << num_data << " sale data" << std::endl;
      last_item = new_item;
      num_data = 1;
    } else {
      last_item = new_item;
      num_data += 1;
    }
  }
  std::cout << std::endl << last_item.book_no << " has " << num_data << " sale data" << std::endl;
}
