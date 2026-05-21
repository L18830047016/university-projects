#include <iostream>
using namespace std;

//定义动物类父类
class Animal{
    public:
        int age;
        string name;
        Animal(int age,string name):age(age),name(name){
            cout<<"调用父类构造函数Aniaml()"<<endl;
        }
        ~Animal(){
            cout<<"调用父类构析函数~Animal()"<<endl;
        }
        void Eat(){
            cout<<name<<"吃东西"<<endl;
        }
    protected:
        int money=666;//受保护成员；
};

class Dog:public Animal{
    private:
        int money=100;
    public:
        string color;
        Dog(string name,int age):Animal(age,name){
            cout<<"调用了子类构造函数Dog()"<<endl;
        }
        ~Dog(){
            cout<<"调用了子类构析函数~Dog()"<<endl;
        }
        void Shut(){
            cout<<name<<"汪汪叫"<<endl;
            //自己的成员
            cout<<name<<":我有钱"<<money<<endl;
            //访问同名的父类的成员
            cout<<name<<":我从父类继承的钱"<<Animal::money<<endl;
        }
};

class Cat:public Animal{
    public:
    string breed;
        Cat(int age,string name):Animal(age,name){
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
    Cat cat(1,"kitty");
    cat.Eat();
    Dog d("旺财",2);
    d.Shut();

    return 0;
}