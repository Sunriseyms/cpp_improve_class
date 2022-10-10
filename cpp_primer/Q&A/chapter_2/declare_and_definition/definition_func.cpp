#include <iostream>

// 一个名字在其定义处之外的编译单元中也可以使用，称其具有外部链接，此处的f()具有外部链接属性
int func() {
  std::cout << "call func() function in definition_func.cpp" << std::endl;
  return 0;
}
