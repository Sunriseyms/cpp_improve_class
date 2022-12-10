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
  double avg_price() const {
    if (unit_sold_) {
      return revenue_ / unit_sold_;
    } else {
      return 0.0;
    }
  }
  SaleData operator+=(const SaleData& rhs);
  // 12.13
  SaleData operator-=(const SaleData& rhs);

 private:
  std::string book_id_ = "";
  int unit_sold_ = 0;
  double revenue_ = 0.0;
};

std::ostream& operator<<(std::ostream& os, const SaleData sale_data) {
  os << "isbn: " << sale_data.book_id_ << ", unit sold: " << sale_data.unit_sold_ << ", revenue: " << sale_data.revenue_
     << ", average price: " << sale_data.avg_price();
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
SaleData operator+(const SaleData& lhs, const SaleData& rhs);
// 12.13
SaleData operator-(const SaleData& lhs, const SaleData& rhs);

class StrBlob {
  friend bool operator==(const StrBlob& lhs, const StrBlob& rhs);

 public:
  typedef std::vector<std::string>::size_type size_type;
  StrBlob();
  StrBlob(std::initializer_list<std::string> il);
  size_type size() const { return data->size(); }
  bool empty() const { return data->empty(); }
  void push_back(const std::string& s) { data->push_back(s); }
  void pop_back();
  std::string& front();
  const std::string& front() const;
  std::string& back();
  const std::string& back() const;

 private:
  std::shared_ptr<std::vector<std::string>> data;
  void check(size_type i, const std::string& msg) const;
};

bool operator==(const StrBlob& lhs, const StrBlob& rhs) {
  bool res = true;
  auto sz1 = lhs.size(), sz2 = rhs.size();
  if (sz1 != sz2) {
    res = false;
  } else {
    if (*(lhs.data) != *(rhs.data)) { res = false; }
  }
  return res;
}
bool operator!=(const StrBlob& lhs, const StrBlob& rhs) {
  bool res = operator==(lhs, rhs);
  return !res;
}
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
  StrBlob str_blob1(std::initializer_list{"how", "are", "you"}), str_blob2(std::initializer_list{"how", "are", "you"}),
      str_blob3(std::initializer_list{"how", "are", "you~"});
  std::string equal_res;
  (str_blob1 == str_blob2) ? equal_res = "true" : equal_res = "false";
  std::cout << equal_res << std::endl;
  (str_blob1 != str_blob3) ? equal_res = "false" : equal_res = "true";
  std::cout << equal_res << std::endl;
  return 0;
}
