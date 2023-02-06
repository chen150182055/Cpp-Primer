//
//  ex8_02.cpp
//  Exercise 8.2
//
//  Created by pezy on 11/27/14.
//
//  @Brief  Test your function by calling it, passing cin as an argument

#include <iostream>

using std::istream;

//接受一个istream&参数,返回值类型也是istream&&
istream &func(istream &is) {    //从给定流中读取数据,直到遇到文件结束标识符时停止
    std::string buf;
    while (is >> buf)
        std::cout << buf << std::endl;  //将读取的数据打印在输出流上
    is.clear();     //对流进行复位
    return is;      //返回流
}

int main() {
    istream &is = func(std::cin);
    std::cout << is.rdstate() << std::endl;
    return 0;
}
