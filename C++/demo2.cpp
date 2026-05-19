#include <iostream>
using namespace std;

//指针类型参数
void test(int *p){
    if(p!=nullptr){
        cout << "指针参数的值为：" << *p << endl;
    }
}

//引用类型参数
void test1(int &p){
    cout << "引用参数的值为：" << p << endl;
}

//函数声明
void printArr(int *arr,int size);
int main(){
    int num=666;
    int &p=num;//引用类型参数,p是num的别名
    test1(p);

    return 0;
}

//函数定义
void printArr(int *arr,int size){
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}