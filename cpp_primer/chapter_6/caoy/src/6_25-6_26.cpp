#include <iostream>
#include <string>

int main(int argc, char** argv) {
  std::cout << std::endl << "Exercise 6.25" << std::endl;
  if (argc > 1) {
    std::string a1 = argv[1];
    std::string a2 = argv[2];
    std::cout << a1 + a2 << std::endl;
  } else {
    std::cout << "Not enough arg passed\n";
  }

  std::cout << std::endl << "Exercise 6.26" << std::endl;
  if (argc > 1) {
    for (int i = 1; i < argc; ++i) { std::cout << argv[i] << std::endl; }
  } else {
    std::cout << "Not enough arg passed\n";
  }

  return 0;
}
