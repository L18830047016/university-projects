#include <stdio.h>

int fibonacci(int n){
    int last1=1;
    int last2=1;
    int sum=0;
    for(int i=3;i<=n;i++){
        sum=last1+last2;
        last2=last1;
        last1=sum;
    }
    return sum;
}
int main(int argc, char const *argv[]) {

    printf("%d\n",fibonacci(6));

    return 0;
}