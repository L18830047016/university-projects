#include <stdio.h>
int fibonacci(int n){
    if(n==2||n==1)
    return 1;
    return fibonacci(n-2)+fibonacci(n-1);
}

int main(int argc, char const *argv[]) {

    printf("%d\n",fibonacci(8));

    return 0;
}