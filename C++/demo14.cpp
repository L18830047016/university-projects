#include <iostream>
using namespace std;

//定义学生类
class Student{
public:
    //成员变量
    int id;
    string sex;
    string name;
    int age;
    string major;
    int *scores;

    //复制构造函数
    Student(const Student &s){
        cout << "调用了复制构造函数" << endl;
        id=s.id;
        sex=s.sex;
        name=s.name;
        age=s.age;
        major=s.major;
        //深拷贝，先分配内存，再复制内容
        scores=new int[5];
        for(int i=0;i<5;i++){
            scores[i]=s.scores[i];
        }
    }

    //全缺省构造函数
    Student(int id=0,string sex="男",string name="tom",int age=0,string major="嵌入式")
    :id(id),sex(sex),name(name),age(age),major(major){
        for(int i=0;i<5;i++){
            scores[i]=0;
        }
    }

    //成员函数
    void display(){
        cout << "id: " << id << endl;
        cout << "name: " << name << endl;
        cout << "major: " << major << endl;
        cout << "scores: ";
        for(int i=0;i<5;i++){
            cout << scores[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    Student stu2(1,"tom","男",20,"嵌入式");
    stu2.scores=new int[]{90,85,92,88,95};
    stu2.display();
    //调用复制构造函数，创建stu3对象
    Student stu3=stu2;
    stu3.display();

    //修改stu3的成绩，验证深拷贝
    stu3.scores[0]=80;
    cout << "修改stu3的成绩后："<<stu3.scores[0] << endl;
    //验证stu2的成绩没有被修改
    cout << "stu2的成绩没有被修改："<<stu2.scores[0] << endl;

    return 0;
}

