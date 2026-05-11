#include <stdio.h>


int main(int argc, char const *argv[]) {

    int a=5;
    int *p=&a;
    printf("%p\n",&a);

    printf("p的地址为%p,p的值为%p\n",&p,p);

    return 0;
}