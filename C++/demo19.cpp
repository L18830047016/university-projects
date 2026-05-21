#include <iostream>
using namespace std;

//定义动物类的父类;子类成员能够访问到protected中的内容
class Animal{
    public:
        int age;
        string name;
        void Eat(){
            cout<<name<<"吃东西"<<endl;
        }
    protected:
    int money =100;//受保护成员
};

class Dog:public Animal{
    public:
        string color;
        void Shut(){
            cout<<name<<"汪汪叫"<<endl;
            cout<<money<<endl;
        }
};

class Cat:public Animal{
    public:
        string breed;
        void CatchMouse(){
            cout<<name<<"抓老鼠"<<endl;
        }
};

class Rabbit:public Animal{
    public:
        void sleep(){
            cout<<name<<"睡觉"<<endl;
        }
};

int main(){
    Cat cat;//先创建自己的父类对象Animal,再创建cat对象
    cat.name="kitty";
    cat.CatchMouse();
    cat.Eat();

    Dog d;//先创建自己的父类对象Animal，再创建d对象
    d.name="旺财";
    d.Eat();
    d.Shut();

    Rabbit r;
    r.sleep();

    return 0;
}