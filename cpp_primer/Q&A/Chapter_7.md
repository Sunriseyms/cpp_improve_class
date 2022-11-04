### Chapter 7  答疑
- 答疑问题


  1. 类声明中直接赋默认值 VS使用参数列表赋值Vs在构造函数中赋值
     ```
     class Demo{
          public:
          Demo:i(0){
               i = 0; //不推荐这种构造函数内的赋值，i会执行构造+赋值的操作
                         // 声明中直接赋初值语义更加明确，参数化列表也可以
          }
          int GetI() const{ //const 修饰的是this指针
               return i;
          }

          private:
          int i{0}; //推荐使用{}初始化，不允许使用隐式类型转换，会报错
          // int i(0.0); 使用（）会执行隐式转换，不会报错，应当避免这种不可控的隐式转换
          double j{0.0};
          // 类成员的构造顺序只与声明的顺序有关，与构造函数参数列表的顺序无关
          // Demo:j(1.0),i(0){} 先构造i,再构造j
     }
     ```
  2. 派生类的构造顺序：基类--》派生类对象---》派生类自身
     ```
     class A{
          private:
               int i ;
          }
          class B: public A{
          private:
               int j;
     }

     内存示意：
     |--------A::i-----------|
     |--------A::i-----------|---------------B::j-----------|
     ```

  3. const的作用 VS mutable的作用（常用mutable来修饰mutex）

   ```
     class Demo{
          public:
               Demo:i(0){
               }
               int GetI() const{ //const 修饰的是this指针
                    std::lock_guard<std::mutex> lock(m_); // 常用mutable来修饰mutex,
                                                            //确保再上锁的情况下其他的变量不会被改变
                    count_++; // mutable
                    return i;
               }
          private:
               int i;
               mutable int count_{0}; // 可以通过mutable修改const属性
               mutable std::mutex m_;
     }
   ```


  4. Q: 析构函数什么时候需要自己写？
     A: 存在动态内存管理（new或者malloc）

   ```
     class Demo{
     public:
          Demo{
               buf = static_cast<char*>(malloc(100));
          }
          ~Demo(){
               free(buf);
          }

     private:
          char * buf;
          vector<int> vec_; //vector,string 等stl存在自身的内存管理，不用去写析构
     }
   ```

  5. 如果不写构造函数，默认会生成如下
  ```
     //1. default construct 如果写了任何一种形式的构造函数，默认构造函数不会自动生成。
     //2. default copy construct 如果定义了copy construct，则不会自动生成move construct
     //3. default copy operator= 如果定义了copy operator=，则不会自动生成move operator=
     //4. default move construct 如果定义了move construct，则不会自动生成copy construct
     //5. default move operator= 如果定义了move operator=，则不会自动生成copy operator=
     //6. default destructor 如果定义了析构，则不会生成move的操作
  ```
     一旦定义了某个函数，建议所有的都写出来。
  6. 如果类中某个静态成员仅用于值可以替换的情况，且它的修饰符是static const或static constexpr，则仅有该静态成员只有一条初始化语句即可。相反，如果该静态成员用于值不能替换的场景中，该静态成员在初始化语句之外，必须还要有一条定义语句。在c++17及以后的版本，能够解析为值替换的场景边多，提升了constexpr的易用性。但是对在类里声明的static成员，我们的建议是都在类的外部进行定义。
