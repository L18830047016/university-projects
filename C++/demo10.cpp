#include <iostream>
using namespace std;

//定义学生类
class Student
{public:
    //成员变量
    int id;
    const char* sex;
    const char* name;
    int age;
    const char* major;

    //成员函数
    void show()
    {
        cout << "学号：" << id << endl;
        cout << "姓名：" << name << endl;
        cout << "性别：" << sex << endl;
        cout << "年龄：" << age << endl;
        cout << "专业：" << major << endl;
    }
};

int main()
{
    //创建学生对象
    Student stu1;//栈上分配内存空间
    //对象初始化
    stu1.id = 1001;
    stu1.name = "张三";
    stu1.sex = "男";
    stu1.age = 20;
    stu1.major = "计算机科学与技术";
    stu1.show();

    //堆上分配内存空间
    Student* stu2=new Student;
    stu2->id = 1002;
    stu2->name = "李四";
    stu2->sex = "女";
    stu2->age = 21;
    stu2->major = "软件工程";
    stu2->show();
    
    delete stu2; // 释放堆上分配的内存
    stu2 = nullptr; // 将指针置空，避免悬空指针

    return 0;
}