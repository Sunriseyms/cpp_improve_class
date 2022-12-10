#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

// 12.2
class SaleData {
  friend std::ostream& operator<<(std::ostream& os, const SaleData sale_data);
  friend std::istream& operator>>(std::istream& is, SaleData& sale_data);

 public:
  SaleData() = default;
  SaleData(std::string book_id, int unit_sold, double revenue)
      : book_id_(book_id), unit_sold_(unit_sold), revenue_(revenue) {}
  std::string Isbn() const { return book_id_; }
  double AvgPrice() const {
    if (unit_sold_) {
      return revenue_ / unit_sold_;
    } else {
      return 0.0;
    }
  }
  SaleData operator+=(const SaleData& rhs) {
    this->unit_sold_ += rhs.unit_sold_;
    this->revenue_ += rhs.revenue_;
    return *this;
  }
  // 12.13
  SaleData operator-=(const SaleData& rhs);

  SaleData& operator=(const std::string& book_id) {
    book_id_ = book_id;
    return *this;
  }

  operator std::string() const { return book_id_; }
  operator double() const { return revenue_; }

 private:
  std::string book_id_ = "";
  int unit_sold_ = 0;
  double revenue_ = 0.0;
};

std::ostream& operator<<(std::ostream& os, const SaleData sale_data) {
  os << "isbn: " << sale_data.book_id_ << ", unit sold: " << sale_data.unit_sold_ << ", revenue: " << sale_data.revenue_
     << ", average price: " << sale_data.AvgPrice();
  return os;
}
std::istream& operator>>(std::istream& is, SaleData& sale_data) {
  double unit_price;
  is >> sale_data.book_id_ >> sale_data.unit_sold_ >> unit_price;
  if (is) {
    sale_data.revenue_ = sale_data.unit_sold_ * unit_price;
  } else {
    sale_data = SaleData();
  }
  return is;
}
SaleData operator+(const SaleData& lhs, const SaleData& rhs) {
  SaleData sum(lhs);
  sum += rhs;
  return sum;
}
// 12.13
SaleData operator-(const SaleData& lhs, const SaleData& rhs);

class StrBlob {
  friend bool operator==(const StrBlob& lhs, const StrBlob& rhs);
  friend bool operator>(const StrBlob& lhs, const StrBlob& rhs);

 public:
  typedef std::vector<std::string>::size_type size_type;
  StrBlob();
  StrBlob(std::initializer_list<std::string> il) : data_(std::make_shared<std::vector<std::string>>(il)) {}
  size_type Size() const { return data_->size(); }
  bool Empty() const { return data_->empty(); }
  void PushBack(const std::string& s) { data_->push_back(s); }
  void PopBack();
  std::string& Front();
  const std::string& Front() const;
  std::string& Back();
  const std::string& Back() const;
  std::string operator[](const int i) { return (*data_)[i]; }

 private:
  std::shared_ptr<std::vector<std::string>> data_;
  void Check(size_type i, const std::string& msg) const;
};

bool operator==(const StrBlob& lhs, const StrBlob& rhs) { return *(lhs.data_) == *(rhs.data_); }
bool operator!=(const StrBlob& lhs, const StrBlob& rhs) { return !operator==(lhs, rhs); }
bool operator>(const StrBlob& lhs, const StrBlob& rhs) { return *(lhs.data_) > *(rhs.data_); }
bool operator>=(const StrBlob& lhs, const StrBlob& rhs) { return operator>(lhs, rhs) || operator==(lhs, rhs); }
bool operator<(const StrBlob& lhs, const StrBlob& rhs) { return !operator>=(lhs, rhs); }
bool operator<=(const StrBlob& lhs, const StrBlob& rhs) { return !operator>(lhs, rhs); }

struct IfThenElse {
  int operator()(int i1, int i2, int i3) {
    if (i1 > 0) {
      return i1;
    } else if (i2 > 0) {
      return i2;
    } else {
      return i3;
    }
  }
};

class CharEqual {
 public:
  CharEqual() = default;
  explicit CharEqual(char compare_with) : compare_with_(compare_with) {}
  bool operator()(char i) { return i == compare_with_; }

 private:
  char compare_with_;
};

int main() {
  std::cout << std::endl << "Exercise 12.2" << std::endl;

  std::cout << std::endl << "Exercise 12.6" << std::endl;
  std::cout << SaleData() << std::endl;

  std::cout << std::endl << "Exercise 12.9" << std::endl;
  SaleData sale_data_istream;
  std::cout << "Please enter book isbn unit sold and unit price:" << std::endl;
  std::cin >> sale_data_istream;
  std::cout << sale_data_istream << std::endl;

  std::cout << std::endl << "Exercise 12.16" << std::endl;
  StrBlob str_blob1(std::initializer_list<std::string>{"how", "are", "you"}),
      str_blob2(std::initializer_list<std::string>{"how", "are", "you"}),
      str_blob3(std::initializer_list<std::string>{"how", "are", "yau"});
  std::string equal_res;
  (str_blob1 == str_blob2) ? equal_res = "true" : equal_res = "false";
  std::cout << equal_res << std::endl;
  (str_blob1 != str_blob3) ? equal_res = "false" : equal_res = "true";
  std::cout << equal_res << std::endl;

  std::cout << std::endl << "Exercise 12.18" << std::endl;
  (str_blob3 >= str_blob2) ? equal_res = "false" : equal_res = "true";
  std::cout << equal_res << std::endl;

  std::cout << std::endl << "Exercise 12.20" << std::endl;
  SaleData sd1("a", 10, 100), sd2("a", 5, 200), sd_sum;
  sd_sum = sd1 + sd2;
  std::cout << sd_sum << std::endl;

  std::cout << std::endl << "Exercise 12.22" << std::endl;
  SaleData sd_str;
  sd_str = "abcd";
  std::cout << sd_str << std::endl;

  std::cout << std::endl << "Exercise 12.26" << std::endl;
  std::cout << str_blob2[2] << std::endl;

  std::cout << std::endl << "Exercise 12.34" << std::endl;
  IfThenElse if_then_else;
  std::cout << if_then_else(-2, 3, 5) << std::endl;

  std::cout << std::endl << "Exercise 12.34" << std::endl;
  std::string s1 = "abcedef";
  CharEqual euqal_with('e');
  replace_if(s1.begin(), s1.end(), euqal_with, 'k');
  std::cout << s1 << std::endl;

  std::cout << std::endl << "Exercise 12.45" << std::endl;
  std::string sd_to_str = sd_sum;
  double sd_to_d = sd_sum;
  std::cout << sd_to_str << std::endl;
  std::cout << sd_to_d << std::endl;
  return 0;
}

