#include <iostream>
using namespace std;

class FatherA{
    public:
        int moneyA=666;
        int data=999;
};
class FatherB{
    public:
        int moneyB=888;
        int data=111;
};

class Son:public FatherA,public FatherB{
    public:
        void showMoney(){
            cout<<"moneyA:"<<moneyA<<endl;
            cout<<"moneyB:"<<moneyB<<endl;
        }
        void showData(){
            //二义性问题
            //cout<<"data:"<<data<<endl;
            //二义性问题可以用作用域运算解决
            cout<<"fatherA data:"<<FatherA::data<<endl;
            cout<<"fatherB data:"<<FatherB::data<<endl;
        }
};

int main(){
    Son son;
    son.showMoney();
    son.showData();
    return 0;
}