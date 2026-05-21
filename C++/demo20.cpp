#include <iostream>
using namespace std;

//定义动物类父类
class Animal{
    public:
        int age;
        string name;
        Animal(){
            cout<<"调用父类构造函数Aniaml()"<<endl;
        }
        ~Animal(){
            cout<<"调用父类构析函数~Animal()"<<endl;
        }
        void Eat(){
            cout<<name<<"吃东西"<<endl;
        }
    protected:
        int money=100;//受保护成员；
};

class Dog:public Animal{
    public:
        string color;
        Dog(){
            cout<<"调用了子类构造函数Dog()"<<endl;
        }
        ~Dog(){
            cout<<"调用了子类构析函数~Dog()"<<endl;
        }
        void Shut(){
            cout<<name<<"汪汪叫"<<endl;
        }
};

class Cat:public Animal{
    public:
    string breed;
        Cat(){
            cout<<"调用了子类构造函数Cat()"<<endl;
        }
        ~Cat(){
            cout<<"调用了子类构析函数~Cat()"<<endl;
        }
        void CatchMouse(){
            cout<<name<<"抓老鼠"<<endl;
        }
};

int main(){
    Cat cat;// 先创建自己的父类对象Animal，再创建cat对象
    cat.name="kitty";
    cat.Eat();
    
    Dog d;// 先创建自己的父类对象Animal，再创建d对象
    d.name="旺财";
    d.Eat();

    return 0;
}