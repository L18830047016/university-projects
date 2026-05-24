#include <iostream>
#include <thread>
#include <mutex>
#include <windows.h>
using namespace std;

//共享资源
int ticket=10;
int num=0;
mutex mtx;//全局锁

//售票线程执行体
void sell_ticket(const string &name){
    while(1){
        Sleep(20);
        //自动锁
        lock_guard<mutex> locker(mtx);
        if(ticket<=0){
            break;
        }    
        ticket--; // 模拟售出票
        num++;
        printf("%s买到了第%d张票，剩余%d张票\n",name.c_str(),num,ticket);
    }
}

int main(void){
  thread t1(sell_ticket,"张三");
  thread t2(sell_ticket,"李四");
  thread t3(sell_ticket,"王五");
  t1.join();
  t2.join();
  t3.join();

  printf("售票结束\n");
  return 0;
}