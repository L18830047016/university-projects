#include<stdio.h>
int func(int j){
    int sum=0;
    for(int i=0;i<=j;i++){
        sum+=i;
    }
    return sum;
}
int main(){
    int sum=func(100);
    printf("sum=%d\n",sum);
    return 0;
}