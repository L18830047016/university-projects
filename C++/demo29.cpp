#include <iostream>
#include <memory>
using namespace std;

struct TestA;
struct TestB;

struct TestA{
    weak_ptr<TestB> testB;
    TestA(){
        cout<<"调用TestA()"<<endl;
    }
    ~TestA(){
        cout<<"调用~TestA()"<<endl;
    }
};
struct TestB{
    weak_ptr<TestA> testA;
    TestB(){
        cout<<"调用TestB()"<<endl;
    }
    ~TestB(){
        cout<<"调用~TestB()"<<endl;
    }
};

int main(){
    auto testA=make_shared<TestA>();//等价于shared_ptr testA=make_shared<testA>()
    auto testB=make_shared<TestB>();//等价于shared_ptr testB=make_shared<testB>()
    testA->testB=testB; // testA对象里面的智能指针(虚)，指向了testB（实）对象
    testB->testA=testA; // testB对象里面的智能指针（虚），指向了testA(实)对象
    cout<<"testA use_count:"<<testA.use_count()<<endl;
    cout<<"testB use_count:"<<testB.use_count()<<endl;

    return 0;
}