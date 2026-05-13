#include <stdio.h>

typedef struct{
    float Realpart;
    float Inagepart;
}Complex;

void Create(Complex *C,float x,float y){
    C->Realpart=x;
    C->Inagepart=y;
}

float GetReal(Complex C){
    return C.Realpart;
}
int main(int argc, char const *argv[]) {

    Complex c;
    Create(&c,50,1);
    float real=GetReal(c);
    printf("%f\n",real);
    return 0;
}