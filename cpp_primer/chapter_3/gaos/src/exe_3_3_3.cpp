#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

#define exe_3_21 false
#define exe_3_17 true
#define exe_3_18 true

int main() {
  if (exe_3_21) {
    cout << "============ex.3.21============" << endl;
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{10};
    vector<int> v5{10, 42};
    vector<string> v6{10};
    vector<string> v7{10, "hi"};
    cout << "the size of vector 1 is " << v1.size() << endl;
    for (auto& item : v1) { cout << item << "  "; }
    cout << endl;
    cout << "the size of vector 2 is " << v2.size() << endl;
    for (auto& item : v2) { cout << item << "  "; }
    cout << endl;
    cout << "the size of vector 3 is " << v3.size() << endl;
    for (auto& item : v3) { cout << item << "  "; }
    cout << endl;
    cout << "the size of vector 4 is " << v4.size() << endl;
    for (auto& item : v4) { cout << item << "  "; }
    cout << endl;
    cout << "the size of vector 5 is " << v5.size() << endl;
    for (auto& item : v5) { cout << item << "  "; }
    cout << endl;
    cout << "the size of vector 6 is " << v6.size() << endl;
    for (auto& item : v6) { cout << item << "  "; }
    cout << endl;

    cout << "the size of vector 7 is " << v7.size() << endl;
    for (auto& item : v7) { cout << item << "  "; }
    cout << endl;
  }

  if (exe_3_17) {
    cout << "============ex.3.17============" << endl;
    cout << "please input words" << endl;
    vector<string> v;
    string tmp;
    while (cin >> tmp) { v.push_back(tmp); }
    int count = 0;
    for (auto& word : v) {
      for (auto& c : word) { cout << toupper(c) << "  "; }
      count++;
      if (count >= 8) {
        count = 0;
        cout << endl;
      }
    }
  }

  if (exe_3_18) {
    cout << "============ex.3.18============" << endl;
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
