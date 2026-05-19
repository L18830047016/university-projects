#include <iostream>
using namespace std;

void test(int *ptr){
    if(ptr!=nullptr){
        cout<<"ptr is not null, value is "<<*ptr<<endl;
    }
}

int main(){
    int num=666;
    //int *ptr1=nullpte;//空指针
    int *ptr1=&num;//指针指向num的地址
    test(ptr1);//通过指针间接传递
    test(&num);//通过指针直接传递

    int* ptr2=new int(10);//0x1100
    delete ptr2;//释放内存
    //test(ptr2);//ptr2成为野指针，指向已释放的内存
    ptr2=nullptr;//将ptr2置空，避免野指针问题
    test(ptr2);
    return 0;

}