#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

atomic<int> counter=0;

void add(){
    for(int i=0;i<10000;i++){
        //原子自增操作
        counter.fetch_add(1,memory_order_relaxed);
    }
}

int main(void){
  thread t1(add);
  thread t2(add);
  t1.join();
  t2.join();

  cout<<"counter:"<<counter<<endl;
  
  return 0;
}