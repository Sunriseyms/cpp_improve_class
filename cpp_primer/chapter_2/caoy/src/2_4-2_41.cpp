#include <iostream>
#include <typeinfo>
int main() {
  std::cout << std::endl << "Exercise 2.4" << std::endl;
  unsigned u = 10, u2 = 42;
  std::cout << u2 - u << std::endl;
  std::cout << u - u2 << std::endl;
  int i = 10, i2 = 42;
  std::cout << i2 - i << std::endl;
  std::cout << i - i2 << std::endl;
  std::cout << i - u << std::endl;
  std::cout << u - i << std::endl;

  std::cout << std::endl << "Exercise 2.7" << std::endl;
  std::cout << "2\115\12";
  std::cout << "2\t\115\12";

  std::cout << std::endl << "Exercise 2.18" << std::endl;
  int j = 10, *p1 = &j;
  std::cout << "init ptr p1 is pointing to " << *p1 << ", ptr p1 is: " << p1 << std::endl;
  *p1 = 100;
  std::cout << "change the valuse of object that the pointer point to " << std::endl;
  std::cout << "now ptr p1 is pointing to " << *p1 << ", ptr p1 is: " << p1 << std::endl;
  int k = 100;
  p1 = &k;
  std::cout << "change the pointer value" << std::endl;
  std::cout << "now ptr p1 is pointing to " << *p1 << ", ptr p1 is: " << p1 << std::endl;

  std::cout << std::endl << "Exercise 2.34" << std::endl;
  int ii = 0, &r = ii;
  auto a = r;
  const int ci = ii, &cr = ci;
  auto b = ci;
  auto c = cr;
  auto d = &ii;
  auto e = &ci;
  auto& g = ci;
  std::cout << "before a: " << a << std::endl;
  std::cout << "before b: " << b << std::endl;
  std::cout << "before c: " << c << std::endl;
  std::cout << "before d: " << d << std::endl;
  std::cout << "before e: " << e << std::endl;
  std::cout << "before g: " << g << std::endl;
  a = 42;
  b = 42;
  c = 42;
  // d = 42;
  // e = 42;
  // g = 42;
  std::cout << "after a: " << a << std::endl;
  std::cout << "after b: " << b << std::endl;
  std::cout << "after c: " << c << std::endl;

  std::cout << std::endl << "Exercise 2.35" << std::endl;
  const int iii = 42;
  auto jjj = iii;
  const auto& kkk = iii;
  auto* ppp = &iii;
  const auto jjj2 = iii, &kkk2 = iii;
  std::cout << typeid(iii).name() << std::endl;
  std::cout << typeid(jjj).name() << std::endl;
  std::cout << typeid(kkk).name() << std::endl;
  std::cout << typeid(ppp).name() << std::endl;
  std::cout << typeid(jjj2).name() << std::endl;
  std::cout << typeid(kkk2).name() << std::endl;

  std::cout << std::endl << "Exercise 2.39" << std::endl;
  struct Foo {};
  std::cout << "error: expected ';' after struct definition" << std::endl;

  std::cout << std::endl << "Exercise 2.40" << std::endl;
  struct SalesData {
    std::string book_no = "";
    int units_sold = 0;
    double unit_cost_price = 0.0;
    double unit_selling_price = 0.0;
    double revenue = 0.0;
  };

  std::cout << std::endl << "Exercise 2.41.1" << std::endl;
  std::cout << "Please enter a sale record, format: isbn  number of book sold  unit cost price  unit selling price"
            << std::endl;
  SalesData item;
  std::cin >> item.book_no >> item.units_sold >> item.unit_cost_price >> item.unit_selling_price;
  item.revenue = (item.unit_selling_price - item.unit_cost_price) * item.units_sold;
  std::cout << item.book_no << " " << item.units_sold << " " << item.unit_cost_price << " " << item.unit_selling_price
            << " " << item.revenue << std::endl;

  std::cout << std::endl << "Exercise 2.41.2" << std::endl;
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

  std::cout << std::endl << "Exercise 2.41.3" << std::endl;
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

  std::cout << std::endl << "Exercise 2.41.4" << std::endl;
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
