#include <iostream>
#include <thread>
#include <stdio.h>

using namespace std;

//线程局部变量，每个线程拥有该变量的独立副本
thread_local int counter=0;

void add(const string &name){
  for(int i=0;i<5;i++){
    counter++;
    printf("%s counter:%d\n",name.c_str(),counter);
  }
}

int main(void){
  thread t1(add,"t1");
  thread t2(add,"t2");
  t1.join();
  t2.join();

  return 0;
}