#include <iostream>
#include <thread>
#include <windows.h>
using namespace std;

// 共享资源


// 售票线程执行体
void sell_ticket(const string &name){
  // 线程私有资源
  int ticket=10; // 保存剩余票数
  int num=0; // 保存当前所售出的票号

  while(1){
    if(ticket<=0){
      break;
    }
    ticket--; // 模拟售出票
    Sleep(50);  // 让线程休眠，模拟网络延时
    num++;
    printf("%s买到了第%d张票，剩余%d张票\n",name.c_str(),num,ticket);
    //Sleep(50);
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