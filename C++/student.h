#pragma once
#include <iostream>
using namespace std;

//学生类
class Student{
    public:
    //成员变量
    int id;
    string sex;
    string name;
    int age;
    string major;
    int* scores;
    //无参构造函数
    Student();
    //复制构造函数
    Student(const Student &s);
};