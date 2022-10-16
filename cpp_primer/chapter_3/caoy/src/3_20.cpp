#include <iostream>
#include <string>
#include <vector>

int main() {
  std::cout << std::endl << "Exercise 3.20" << std::endl;
  int num;
  std::vector<int> num_vec;
  while (std::cin >> num) { num_vec.push_back(num); }
  for (decltype(num_vec.size()) i = 0; i < num_vec.size(); i += 2) {
    if ((i + 1) < num_vec.size()) {
      std::cout << "The sum of number " << i << " and " << i + 1 << " is: " << num_vec[i] + num_vec[i + 1] << std::endl;
    } else {
      std::cout << "Number " << i << " is: " << num_vec[i] << std::endl;
    }
  }

  for (decltype(num_vec.size()) i = 0; i <= (num_vec.size() / 2); i++) {
    if (i < (num_vec.size() / 2)) {
      std::cout << "The sum of number " << i << " and " << (num_vec.size() - 1) - i
                << " is: " << num_vec[i] + num_vec[(num_vec.size() - 1) - i] << std::endl;
    } else {
      std::cout << "Number " << i << " is: " << num_vec[i] << std::endl;
    }
  }

  return 0;
}
