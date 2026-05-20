#include <iostream>
using namespace std;

//定义一个学生类
class Student
{public:
    //成员变量
    int id;
    const char* sex;
    const char* name;
    int age;
    const char* major;
    int* scores;

    // //默认无参构造函数
    // Student(){
    //     cout << "调用了默认构造函数" << endl;
    // }

    // Student(int id, const char* sex, const char* name, int age, const char* major, int* scores)
    // {
    //     this->id = id;
    //     this->sex = sex;
    //     this->name = name;
    //     this->age = age;
    //     this->major = major;
    //     this->scores = scores;
    // }

    // //列表初始化构造函数
    // Student(int id, const char* sex, const char* name, int age, const char* major, int* scores)
    //  : id(id), sex(sex), name(name), age(age), major(major), scores(scores)
    // {}

    // //缺省构造函数（半缺省）
    // Student(int id, const char* sex="男", const char* name="未知", int age=0, const char* major="未知", int* scores)
    // :id(id),sex(sex),name(name),age(age),major(major),scores(scores){}
   
    //全缺省构造函数
    Student(int id=0, const char* sex="男", const char* name="未知", int age=0, const char* major="未知", int* scores=nullptr)
    :id(id),sex(sex),name(name),age(age),major(major),scores(scores){}
   

    //成员函数
    void show()
    {
        cout << "学生信息：" << endl;
        cout << "学号：" << id << endl;
        cout << "性别：" << sex << endl;
        cout << "姓名：" << name << endl;
        cout << "年龄：" << age << endl;
        cout << "专业：" << major << endl;
    }
};

int main(){
    //Student stu;
    //外部访问对象的成员变量
    // stu.name = "张三";

    //成员函数
    // stu.show();

    Student stu1(1001, "男", "张三", 20, "计算机科学与技术");
    //保存成绩
    stu1.scores = new int[3]{85, 90, 95};
    stu1.show();

    cout << "成绩：" << stu1.scores[0] << ", " << stu1.scores[1] << ", " << stu1.scores[2] << endl;

    //复制一份stu1到新创建的对象stu2
    Student stu2 = stu1; //默认的拷贝构造函数
    stu2.show();

    //修改stu2的成绩
    stu2.scores[0] = 80;
    cout << "修改后stu2的成绩：" << stu2.scores[0] << ", " << stu2.scores[1] << ", " << stu2.scores[2] << endl;
    //查看stu1的成绩，发现也被修改了，说明默认的拷贝构造函数是浅拷贝
    cout << "stu1的成绩：" << stu1.scores[0] << ", " << stu1.scores[1] << ", " << stu1.scores[2] << endl;

    stu2.name = "李四";//改变stu2.name的指向（指向了另一个字符串常量），而不是修改字符串常量的内容
    cout << "修改后stu2的姓名：" << stu2.name << endl;
    //查看stu1的姓名，发现没有被修改，说明字符串常量是不可修改的
    cout << "stu1的姓名：" << stu1.name << endl;

    return 0;
}