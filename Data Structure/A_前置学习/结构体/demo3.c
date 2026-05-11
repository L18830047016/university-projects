#include <stdio.h>

struct point{
    int x;
    int y;

};
int main(int argc, char const *argv[]) {
    struct point p;
    p.x=5;
    p.y=3;
    struct point *ptr;
    ptr=&p;
    (*ptr).x=3;
    (*ptr).y=5;
    printf("x=%d,y=%d\n",p.x,p.y);
    printf("x=%d,y=%d\n",ptr->x,ptr->y);
    

    return 0;
}