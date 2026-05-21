#include <iostream>
#include "person.h"
using namespace std;

int main(){
    Person p;
    p.SetId(100);
    p.SetAge(20);
    p.SetName("张三");
    p.ShowInfo();
    cout<<"age:"<<p.GetAge()<<endl;

    //直接访问类的静态成员
    cout<<"类的静态成员变量："<<Person::country<<endl;
    cout<<"类的静态成员函数："<<Person::ShowCountry<<endl;
    //cout<<"类的静态成员函数："<<Person::ShowCountry()<<endl;
    Person::ShowCountry();

    return 0;
}