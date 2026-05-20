#include <iostream>
using namespace std;

//自定义学生类型结构体
typedef struct Student{
    int id;
    int age;
    double height;
    char name[10];
    char major[10];
}Stu;

int main(void){
    //保存一个学生的信息，id，age,height,name,major
    //int id=100;
    //int age=18;
    //double height=179.9;
    //char name[]="tom";
    //char major[]="嵌入式";

    //定义自定义结构体类型变量
    struct Student stu1;
    Stu stu2;

    return 0;
}