#include <stdio.h>


int main(int argc, char const *argv[]) {

    int a[]={15,33,32,45,31};
    int *p;
    p=a;
    for(int i=0;i<(sizeof(a)/sizeof(int));i++){
        printf("%d      ",a[i]);
    }
    printf("\n");
    for(int i=0;i<(sizeof(a)/sizeof(int));i++){
        printf("%d      ",*(p+i));
    }
    return 0;
}       