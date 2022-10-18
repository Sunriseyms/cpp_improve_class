#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

#define exe_3_22 true
#define exe_3_23 false

int main() {
  if (exe_3_22) {
    cout << "============ex.3.22============" << endl;
    vector<string> text = {"qq", "ww", "ee", "rr", "tt", "yy", "uu", "ii", "oo", "", "pp", "aa"};
    for (vector<string>::iterator it = text.begin(); it != text.end() && !it->empty(); ++it) {
      for (auto ele = (*it).begin(); ele != (*it).end(); ele++) { cout << static_cast<char>(toupper(*ele)) << "  "; }
    }
    cout << endl;
  }

  if (exe_3_23) {
    cout << "============ex.3.23============" << endl;
    cout << "please input words" << endl;
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto& iter : v) {
      iter *= iter;
      cout << iter << "  ";
    }
    cout << endl;
  }

  return 0;
}
