#include <iostream>
using namespace std;

//定义动物类父类
class Animal{
    public:
        int age;
        string name;
        //虚函数，子类可重写
        virtual void Eat(){
            cout<<name<<"吃东西"<<endl;
        }
};

class Dog:public Animal{
    public:
        string color;
        void Shut(){
            cout<<name<<"汪汪叫"<<endl;
        }
        //对父类的Eat（）做了表面覆盖
        void Eat(){
            cout<<name<<"啃大骨头"<<endl;
        }
};

class Cat:public Animal{
    public:
        string breed;
        void CatchMouse(){
            cout<<name<<"抓老鼠"<<endl;
        }
        void Eat(){
            cout<<name<<"吃小鱼干"<<endl;
        }
};

class Rabbit:public Animal{
    public:
        void BiteSth(){
            cout<<name<<"咬东西"<<endl;
        }
        void Eat(){
            cout<<name<<"吃胡萝卜"<<endl;
        }
};

class Tiger:public Animal{
    public:
        string type;
        void Eat(){
            cout<<name<<"吃肉"<<endl;
        }
};

//饲养员
class Breeder{
    public:
        //将参数的类型由具体类型改为通用的父类类型
        //这样可以解除模块和具体类型的耦合度
        void feedAnimal(Animal &animal){
            animal.Eat();
        }
        // 喂养小动物的系列行为,使用重载优化代码结构，方便调用
        /*
        void feedAniaml(Cat &animal){
            animal.Eat();
        }
        void feedAniaml(Dog &animal){
            animal.Eat();
        }
        void feedAniaml(Rabbit &animal){
            animal.Eat();
        }  
        */
};

int main(){
    Cat cat;
    cat.name="kitty";
    Dog dog;
    dog.name="旺财";
    Breeder breeder;
    breeder.feedAnimal(cat);
    breeder.feedAnimal(dog);
    Rabbit r;
    r.name="小灰";
    breeder.feedAnimal(r);
    Tiger t;
    t.name="泰哥";
    breeder.feedAnimal(t);

    return 0;
}