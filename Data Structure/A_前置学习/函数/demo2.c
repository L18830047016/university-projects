#include<stdio.h>

void func()
{
    int sum=0;
    for(int i=1;i<=100;i++){
        sum+=i;
    }
    printf("sum=%d\n",sum);
}
int main(){
    func();
    return 0;
}