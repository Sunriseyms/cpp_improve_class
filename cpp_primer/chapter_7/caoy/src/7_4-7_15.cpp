#include <iostream>
#include <string>
#include <vector>

// "Exercise 7.4";
class Person {
  friend std::istream& Read(std::istream& is, Person& person);

 public:
  // "Exercise 7.15";
  Person() = default;
  Person(const std::string& n, const std::string& a) : name_(n), address_(a) {}
  explicit Person(std::istream& is) { is >> name_ >> address_; }

  // "Exercise 7.5";
  std::string GetName() const { return name_; }
  std::string GetAddress() const { return address_; }

 private:
  std::string name_;
  std::string address_;
};

// "Exercise 7.9";
std::istream& Read(std::istream& is, Person& person) {
  std::string name, addr;
  is >> person.name_ >> person.address_;
  return is;
}

std::ostream& Print(std::ostream& os, const Person& person) {
  os << person.GetName() << " " << person.GetAddress();
  return os;
}

int main() {
  std::cout << std::endl << "Exercise for class Person" << std::endl;

  return 0;
}
