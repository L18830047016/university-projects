#include <stdio.h>
#include<stdlib.h>
typedef struct{
    int x;
    int y;
}po;
int main(int argc, char const *argv[]) {

    po *p;
    p=(po*)malloc(sizeof(po));
    p->x=3;
    p->y=5;
    printf("x=%d,y=%d",p->x,p->y);
    free(p);
    return 0;
}