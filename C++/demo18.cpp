#include <iostream>
using namespace std;

//定义类
class TestA{
    public:
        //在TestA中声明TestB类为它的友元类
        friend class TestB;
        void SetMoney(int money);
    private:
        int money;
};

//定义友元类B
class TestB{
    public:
        //友元函数
        void PeepMoney(TestA &testA);
};

//定义友元函数
void TestB::PeepMoney(TestA &testA){
    cout<<"test的money:"<<testA.money<<endl;
}

void TestA::SetMoney(int money){
    this->money=money;
}

int main(){
    TestA testA;
    testA.SetMoney(666);
    TestB testB;
    testB.PeepMoney(testA);

    return 0;
}