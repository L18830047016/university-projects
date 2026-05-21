#include  <iostream>
#include "student.h"
using namespace std;

//形参是值类型，调用时会调用复制构造函数，形参是引用类型，不会调用复制构造函数
void func(Student s)
{
    cout << "func函数被调用了" << endl;
}

//函数返回值类型是普通对象变量类型，返回时会调用复制构造函数，函数返回值类型是引用类型，不会调用复制构造函数
//现代C++编译器会进行返回值优化（RVO），在函数返回对象时直接在调用处构造对象，避免了复制构造函数的调用，提高了效率
//即省略1~2次复制构造函数的调用
Student func2()
{
    Student s;
    cout << "func2函数被调用了" << endl;
    s.id = 1001;
    return s;
}

int main(){
    //创建对象
    Student s1;
    s1.id = 1000;
    //复制构造函数的执行时机：
    
    //1.用一个已经创建好的对象来初始化一个新对象
    Student s2 = s1;
    //Student s2(s1);
    //Student s2;s2 = s1;//这种方式不会调用复制构造函数，而是调用赋值运算符函数

    //2.值传递的方式给函数参数传值
    func(s1);

    //3.函数返回值是普通对象变量类型
    Student s3 = func2();

    return 0;
}