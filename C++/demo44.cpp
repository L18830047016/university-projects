#include <iostream>
#include <thread>
#include <mutex>
#include <windows.h>

using namespace std;

mutex mtx1,mtx2;

void func1(){
    cout<<"t1执行"<<endl;
    lock_guard<mutex> locker1(mtx1);
    cout<<"t1锁住了mtx1"<<endl;
    Sleep(100); // 增加死锁机会
    // 尝试获取mtx2
    lock_guard<mutex> locker2(mtx2);
    cout<<"t1锁住了mtx2"<<endl;
}

void func2(){
    cout<<"t2执行"<<endl;
    lock_guard<mutex> locker2(mtx2);
    cout<<"t2锁住了mtx2"<<endl;
    Sleep(100); // 增加死锁机会
    // 尝试获取mtx1
    lock_guard<mutex> locker1(mtx1);
    cout<<"t2锁住了mtx1"<<endl;
}

int main(){
    thread t1(func1);
    thread t2(func2);

    t1.join();
    t2.join();

    cout<<"main over";

    return 0;
}