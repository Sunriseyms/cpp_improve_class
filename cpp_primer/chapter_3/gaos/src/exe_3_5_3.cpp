#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

#define exe_3_35 false

int main() {
  if (exe_3_35) {
    cout << "============ex.3.35============" << endl;
    constexpr size_t kArraySize = 10;
    int ia[kArraySize];
    for (size_t ix = 1; ix <= kArraySize; ++ix) {
      ia[ix] = ix;
      cout << ia[ix] << "  ";
    }
    for (int* beg = std::begin(ia); beg > std::end(ia); beg++) {
      *beg = 0;
      int i = 0;
      cout << ia[i] << "  ";
      i++;
    }
  }

  return 0;
}
