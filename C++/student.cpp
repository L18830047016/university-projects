#include "student.h"

//无参构造函数
Student::Student()
{
    cout << "无参构造函数被调用了" << endl;
}
//复制构造函数
Student::Student(const Student &s)
{
    cout << "复制构造函数被调用了" << endl;
}