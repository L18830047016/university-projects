#include <iostream>
using namespace std;

//定义一个类
class Test{
        //声明友元函数
        friend void PeepMoney(Test &t);
    private:
       int money;
    public:
        void SetMoney(int m);
};

//定义友元函数
void PeepMoney(Test &t){
    cout << "test的money = " << t.money << endl;
}

void Test::SetMoney(int m){
    money = m;
}

int main(){
    Test t;
    t.SetMoney(100);
    //通过友元函数能间接访问到对象t的私有成员
    PeepMoney(t);
    return 0;
}