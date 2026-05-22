//当通过基类指针删除派生类对象时，如果基类的构析函数不是虚函数，
// 则只会调用基类的构析函数，而不会调用派生类的构析函数，
// 导致派生类部分资源无法释放，造成内存泄漏

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
  // 普通析构函数
  ~Animal(){
    cout<<"执行 ~Animal()"<<endl;
  }
// //   父类的虚析构函数
//   virtual ~Animal(){
//     cout<<"执行 ~Animal()"<<endl;
//   }

  // 虚函数，让子类覆盖该函数
  virtual void Eat(){
    cout<<name<<"吃东西"<<endl;
  }
  // 纯虚函数
  virtual void sleep()=0;
};

class Dog:public Animal{
public:
  string color;

  Dog(){
    cout<<"执行 Dog()"<<endl;
  }
  ~Dog(){
    cout<<"执行 ~Dog()"<<endl;
  }
  void Shut(){
    cout<<name<<"汪汪叫"<<endl;
  }
  // 对父类的Eat()做了“表面”的覆盖
  void Eat(){
    cout<<name<<"啃大骨头"<<endl;
  }
  // 必须重写父类的纯虚函数
  void sleep(){
    cout<<name<<"趴着睡觉"<<endl;
  }
};

int main(void){
  Animal *a=new Dog();
  a->name="旺财";
  a->Eat();
  delete a;
  a=nullptr;
   Dog d;
   d.name="旺财";
   d.Eat();

  return 0;
}
