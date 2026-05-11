#include <stdio.h>


int main(int argc, char const *argv[]) {

    int a[]={155,5877,579,656,0};
    printf("%zu\n",sizeof(a));
    printf("%zu\n",sizeof(a[0]));
    int len=sizeof(a)/sizeof(a[0]);
    printf("数组长度为%d\n",len);

    return 0;
}