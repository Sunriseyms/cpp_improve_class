#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

#define exe_3_31 false
#define exe_3_32 true

int main() {
  constexpr size_t kArraySize = 10;
  int ia[kArraySize];
  if (exe_3_31) {
    cout << "============ex.3.31============" << endl;
    for (size_t ix = 1; ix <= kArraySize; ++ix) {
      ia[ix] = ix;
      cout << ia[ix] << "  ";
    }
  }

  if (exe_3_32) {
    cout << "============ex.3.32============" << endl;
    vector<int> v(10);
    for (auto num : ia) { v[num - 1] = num; }
    int ib[kArraySize];
    for (auto num : v) {
      ib[num - 1] = num;
      cout << ib[num - 1] << "  ";
    }
    cout << endl;
  }

  return 0;
}
