#include <iostream>
using namespace std;

//定义学生类
class Student
{public:
    //成员变量
    int id;
    string sex;
    string name;
    int age;
    string major;
    int *scores;

    //复制构造函数
    Student(const Student &s)
    {
        cout << "调用了复制构造函数" << endl;
        id = s.id;
        sex = s.sex;
        name = s.name;
        age = s.age;
        major = s.major;
        scores=s.scores; //浅拷贝
    }

    //全缺省构造函数
    Student(int id=100,string sex="男",string name="tom",string major="嵌入式")
    :id(id),sex(sex),name(name),age(18),major(major)
    {
        cout << "调用了全缺省构造函数" << endl;
    }

    //成员函数
    void display()
    {
        cout << "学号：" << id << endl;
        cout << "姓名：" << name << endl;
        cout << "性别：" << sex << endl;
        cout << "年龄：" << age << endl;
    }

};

int main(){
    Student stu2(1,"tom","男","AI Agent");
  // 保存成绩
  stu2.scores=new int[]{10,20,30,40,50};
  stu2.display();
  // 复制对象
  Student stu4=stu2;
  stu4.display();

    // 继续操作原始数据
  stu2.scores[2]=68;
  cout<<"stu2 scores[2]:"<<stu2.scores[2]<<endl;
  // 会对备份数据产生影响(要求不能影响备份数据)
  cout<<"stu4 scores[2]:"<<stu4.scores[2]<<endl;

  return 0;
}