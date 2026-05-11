#include<stdio.h>

void func(int j)
{
    int sum=0;
    for(int i=1;i<=j;i++){
        sum+=i;
    }
    printf("sum=%d\n",sum);
}
int main(){
    func(100);
    return 0;
}