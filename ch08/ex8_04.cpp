//
//  ex8_04.cpp
//  Exercise 8.4
//
//  Created by pezy on 11/9/14.
//
//  @Brief  Write a function to open a file for input and read its contents into a vector of strings, 
//          storing each line as a separate element in the vector. 

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using std::vector;
using std::string;
using std::ifstream;
using std::cout;
using std::endl;

//编写函数,以读模式打开一个文件,将其内容读入到一个string的vector对象内,将每一行作为一个独立的元素存放在vector中
void ReadFileToVec(const string &fileName, vector<string> &vec) {   //fileName,和vec分别为两个引用,代表文件名和存放的对象
    ifstream ifs(fileName); //ifstream从给定文件读取数据
    if (ifs) {          //查询流的状态
        string buf;
        while (std::getline(ifs, buf))  //读取一行放到buf
            vec.push_back(buf);
    }
}

int main() {
    vector<string> vec;
    ReadFileToVec("../../data/book.txt", vec);  //文件名为book.txt,存放的向量名为vec
    for (const auto &str: vec)
        cout << str << endl;        //遍历输出
    return 0;
}
