//
//  ex7_11.cpp
//  Exercise 7.11
//
//  Created by pezy on 11/9/14.
//

#include "ex7_11.h"

int main() {
    Sales_data item1;      //使用默认构造函数
    print(std::cout, item1) << std::endl;

    Sales_data item2("0-201-78345-X");  //使用第二个只有一个参数的构造函数
    print(std::cout, item2) << std::endl;

    Sales_data item3("0-201-78345-X", 3, 20.00);    //使用第三个有三个参数的构造函数
    print(std::cout, item3) << std::endl;

    Sales_data item4(std::cin);     //使用第四个函数体不为空的构造函数
    print(std::cout, item4) << std::endl;

    return 0;
}
