#include <stdio.h>
int func(int j){
    int sum=0;
    for(int i=0;i<=j;i++){
        sum+=i;
    }
    return sum;
}
int main(){
    int sum=0,j=0;
    printf("please input a max number:");
    scanf("%d",&j);
    sum=func(j);
    printf("the sum is %d",sum);
    return 0;
}