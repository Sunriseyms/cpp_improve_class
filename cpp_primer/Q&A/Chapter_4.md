### Chapter 4  答疑
- 答疑问题


  1. 对string 对象或vector对象执行sizeof运算，只返回该类型固定部分的大小，不会计算对象中的元素占用了多少空间

   ```
  template <typename T>
  struct basic_string {
      char* begin_;
      size_t size_;
      union {
          size_t capacity_;
          char sso_buffer[16];
      };
  };

  std::string str;
  sizeof(str) = 32( (8+4+16) = 28 -> 32)
   ```

  2. 左值右值的判断方法：能取地址的是左值，不能取地址的是右值

  3. 左值和右值的关系（我看了个知乎的文档还不错，可以参考下）https://zhuanlan.zhihu.com/p/335994370
