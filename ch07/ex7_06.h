//
//  ex7_06.h
//  Exercise 7.6
//
//  Created by pezy on 11/8/14.
//

#ifndef CP5_ex7_06_h
#define CP5_ex7_06_h

#include <string>
#include <iostream>

struct Sales_data {
    std::string const &isbn() const { return bookNo; };

    Sales_data &combine(const Sales_data &);

    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// member functions.
Sales_data &Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

// nonmember functions
std::istream &read(std::istream &is, Sales_data &item)  //自己版本的read,函数名前的“&”是指返回引用类型
{                                                       //将read的Sales_data参数定义为普通引用，因为它的目的是改变收入的值。
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item)   //自己版本的print,函数名前的“&”是指返回引用类型
{                                                               //将print的Sales_data参数定义为对const的引用，
    // 因为它并不打算改变这个对象的任何成员的值。
    os << item.isbn() << " " << item.units_sold << " " << item.revenue;
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)    //自己版本的add
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

#endif
