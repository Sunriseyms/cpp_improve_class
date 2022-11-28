#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class HasPtr {
  friend void swap(HasPtr& p1, HasPtr& p2);

 public:
  HasPtr(const std::string& s = std::string()) : ps(new std::string(s)), i(0) {}
  ~HasPtr() { delete ps; }                                         // exercise 13.12
  HasPtr(const HasPtr& p) : ps(new std::string(*p.ps)), i(p.i) {}  // exercise 13.5
  HasPtr& operator=(const HasPtr& p) {
    auto new_ps = new std::string(*p.ps);
    delete ps;
    ps = new_ps;
    i = p.i;
    return *this;
  }  // exercise 13.8

  bool operator<(const HasPtr& p) const { return *ps < *p.ps; }
  void GetPs() { std::cout << *ps << std::endl; }

 private:
  std::string* ps;
  int i;
};

class Numbered {
  friend void f(Numbered);
  friend void f1(const Numbered&);

 public:
  Numbered() { mysn++; }
  Numbered(Numbered& n) { mysn = n.mysn + 1; }

 private:
  static int mysn;
};
int Numbered::mysn = 0;

void f(Numbered s) { std::cout << s.mysn << std::endl; }
void f1(const Numbered& s) { std::cout << s.mysn << std::endl; }

class Employee {
 public:
  Employee() {
    id++;
    GetInfo();
  };
  Employee(const std::string& n) {
    name = n;
    id++;
    GetInfo();
  }
  Employee(Employee& e) {
    name = e.name;
    id++;
    GetInfo();
  }
  Employee& operator=(Employee& e) {
    name = e.name;
    id++;
    GetInfo();
    return *this;
  }

 private:
  void GetInfo() { std::cout << "Name: " << name << ", ID: " << id << std::endl; }

 private:
  static int id;
  std::string name;
};
int Employee::id = 0;

void swap(HasPtr& p1, HasPtr& p2) {
  std::cout << "swap " << *p1.ps << " and " << *p2.ps << std::endl;
  std::swap(p1.ps, p2.ps);
  std::swap(p1.i, p2.i);
  std::cout << "after swap: " << *p1.ps << " and " << *p2.ps << std::endl;
}

int main() {
  std::cout << std::endl << "Exercise 13.5" << std::endl;
  std::string s = "hello";
  HasPtr orig_p(s);
  HasPtr copied_p(orig_p);

  std::cout << std::endl << "Exercise 13.8" << std::endl;
  HasPtr assigned_p = orig_p;

  std::cout << std::endl << "Exercise 13.12" << std::endl;

  std::cout << std::endl << "Exercise 13.17" << std::endl;
  Numbered a, b = a, c = b;
  f(a);
  f(b);
  f(c);
  Numbered a1, b1 = a1, c1 = b1;
  f(a1);
  f(b1);
  f(c1);

  std::cout << std::endl << "Exercise 13.18" << std::endl;
  Employee e1, e2("Judy"), e3("Jack");

  std::cout << std::endl << "Exercise 13.19" << std::endl;
  Employee e4(e2), e5 = e2;

  std::cout << std::endl << "Exercise 13.30" << std::endl;
  HasPtr pa("aaa"), pb("bbb");
  swap(pa, pb);

  std::cout << std::endl << "Exercise 13.31" << std::endl;
  std::vector<HasPtr> p_vec{HasPtr("aaa"), HasPtr("aba"), HasPtr("aaaa"), HasPtr("Aaa")};
  std::sort(p_vec.begin(), p_vec.end());
  for (auto p : p_vec) { p.GetPs(); }
  return 0;
}
