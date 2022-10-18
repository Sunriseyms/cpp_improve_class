#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

#define exe_3_39 false
#define exe_3_40 false

int main() {
  if (exe_3_39) {
    cout << "============ex.3.39============" << endl;
    cout << "please input two strings" << endl;
    string s1, s2;
    cin >> s1 >> s2;
    if (s1 == s2) {
      cout << "two strings are equal" << endl;
    } else {
      cout << "two strings are not equal" << endl;
    }

    char ca1[] = {'C', '+', '+'};
    char ca2[] = {'C', '+', '+'};
    if (0 == strcmp(ca1, ca2)) {
      cout << "two C-style character strings are equal" << endl;
    } else {
      cout << "two C-style character strings are not equal" << endl;
    }
  }

  if (exe_3_40) {
    cout << "============ex.3.40============" << endl;
    char ca1[] = {'A', 'B', 'C'};
    char ca2[] = {'a', 'b', 'c'};
    char ca3[10];
    strcat(ca1, ca2);
    strcpy(ca3, ca1);
    for (auto c : ca3) { cout << c << "  "; }
    cout << endl;
  }

  return 0;
}
