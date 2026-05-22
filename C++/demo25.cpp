#include <iostream>
using namespace std;

// 定义动物类的父类
class Animal{
public:
  int age;
  string name;

  Animal(){
    cout<<"执行 Animal()"<<endl;
  }
  // 虚函数，让子类覆盖该函数
  virtual void Eat(){
    cout<<name<<"吃东西"<<endl;
  }
  // 纯虚函数,含有纯虚函数的类叫做抽象类，抽象类不能被实例化
  virtual void sleep()=0;
};

class Dog:public Animal{
    public:
        string color;

        Dog(){
            cout<<"执行Dog（）"<<endl;
        }
        void Shut(){
            cout<<name<<"汪汪叫"<<endl;
        }
        void Eat(){
            cout<<name<<"啃大骨头"<<endl;
        }
        //必须重写父类的纯虚函数，否则子类也是抽象类
        void sleep(){
            cout<<name<<"趴着睡觉"<<endl;
        }
};

class Cat:public Animal{
public:
  void CatchMouse(){
    cout<<name<<"抓老鼠"<<endl;
  }
};//Cat也是抽象类

int main(){
    //子类对象可以保存到父类类型中
    Dog *a1=new Dog();
    a1->name="旺财";
    a1->age=1;
    a1->color="黄色";
    a1->Shut();
    a1->Eat();
    a1->sleep();
    
    Animal* a2=new Dog();
     a2->age=1;
    a2->name="小黑";
     // a2->color="黑色";
     a2->Eat();
     a2->sleep();

     return 0;
}