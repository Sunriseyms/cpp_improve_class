#include <iostream>
#include <memory>
#include <string>
#include <vector>

std::vector<int>* NewIntVec() {
  std::vector<int>* p = new std::vector<int>;
  return p;
}
std::vector<int>* FillIntVec(std::vector<int>* p) {
  std::vector<int> input_num{0, 1, 2, 3, 4, 5};
  for (auto i : input_num) { p->push_back(i); }
  return p;
}

std::shared_ptr<std::vector<int>> SpIntVec() {
  std::shared_ptr<std::vector<int>> p = std::make_shared<std::vector<int>>();
  return p;
}
std::shared_ptr<std::vector<int>> FillSpIntVec(std::shared_ptr<std::vector<int>> p) {
  std::vector<int> input_num{0, 1, 2, 3, 4, 5};
  for (auto i : input_num) { p->push_back(i); }
  return p;
}

int main() {
  std::cout << std::endl << "Exercise 12.6" << std::endl;
  std::vector<int>* p_new = NewIntVec();
  p_new = FillIntVec(p_new);
  for (auto i : *p_new) { std::cout << i << std::endl; }
  delete p_new;
  p_new = nullptr;

  std::cout << std::endl << "Exercise 12.7" << std::endl;
  std::shared_ptr<std::vector<int>> p_sp = SpIntVec();
  p_sp = FillSpIntVec(p_sp);
  for (auto i : *p_sp) { std::cout << i << std::endl; }

  std::cout << std::endl << "Exercise 12.26" << std::endl;
  std::allocator<std::string> alloc;
  int n = 5;
  auto const p = alloc.allocate(n);
  std::string s;
  std::string* q;
  q = p;
  std::vector<std::string> strs{"how", "are", "you"};
  for (auto i : strs) { alloc.construct(q++, i); }
  auto occupied = q - p;
  for (int i = 0; i < occupied; ++i) { std::cout << p[i] << std::endl; }
  while (q != p) { alloc.destroy(q--); }
  alloc.deallocate(p, n);
  return 0;
}
