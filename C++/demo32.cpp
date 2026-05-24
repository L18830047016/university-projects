#include <iostream>
#include <thread>
using namespace std;

//线程执行体，回调函数
void print(string name, int n){
    for(int i=0;i<n;i++){
        cout<<name<<":好好学习"<<endl;
    }
}

int main(){
    //创建子线程
    //print → 函数指针，线程入口点
    //"t1" → 字面量，会自动转换为 string 类型
    //5 → int 整数
    thread t1(print,"t1",5);//这里函数名print会被隐式转换为函数指针
    thread t2(print,"t2",5);
    //让主线程等待子线程执行结束后，再继续执行
    // t1.join();
    // t2.join();
    //主线程不等待子线程
    t1.detach();
    t2.detach();

    cout<<"main over"<<endl;
    return 0;
}