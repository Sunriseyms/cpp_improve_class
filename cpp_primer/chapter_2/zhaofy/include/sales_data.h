#ifndef PX_ARM_CPP_PRIMER_CHAPTER_2_ZHAOFY_INCLUDE_SALES_DATA_H_
#define PX_ARM_CPP_PRIMER_CHAPTER_2_ZHAOFY_INCLUDE_SALES_DATA_H_

#include <iostream>
#include <string>

struct Sales_data {
  std::string book_no;
  unsigned units_sold = 0;
  double units_price = 0.0;
  double revenue = 0.0;
};

#endif  // PX_ARM_CPP_PRIMER_CHAPTER_2_ZHAOFY_INCLUDE_SALES_DATA_H_
