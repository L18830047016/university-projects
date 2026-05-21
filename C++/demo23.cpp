#include <iostream>
using namespace std;

class Father{
    public:
        Father(){
            cout<<"调用Father()"<<endl;
        }
};
//菱形继承问题，用虚拟继承解决（确保Father只被创建一次）
class SonA:virtual public Father{
//class SonA:public Father{
    public:
        SonA(){
            cout<<"调用SonA()"<<endl;
        }
};
class SonB:virtual public Father{
//class SonB:public Father{
    public:
        SonB(){
            cout<<"调用SonB()"<<endl;
        }
};
class GrandSon:public SonA,public SonB{
    public:
        GrandSon(){
            cout<<"调用GrandSon()"<<endl;
        }
};

int main(){
    GrandSon gs;
    return 0;
}