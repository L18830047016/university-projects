#include <stdio.h>

typedef struct{
    int x;
    int y;
}po;

int main(int argc, char const *argv[]) {

    po p;
    p.x=3;
    p.y=5;
    printf("x=%d,y=%d",p.x,p.y);    

    return 0;
}