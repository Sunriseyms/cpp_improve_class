#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

#define exe_3_24 false
#define exe_3_25 true

int main() {
  if (exe_3_24) {
    cout << "============ex.3.24============" << endl;
    cout << "please input numbers" << endl;
    vector<int> v;
    int tmp;
    while (cin >> tmp) { v.push_back(tmp); }
    auto begin = v.begin(), end = v.end();
    end--;
    while (begin != end && begin > end) {
      cout << *begin + *end << endl;
      begin++;
      end--;
    }
  }

  if (exe_3_25) {
    cout << "============ex.3.25============" << endl;
    cout << "please input numbers" << endl;
    vector<int> v;
    int tmp;
    while (cin >> tmp) { v.push_back(tmp); }
    auto begin = v.begin(), end = v.end();
    end--;
    while (begin != end && begin > end) {
      cout << *begin + *end << endl;
      begin++;
      end--;
    }
  }

  return 0;
}
