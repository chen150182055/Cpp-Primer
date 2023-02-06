//
//  ex7_15.h
//  Exercise 7.15
//
//  Created by pezy on 11/9/14.
//

#ifndef CP5_ex7_15_h
#define CP5_ex7_15_h

#include <string>
#include <iostream>

struct Person;

std::istream &read(std::istream &, Person &);

struct Person {
    Person() = default;     //添加默认的构造函数
    Person(const std::string sname, const std::string saddr) : name(sname), address(saddr) {} //添加有两个参数的构造函数
    Person(std::istream &is) { read(is, *this); }    //添加函数体不为空的构造函数

    std::string getName() const { return name; }

    std::string getAddress() const { return address; }

    std::string name;
    std::string address;
};

std::istream &read(std::istream &is, Person &person) {
    is >> person.name >> person.address;
    return is;
}

std::ostream &print(std::ostream &os, const Person &person) {
    os << person.name << " " << person.address;
    return os;
}

#endif
