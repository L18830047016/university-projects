#include <iostream>
#include <thread>
using namespace std;
int main(void){
  thread t1([](int n){
    for (int i = 0; i < n; i++){
      cout<<"t1"<<":好好学习，天天向上!"<<endl;
    }  
  },5);
  thread t2([](int n){
    for (int i = 0; i < n; i++){
      cout<<"t2"<<":好好学习，天天向上!"<<endl;
    }  
  },5);

  
    t1.join();
    t2.join();
  return 0;
}