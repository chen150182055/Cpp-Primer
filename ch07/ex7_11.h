//
//  ex7_11.h
//  Exercise 7.11
//
//  Created by pezy on 11/9/14.
//

#ifndef CP5_ex7_11_h
#define CP5_ex7_11_h

#include <string>
#include <iostream>

struct Sales_data {
    Sales_data() = default; //因为该构造函数不接受任何实参,所以它是一个默认构造函数，在C++11中，如果我们需要默认的行为，
    // 那么可以通过在参数列表后面写上"= default"，来要求编译器生成构造函数
    Sales_data(const std::string &s) : bookNo(s) {}  //冒号后面的部分为构造函数初始值列表。
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(n * p) {}

    Sales_data(std::istream &is);

    std::string isbn() const { return bookNo; };

    Sales_data &combine(const Sales_data &);

    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// nonmember functions
std::istream &read(std::istream &is, Sales_data &item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " " << item.revenue;
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

// member functions.
Sales_data::Sales_data(std::istream &is)       //调用了read函数为数据成员赋初值
{
    read(is, *this);
}

Sales_data &Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

#endif
