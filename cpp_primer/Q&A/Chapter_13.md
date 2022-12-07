### Chapter 13  答疑
- 答疑问题

1. 使用标准容器时调用其Insert或push时，容器会对其元素进行拷贝初始化。而用emplace成员创建的元素都进行直接初始化。故建议使用emplace，效率更高。
2. 拷贝控制操作
 ```
    Demo d1(1); // 构造函数
    Demo d2 = d1; // 执行拷贝构造函数 ， d2未被初始化，相当于d2(d1)
    Demo d3; // 默认构造函数
    d3 = d1; // 拷贝赋值运算符

    Demo d4;
    d4 = d1； // d1是左值，拷贝赋值运算符，d4.operator=(xx),其中xx=d1
    d4 = std::move(d1); // 参数是右值时调用移动赋值运算符，相当于 d4.operator=(xx),其中xx=std::move(d1)

    Demo d5 = std::move(d1); //std::move(d1)是右值，移动语义，调用移动构造函数
    Demo d5 = Demo(3); //会被编译器优化成走直接构造函数，类似与Demo d5(3);
                    // 理论上应该是使用移动构造函数，因为Demo(3)是右值
 ```
3. 五个构造函数中如果显式定义了其中一个，那么剩余的其他构造如果不想手动定义，建议写成=default,避免不会自动生成其他的构造的函数。
4. move之后注意代码安全。
```
#include <iostream>
#include <memory>
#include <vector>

class Demo {
    public:
    Demo()
    {
        std::cout << "Demo construct0" << std::endl;
    }

    Demo(const int& i) :i_(i) {
        std::cout << "Demo construct1" << std::endl;
    }

    Demo(const Demo& d) {
        //memcopy(this->buf,d.buf,size); 需要深拷贝
        // 系统默认生成的是this->buf = d.bug,浅拷贝，不符合要求
        std::cout << "Demo copy construct" << std::endl;
    }

    Demo& operator=(const Demo& d) {
        std::cout << "Demo operator= construct" << std::endl;
        return *this;
    }

    Demo(Demo&& d) {
        this->i_ = std::move(d.i_);
        this->v_ = std::move(d.v_);
        // 如果是右值的话，少了memcopy的内存拷贝，直接改变指针指向，性能会有提升
        this->buf = d.buf;
        d.buf = nullptr;
        std::cout << "Demo move construct" << std::endl;
    }

    Demo& operator=(Demo&& d) {
        std::cout << "Demo move operator= construct" << std::endl;
        return *this;
    }

    ~Demo() {
        std::cout << "Demo destructor" << std::endl;
        if（buf == nullptr){
            delete buf;
        }
    }

    public:
    std:vector<int> v_;
    char * buf; //注意，由于有动态内存，所以拷贝和赋值运算符均需自行定义，参考移动构造函数
    int i_{0};
};

int main()
{
    Demo d1;
    {
        Demo d5= std::move(d1);
        // d5离开作用域后，会被释放
    }
    // d1.v_[0]不能使用，未定义行为


    std::vector<Demo> d_list;
    d_list.push_back(1); // 会调用构造函数 + 移动构造函数
                         // Demo(1) + Demo(const Demo &&)      Demo(1)是右值

    Demo d1; //构造函数
    d_list.push_back(d1); //拷贝构造函数



    // 下面这两种用法的性能开销一样
    d_list.push_back(Demo(1)); // Demo(1); Demo d_list[0] = Demo(1);
    d_list.emplace_back(Demo(1)); // Demo(1); Demo d_list[0] = Demo(1);
    //emplace只有使用参数构造时性能才有提升
    d_list.emplace_back(2); // 只有构造函数，相当于Demo d_list[0]=Demo(2);

    return 0;
}
```

5. 行为类似指针的类的作用和使用方式，可以参照智能指针
6. 若移动构造函数未定义，则会退化到拷贝构造函数
