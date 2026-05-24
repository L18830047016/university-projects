#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <windows.h>
#include <stdio.h>
using namespace std;

mutex mtx;
condition_variable cv;
boolean ready =false;

void runner(string name){
    printf("运动员%s预备\n",name.c_str());
    unique_lock<mutex> locker(mtx);

    //让当前线程等待，直到ready变成true
    cv.wait(locker,[]{return ready;});
    //等价于：
        // while (!ready) {
        //     cv.wait(locker);
        // }

    printf("运动员%s跑步\n",name.c_str());
};

void coach(){
    //模拟教练开枪
    {
        unique_lock<mutex> locker(mtx);
        ready=true;
        printf("教练开枪\n");
    }
    //通知等待的线程，让线程检查lambda表达式条件
    cv.notify_all();
}

int main(void){
  thread t1(runner,"tom");
  thread t2(runner,"jerry");
  thread t3(coach);
  t1.join();
  t2.join();
  t3.join();


  return 0;
}