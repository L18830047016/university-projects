#include <iostream>

using namespace std;

int main(){
    //无参无返回值lambda表达式
    //auto test1=[]()->void{
    //cout<<"执行无参无返回值lambda表达式"<<endl;
    //};
    auto test1=[]{
        cout<<"执行无参无返回值lambda表达式"<<endl;
    };
    test1();//手动调用lambda表达式
    //有参有返回值
    auto test2=[](int x,int y)->int{//->int 为返回值类型
        return x+y;
    };
    cout<<"执行有参有返回值lambda表达式:"<<test2(1,2)<<endl;
    int count=666;
    int score=99;
    //按值捕获，不能在实现部分改变捕获的值，但可以在捕获时改变，改变的值不会映射到表达式外部
        //捕获部分
        auto test3=[count,score=100]{
            // count=888; // 不能在内部修改按值捕获的变量值
            cout<<"test3 lambda表达式捕获到了count:"<<count<<endl;
            cout<<"test3 lambda表达式捕获到了score:"<<score<<endl;
        };
        //执行test3
        test3();

        //捕获所有
        auto test4=[=]{
            //count=888; // 不能在内部修改按值捕获的变量值
            cout<<"test3 lambda表达式捕获到了count:"<<count<<endl;
            cout<<"test3 lambda表达式捕获到了score:"<<score<<endl;
        };
        //执行test4
        test4();
    
    cout<<"count="<<count<<",score="<<score<<endl;
        
    //按引用捕获所有
    auto test5=[&]{
        count=888; // 能在内部修改按值捕获的变量值
        score=100;    
        cout<<"test3 lambda表达式捕获到了count:"<<count<<endl;
        cout<<"test3 lambda表达式捕获到了score:"<<score<<endl;
    };
    test5();

    cout<<"count="<<count<<",score="<<score<<endl;

    return 0;
}