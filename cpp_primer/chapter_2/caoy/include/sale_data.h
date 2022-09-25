#ifndef PX_ARM_CPP_PRIMER_CHAPTER_2_CAOY_INCLUDE_SALE_DATA_H_
#define PX_ARM_CPP_PRIMER_CHAPTER_2_CAOY_INCLUDE_SALE_DATA_H_
#include <iostream>
#include <string>
struct SalesData {
  std::string book_no = "";
  int units_sold = 0;
  double unit_cost_price = 0.0;
  double unit_selling_price = 0.0;
  double revenue = 0.0;
};
#endif  // PX_ARM_CPP_PRIMER_CHAPTER_2_CAOY_INCLUDE_SALE_DATA_H_
