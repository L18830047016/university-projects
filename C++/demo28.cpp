#include <iostream>
#include <memory>

using namespace std;

class TestA{
    public:
        int data=100;
        TestA(){
            cout<<"调用TestA()"<<endl;
        }
        ~TestA(){
            cout<<"调用~TestA()"<<endl;
        }
};

int main(){
    //智能指针，共享所有权
    shared_ptr<TestA> ptr1=make_shared<TestA>();
    cout<<"count:"<<ptr1.use_count()<<endl;//count=1;ptr1
    cout<<"ptr1->data:"<<ptr1->data<<endl;
    cout<<"prt1:"<<ptr1.get()<<endl;
    cout<<"count:"<<ptr1.use_count()<<endl;//count=1;ptr1

    //定义ptr2
    shared_ptr<TestA> ptr2=ptr1;
    cout<<"ptr2 count:"<<ptr2.use_count()<<endl;//count=2;ptr1、ptr2
    cout<<"ptr2->data:"<<ptr2->data<<endl;
    cout<<"ptr2:"<<ptr2.get()<<endl;

    cout<<"count:"<<ptr1.use_count()<<endl;//count=2;ptr1、ptr2

     {
    // 定义ptr3,ptr3的作用域在{}，{}结束=>ptr3 delete
    shared_ptr<TestA> ptr3=ptr1;
    cout<<"prt3 count:"<<ptr3.use_count()<<endl;//count=3;ptr1,ptr2,ptr3
    cout<<"ptr3->data:"<<ptr3->data<<endl;    
    cout<<"prt3:"<<ptr3.get()<<endl;
     }
  cout<<"count:"<<ptr1.use_count()<<endl;  //count=2;ptr2,ptr1

  return 0;
}