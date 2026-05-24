#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    //vector特性(具有许多API函数)：
    // 1. 动态大小：可以在运行时自动增长和收缩
    // 2. 连续存储：元素在内存中连续存放
    // 3. 随机访问：通过索引 O(1) 时间访问
    // 4. 尾部操作高效：末尾插入/删除 O(1)
    // 5. 中间操作低效：中间插入/删除 O(n)
    vector<int> v={9,2,3,4,5,6,1,8};
    int target=50;
    //auto iterator = find_if(begin, end, predicate);
    //begin/end：迭代器范围[begin,end)
    //predicate：返回 bool 的函数对象（Lambda/函数指针/仿函数）
    //返回值：第一个满足条件的元素的迭代器，找不到则返回 end
    auto res =find_if(v.begin(),v.end(),[target](int n){
        return n>target;
    });
    if(res!=v.end()){
        cout<<"目标："<<*res<<endl;
    }else{
        cout<<"没找到"<<endl;
    }
    //sort(begin, end);                              // 默认升序
    //sort(begin, end, comp);                        // 自定义比较函数
    sort(v.begin(),v.end(),[](int a,int b){return a<b;});

    //以值拷贝方式遍历容器v
    for(auto item:v){
        cout<<item<<" ";
    }
    cout<<endl;

    return 0;
}