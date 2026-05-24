#include <iostream>
#include <thread>


using namespace std;

int counter=0;

void add(){
  for(int i=0;i<10000;i++){
    counter++;
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