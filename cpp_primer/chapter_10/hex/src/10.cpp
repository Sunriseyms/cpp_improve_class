#include <algorithm>
#include <iostream>
#include <list>
#include <numeric>
#include <string>
#include <vector>

int main() {
  // 10.1
  {
    std::vector<int> vec = {1, 2, 4, 5, 6, 2, 10};
    int target = 2;
    std::cout << "\n10.1 :\n The count of target is " << std::count(vec.cbegin(), vec.cend(), target) << std::endl;
  }

  // 10.2
  {
    std::list<std::string> str_list = {"a", "b", "c", "dd", "c", "c"};
    std::string target{"c"};
    std::cout << "\n10.2 :\n The count of target is " << std::count(str_list.cbegin(), str_list.cend(), target)
              << std::endl;
  }

  // 10.3
  {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    int res = std::accumulate(vec.cbegin(), vec.cend(), 0);
    std::cout << "\n10.3 :\n The sum of vector is " << res << std::endl;
  }

  // 10.4
  {
    std::vector<double> vec = {1, 2, 3.7, 4.2, 5.5};
    double res = std::accumulate(vec.cbegin(), vec.cend(), 0);
    std::cout
        << "\n10.4 :\n The sum of vector is " << res
        << "\n 答:accumulate第三个参数是决定返回值类型和加法运算符的类型选择（int or double），将其置为0. 会导致int--> "
           "double ,精度损失"
        << std::endl;
  }

  // 10.5
  {
    std::cout
        << "\n10.5 :\n  答:如果使用equal比较的容器内存放的是c风格字符串，相当于比较两个指针的值是否一致，而非字符串本身"
        << std::endl;
  }

  // back_inserter 扩容机制
  {
    std::string str = "aaa";
    std::vector<std::string> vec;
    vec.push_back(str);
    auto it = back_inserter(vec);
    std::cout << "After back_inserter , vec.size()  << " << vec.size() << std::endl;
    *it = std::string("sss");
    std::cout << "After assignment *it = std::string();, vec.size()  << " << vec.size() << std::endl;
    std::cout << "\nback_inserter 扩容机制 :\n  "
                 "答:调用back_inserter并不会对容器进行扩容，size()不变，只是获取了插入迭代器；只有对插入迭代器back_"
                 "inserter赋值时，才会构建对象并插入到容器中，size +1"
              << std::endl;
  }

  // 10.6
  {
    std::vector<int> vec(10, 4);
    std::fill_n(vec.begin(), vec.size(), 0);
  }

  // 10.14
  {
    auto f = [](int x, int y) { return x + y; };
    int x = 1, y = 2;
    std::cout << "\n10.14:\n (lambda) x+y = " << f(x, y) << std::endl;
  }

  // 10.15
  {
    int x = 1;
    auto f = [x](int y) { return x + y; };
    int y = 2;
    std::cout << "\n10.15:\n (lambda capture) x+y = " << f(y) << std::endl;
  }

  // 10.20
  {}

  return 0;
}
