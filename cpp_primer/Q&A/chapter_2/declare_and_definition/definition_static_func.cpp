#include <iostream>
// 如果一个名字只能在其定义所在的编译单元中被引用，称为内部链接； static、const关键字暗示默认内部链接
static int func() {
  std::cout << "call func() function in definition_static_func.cpp" << std::endl;
  return 0;
}
