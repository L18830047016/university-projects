#include <iostream>
using namespace std;

struct Person{
    //成员变量
    int id;//4bytes 0,1,2,3
    int age;//4bytes 4,5,6,7
    double height;//8bytes 8,9,10,11,12,13,14,15
    const char* name;//8bytes 16,17,18,19,20,21,22,23

    //无参构造函数
    Person(){
        id = 0;
        age = 0;
        height = 0.0;
        name = nullptr;
    }

    //构造函数
    Person(int id1,const char* name1){
        id = id1;
        age = 0;
        height = 0.0;
        name = name1;
    }
    Person(int id1,int age1,const char* name1){
        id = id1;
        age = age1;
        height = 0.0;
        name = name1;
    }
    
    //成员函数
    void display(){
        cout<<"id: "<<id<<endl;
        cout<<"age: "<<age<<endl;
        cout<<"height: "<<height<<endl;
        cout<<"name: "<<name<<endl;
    }
}; //24bytes

int main(void){
    
    //Person p1={.id=1,.age=20,.height=1.75,.name="Alice"};
    //以上初始化方式仅适用于C++20及以上版本，且需要编译器支持
    Person p1;
    p1.id = 1;
    p1.age = 20;
    p1.height = 1.75;
    p1.name = "Alice";
    p1.display();

    //通过构造函数对创建的结构体的成员做初始化
    Person p2(2,"Bob");
    p2.display();
    //对id和name成员进行初始化，age和height成员会被默认初始化为0
    //对id,name,age初始化
    Person p3(3,30,"Charlie");
    p3.display();

    return 0;
}