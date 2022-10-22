#include <iostream>
#include <string>
#include <vector>

void RecurseVector(std::vector<int> vec) {
#ifndef NDEBUG
  std::cout << "vector size is: " << vec.size() << std::endl;
#endif
  if (vec.size() > 0) {
    std::cout << vec[0] << std::endl;
    if (vec.size() > 1) {
      vec.erase(vec.begin());
      RecurseVector(vec);
    }
  }
}

void F() { std::cout << "f 1 is called\n"; }
void F(int i) { std::cout << "f 2 is called\n"; }
void F(int i1, int i2) { std::cout << "f 3 is called\n"; }
void F(double d1, double d2 = 3.14) { std::cout << "f 4 is called\n"; }

int FuncAdd(int num1, int num2) { return num1 + num2; }
int FuncSub(int num1, int num2) { return num1 - num2; }
int FuncMul(int num1, int num2) { return num1 * num2; }
int FuncDiv(int num1, int num2) {
  if (num2 == 0) {
    return 1000000;
  } else {
    return num1 / num2;
  }
}

void Calc(int num1, int num2, int (*pf)(int, int)) { std::cout << pf(num1, num2) << std::endl; }

int main() {
  std::cout << std::endl << "Exercise 6.47" << std::endl;
  std::vector<int> vec{0, 1, 2, 3, 4, 5};
  RecurseVector(vec);

  std::cout << std::endl << "Exercise 6.51" << std::endl;
  // f(2.56, 42);
  F(42);
  F(42, 0);
  F(2.56, 3.14);

  std::cout << std::endl << "Exercise 6.54+55+56" << std::endl;
  decltype(FuncAdd)*p_add = FuncAdd, *p_sub = FuncSub, *p_mul = FuncMul, *p_div = FuncDiv;
  std::vector<decltype(FuncAdd)*> fun_ptr_vec = {p_add, p_sub, p_mul, p_div};
  int num1 = 2, num2 = 5;
  for (auto pf : fun_ptr_vec) { Calc(num1, num2, pf); }
  return 0;
}
