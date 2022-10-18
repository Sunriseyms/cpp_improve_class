#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

#define exe_3_2 false
#define exe_3_4 true
#define exe_3_5 false

int main() {
  if (exe_3_2) {
    cout << "============ex.3.2============" << endl;
    string word;
    while (cin >> word) { cout << word << endl; }
  }

  if (exe_3_4) {
    cout << "============ex.3.4============" << endl;
    string s1, s2;
    cin >> s1 >> s2;
    if (s1 == s2) {
      cout << "two strings are equal" << endl;
    } else if (s1 > s2) {
      cout << "first string is larger" << endl;
    } else {
      cout << "secend string is larger" << endl;
    }
    unsigned int len1 = s1.size(), len2 = s2.size();
    if (len1 == len2) {
      cout << "two strings are equal" << endl;
    } else if (len1 > len2) {
      cout << "first string is larger" << endl;
    } else {
      cout << "secend string is larger" << endl;
    }
  }

  if (exe_3_5) {
    cout << "============ex.3.5============" << endl;
    string sentence, word;
    while (cin >> word) { word = sentence + word + " "; }
    cout << sentence << endl;
  }

  return 0;
}
