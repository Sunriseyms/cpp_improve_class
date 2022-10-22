#include <iostream>
#include <string>
#include "Chapter6.h"

void SwapIntByPtr(int* ptr1, int* ptr2) {
  int temp = *ptr1;
  *ptr1 = *ptr2;
  *ptr2 = temp;
}

void Reset(int& num) { num = 0; }

void SwapIntByPtr(int& num1, int& num2) {
  int temp = num1;
  num1 = num2;
  num2 = temp;
}

bool IfContainCap(const std::string& str) {
  for (auto c : str) {
    if (isupper(c)) { return true; }
  }
  return false;
}

std::string LowerStr(std::string& str) {
  for (auto& c : str) {
    if (isupper(c)) { c = tolower(c); }
  }
  return str;
}

int CompareIntAndPointedInt(int num, int* ptr) {
  int pointed_num = *ptr;
  return std::max(num, pointed_num);
}

void SwapTwoIntPtr(int*& ptr1, int*& ptr2) {
  int* temp = ptr1;
  ptr1 = ptr2;
  ptr2 = temp;
}

void Print(const int i) { std::cout << i << std::endl; }

void Print(const int (&arr)[2]) {
  for (auto i : arr) { std::cout << i << std::endl; }
}

int main() {
  std::cout << std::endl << "Exercise 6.8" << std::endl;
  std::cout << "Header Chapter6.h added" << std::endl;

  std::cout << std::endl << "Exercise 6.10" << std::endl;
  int num1 = 10, num2 = 20;
  std::cout << "Before swapping, num1 and num to is: " << num1 << " and " << num2 << std::endl;
  int* ptr1 = &num1;
  int* ptr2 = &num2;
  SwapIntByPtr(ptr1, ptr2);
  std::cout << "Before swapping, num1 and num to is: " << num1 << " and " << num2 << std::endl;

  std::cout << std::endl << "Exercise 6.11" << std::endl;
  int num_to_reset = 100;
  std::cout << "Before reset, num is: " << num_to_reset << std::endl;
  Reset(num_to_reset);
  std::cout << "Before reset, num is: " << num_to_reset << std::endl;

  std::cout << std::endl << "Exercise 6.12" << std::endl;
  std::cout << "Before swapping, num1 and num to is: " << num1 << " and " << num2 << std::endl;
  int& r1 = num1;
  int& r2 = num2;
  SwapIntByPtr(r1, r2);
  std::cout << "Before swapping, num1 and num to is: " << num1 << " and " << num2 << std::endl;

  std::cout << std::endl << "Exercise 6.17" << std::endl;
  std::string all_lower_str = "hey you";
  std::string lower_and_upper_str = "Hi There";
  std::cout << all_lower_str << " contains uppercase char: " << IfContainCap(all_lower_str) << std::endl;
  std::cout << lower_and_upper_str << " contains uppercase char: " << IfContainCap(lower_and_upper_str) << std::endl;
  std::cout << "convert all chars in " << all_lower_str << " to lowercase: " << LowerStr(all_lower_str) << std::endl;
  std::cout << "convert all chars in " << lower_and_upper_str << " to lowercase: " << LowerStr(lower_and_upper_str)
            << std::endl;

  std::cout << std::endl << "Exercise 6.21" << std::endl;
  int i1 = 10;
  int i2 = 20;
  int large = CompareIntAndPointedInt(i1, &i2);
  std::cout << "the larger int between " << i1 << " and " << i2 << " is: " << large << std::endl;

  std::cout << std::endl << "Exercise 6.22" << std::endl;
  int* p1 = &i1;
  int* p2 = &i2;
  std::cout << "Besfore swap ptr1 point to " << *p1 << ", address is: " << p1 << " ptr1 point to " << *p2
            << ", address is: " << p2 << std::endl;
  SwapTwoIntPtr(p1, p2);
  std::cout << "After swap ptr1 point to " << *p1 << ", address is: " << p1 << " ptr1 point to " << *p2
            << ", address is: " << p2 << std::endl;

  std::cout << std::endl << "Exercise 6.23" << std::endl;
  int i = 0;
  Print(i);
  int j[2] = {0, 1};
  Print(j);


  return 0;
}
