#include <stdio.h>

int func(int n){
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=i;
    }
    return sum;
}
int main(int argc, char const *argv[]) {

    printf("%d\n",func(5));

    return 0;
}