#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

#define exe_3_6 false
#define exe_3_7 true
#define exe_3_8 false
#define exe_3_10 false
#define exe_3_11 false

int main() {
  if (exe_3_6) {
    cout << "============ex.3.6============" << endl;
    cout << "please input a string" << endl;
    string s;
    cin >> s;
    for (auto& c : s) { c = 'X'; }
    cout << s << endl;
  }

  if (exe_3_7) {
    cout << "============ex.3.7============" << endl;
    cout << "please input a string" << endl;
    string s;
    cin >> s;
    for (char& c : s) { c = 'X'; }
    cout << s << endl;
  }

  if (exe_3_8) {
    cout << "============ex.3.8============" << endl;
    cout << "please input a string" << endl;
    string s;
    cin >> s;
    string s_while = s, s_for = s;
    string::iterator iter = s_while.begin();
    while (iter != s_while.end()) {
      *iter = 'X';
      iter++;
    }
    cout << "s_while is " << s_while << endl;
    for (auto iter = s_for.begin(); iter != s_for.end(); iter++) { *iter = 'X'; }
    cout << "s_while is " << s_for << endl;
  }

  if (exe_3_10) {
    cout << "============ex.3.10============" << endl;
    cout << "please input a string" << endl;
    string s;
    cin >> s;
    auto iter = s.begin();
    while (iter != s.end()) {
      if (ispunct(*iter)) { cout << *iter << endl; }
      iter++;
    }
  }

  if (exe_3_11) {
    cout << "============ex.3.11============" << endl;
    cout << "please input a string" << endl;
    const string s = "Keep out!";
    for (auto& c : s) { /* ... */
    }
  }

  return 0;
}
