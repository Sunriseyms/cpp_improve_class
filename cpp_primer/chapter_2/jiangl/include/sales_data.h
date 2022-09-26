#ifndef CPP_IMPROVE_CLASS_CPP_PRIMER_CHAPTER_2_JIANGL_INCLUDE_SALES_DATA_H_
#define CPP_IMPROVE_CLASS_CPP_PRIMER_CHAPTER_2_JIANGL_INCLUDE_SALES_DATA_H_

#include <string>
#include <iostream>

class sales_data {
    friend std::istream& operator >> (std::istream&, sales_data&);
    friend std::ostream& operator << (std::istream&, sales_data&);
    friend bool operator == (const sales_data& data1, const sales_data& data2);
    friend int operator + (const sales_data& data1, const sales_data& data2);
 public:
    sales_data() = default;
 public:
    int sold_num = 0;
    std::string get_isdn() const {
      return isdn;
    }
 private:
    std::string isdn = "Unknown";
};

std::istream& operator >> (std::istream& in, sales_data& data) {
  in >> data.isdn >> data.sold_num;
  return in;
}

std::ostream& operator << (std::ostream& out, const sales_data& data) {
  out << data.get_isdn() <<" "<<  data.sold_num;   // question
  return out;
}

inline bool operator == (const sales_data& data1, const sales_data& data2) {
  return data1.isdn == data2.isdn;
}

inline int operator + (const sales_data& data1, const sales_data& data2) {
  if (data1.isdn == data2.isdn) {
    return data1.sold_num + data2.sold_num;
  } else {
    std::cout << "(ISDN is different! The second data is ignored! )" << std::endl;
    return data1.sold_num;
  }
}

#endif  // CPP_IMPROVE_CLASS_CPP_PRIMER_CHAPTER_2_JIANGL_INCLUDE_SALES_DATA_H_
