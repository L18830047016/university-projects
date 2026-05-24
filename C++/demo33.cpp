#include <iostream>
#include <thread>
using namespace std;

class PrintTask{
    public:
    //运算符（）重载
    void operator()(string name,int n){
        for(int i=0;i<n;i++){
            cout<<name<<"好好学习"<<endl;
        }
    }
};

int main(){
    thread t1(PrintTask(),"t1",5);
    thread t2(PrintTask(),"t2",5);
    t1.join();
    t2.join();
  
    return 0;

}