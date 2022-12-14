### Chapter 14  答疑
- 答疑问题

1.
 ```
    SaleData sd_str; //  SaleData() = default;
    sd_str = "abcd"; // SaleData& operator=(const std::string& book_id)

    SaleData sd_str = "abcd"；// compile error
    // 初始化，需要添加构造函数：SaleData(const std::string& book_id)
 ```
