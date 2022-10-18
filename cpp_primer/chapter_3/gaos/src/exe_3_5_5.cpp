#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

#define exe_3_41 false
#define exe_3_42 false

int main() {
  if (exe_3_41) {
    cout << "============ex.3.41============" << endl;
    vector<int> v = {1, 2, 3, 4, 5};
    for (auto num : v) { cout << num << "  "; }
    cout << endl;
  }

  if (exe_3_42) {
    cout << "============ex.3.42============" << endl;
    vector<int> v = {1, 2, 3, 4, 5};
    int ia[v.size()];
    int* beg = ia;
    for (auto num : v) {
      *beg = num;
      beg++;
      int i = 0;
      cout << ia[i] << "  ";
    }
    cout << endl;
  }

  return 0;
}
