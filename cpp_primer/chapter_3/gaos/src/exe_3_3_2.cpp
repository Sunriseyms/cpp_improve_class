#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

#define exe_3_14 false
#define exe_3_15 true

int main() {
  if (exe_3_14) {
    cout << "============ex.3.14============" << endl;
    cout << "please input numbers" << endl;
    vector<int> v;
    int tmp;
    while (cin >> tmp) { v.push_back(tmp); }
  }

  if (exe_3_15) {
    cout << "============ex.3.15============" << endl;
    cout << "please input strings" << endl;
    vector<string> v;
    string tmp;
    while (cin >> tmp) { v.push_back(tmp); }
  }

  return 0;
}
