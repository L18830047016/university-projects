#include "person.h"

//静态成员变量初始化
string Person::country = "中国";
//静态成员函数
void Person::ShowCountry(){
    cout<<"国家："<<country<<endl;
}
void Person::SetId(int id){
    this->id = id;
}
void Person::SetAge(int age){
    this->age = age;
}
void Person::SetName(string name){
    this->name = name;
}
int Person::GetId(){
    return id;
}
int Person::GetAge(){
    return age;
}
string Person::GetName(){
    return name;
}
void Person::ShowInfo(){
    cout<<"ID："<<id<<endl;
    cout<<"年龄："<<age<<endl;
    cout<<"姓名："<<name<<endl;
}