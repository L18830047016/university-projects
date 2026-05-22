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
    //智能指针，独占所有权
    unique_ptr<int> ptr1=make_unique<int>(10);//等价于unique_ptr<int> ptr1(new int(10));
    cout<<ptr1.get()<<endl;//获取指针
    cout<<*ptr1<<endl;

    unique_ptr<TestA> ptr2=make_unique<TestA> ();
    cout<<ptr2->data<<endl;

    return 0;
}