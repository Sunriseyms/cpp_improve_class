#include <iostream>
#include <string>
#include <vector>

// "Exercise 7.23";
class Screen {
  // "Exercise 7.24";
 public:
  Screen() = default;
  Screen(const int w, const int h) : w_(w), h_(h), contents_(w * h, ' ') {}
  Screen(const int w, const int h, const char c) : w_(w), h_(h), contents_(w * h, c) {}

 private:
  int w_;
  int h_;
  std::string contents_;
};

int main() {
  std::cout << std::endl << "Exercise for class Screen" << std::endl;

  return 0;
}
