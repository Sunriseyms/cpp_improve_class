#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

#define exe_3_43 false
#define exe_3_44 false
#define exe_3_45 false

int main() {
  if (exe_3_43) {
    cout << "============ex.3.43============" << endl;
    int ia[] = {1, 2, 3, 4, 5};
    for (int num : ia) { cout << num << "  "; }
    cout << endl;
    for (int i = 0; i < 5; i++) { cout << ia[i] << "  "; }
    cout << endl;
    for (int* p = std::begin(ia); p < std::end(ia); p++) { cout << *p << "  "; }
    cout << endl;
  }

  if (exe_3_44) {
    cout << "============ex.3.44============" << endl;
    using int_array = int[4];
    typedef int int_array[4];
    int ia[3][4];
    for (int_array* p = ia; p != ia + 3; ++p) {
      for (int* q = *p; q != *p + 4; ++q) { cout << *q << ' '; }
      cout << endl;
    }
  }

  if (exe_3_45) {
    cout << "============ex.3.45============" << endl;
    int ia[] = {1, 2, 3, 4, 5};
    for (auto num : ia) { cout << num << "  "; }
    cout << endl;

    return 0;
  }
}
