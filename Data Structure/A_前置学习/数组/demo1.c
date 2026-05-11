#include <stdio.h>


int main(int argc, char const *argv[]) {

    int a[]={16,56,256,156,728};
    for(int i=0;i<(sizeof(a)/sizeof(int));i++){
        printf("%d      ",a[i]);
    }

    return 0;
}