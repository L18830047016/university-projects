//输出遇到空指针时会导致程序崩溃
#include <iostream>

using namespace std;

//定义学生类
class Student
{public:
    //成员变量
    int id;
    const char* name;
    const char* sex;
    int age;
    const char* major;

    Student(){}//默认无参构造函数

    //有参构造函数
    Student(int id1,const char* name1,const char* sex1,int age1,const char* major1)
    {
        id=id1;
        name=name1;
        sex=sex1;
        age=age1;
        major=major1;
    }
    Student(int id1,const char* name1,const char* sex1)
    {
        id=id1;
        name=name1;
        sex=sex1;
        age=0;
        major=nullptr;
    }

    //成员函数
    void display()
    {
        cout<<"学号："<<id<<endl;
        cout<<"姓名："<<name<<endl;//对于char*类型，cout有重载函数，可以直接输出字符串内容
        cout<<"姓名："<<*name<<endl;//对于char*类型，*name表示字符串的第一个字符
        cout<<"姓名："<<(void*)name<<endl;//对于char*类型，(void*)name表示字符串的地址
        
        //对于非char类型的指针，要输出指针指向的内容，必须先解引用指针，否则输出的是指针的地址
        
        cout<<"性别："<<sex <<endl;
        cout<<"年龄："<<age <<endl; 
        cout<<"专业："<<major <<endl;
    }
};

int main(void){
    //创建学生对象，要求必须对id、name、sex进行初始化，age和major可以不进行初始化
    Student *stu1=new Student(100,"tom","男");
    stu1->major="计算机科学与技术";
    stu1->age=20;
    stu1->display();
    delete stu1;
    stu1=nullptr;

    Student stu2(101,"jerry","女");
    stu2.major="软件工程";
    stu2.display();

    Student stu3(102,"alice","女",19,"软件工程");
    stu3.display();

    Student stu4;

    return 0;
}