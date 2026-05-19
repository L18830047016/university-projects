#include <iostream>
using namespace std;

typedef struct {
    int id; //4bytes  0,1,2,3
    int age; //4bytes  4,5,6,7
    double height; //8bytes  8,9,10,11,12,13,14,15
    char* name; //8bytes  16,17,18,19,20,21,22,23 
}Person; //24bytes

//指针类型参数，模块内只能访问目标内存中的值，不能修改目标内存中的值
void showPerson(const Person* person);

int main(){
    Person p;
    p.id = 1;
    p.age = 18;
    p.height = 1.75;
    p.name = "Alice";
    cout<<"p size:"<<sizeof(p)<<endl; //24bytes
    //值传递
    //showPerson(p);
    //指针传递
    showPerson(&p);
    cout<<"main p.id:"<<p.id<<endl; //1

    int num1=999;
    int num2=888;
    cout<<"num1:"<<num1<<endl; //999
    cout<<"&num1:"<<&num1<<endl; 
    cout<<"num2:"<<num2<<endl; //888
    cout<<"&num2:"<<&num2<<endl; 

    //常量指针，指向可改，值不能改
    const int* pNum1 = &num1; //指针pNum1指向num1，pNum1是一个常量指针，指向的值不能修改
    cout<<"*pNum1:"<<*pNum1<<endl; //999
    cout<<"pNum1:"<<pNum1<<endl; //地址
    pNum1 = &num2; //指针pNum1可以指向num2
    cout<<"*pNum1:"<<*pNum1<<endl; //888
    cout<<"pNum1:"<<pNum1<<endl; //地址
    //改目标内存中的值，
    // *pNum1 = 777; //错误，不能修改常量指针指向的值   

    //指针常量，指向不可改，值可改
    int* const pNum2 = &num1; //指针pNum2是一个指针常量，指向num1，pNum2指向的地址不能修改，但可以修改指向地址中的值

}

void showPerson(const Person* person){
    cout << "ID: " << person->id << endl;
    cout << "Age: " << person->age << endl;
    cout << "Height: " << person->height << endl;
    cout << "Name: " << person->name << endl;
    //person->id = 2; //错误，不能修改常量指针指向的值
}