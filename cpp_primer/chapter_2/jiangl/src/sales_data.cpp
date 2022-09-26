#include "sales_data.h"

#include <iostream>

int main() {
    sales_data data;
    std::cout << "Please input sales_data." << std::endl;
    std::cin >> data;
    std::cout << data << std::endl;

    sales_data data1, data2;
    std::cout << "Please input sales_datas with same isdn." << std::endl;
    std::cin >> data1 >> data2;
    int sold_num = data1 + data2;
    std::cout << "Book (" << data1.get_isdn() << ") is sold " << sold_num << std::endl;

    std::cout << "Please input sales_datas with different isdn." << std::endl;
    std::cin >> data1;
    while (std::cin >> data2) {
        data1.sold_num = data1 + data2;
    }
    std::cout << "Book (" << data1.get_isdn() << ") is sold " << data1.sold_num << std::endl;
    return 0;
}