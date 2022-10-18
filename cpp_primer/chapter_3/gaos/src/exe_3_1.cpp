#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  cout << "============ex.1.9============" << endl;
  int sum = 0, val = 100;
  while (val >= 50) {
    sum += val;
    val--;
  }
  cout << "Sum of 50 to 100 inclusive is " << sum << endl;

  cout << "============ex.1.10============" << endl;
  cout << "print each number from 10 to 0 " << endl;
  int sum1 = 0, val1 = 10;
  while (val1 >= 0) {
    cout << val1 << endl;
    val1--;
  }

  cout << "============ex.1.11============" << endl;
  cout << "Please enter two integers " << endl;
  int num1, num2;
  cin >> num1 >> num2;
  int upper = std::max(num1, num2);
  int lower = std::min(num1, num2);
  cout << "print each number from " << lower << " to " << upper << endl;
  while (lower <= upper) {
    cout << lower << endl;
    lower++;
  }

  return 0;
}
