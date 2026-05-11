#include<stdio.h>
#include<string.h>
int main(){
    char str[]="HelloWorld";
    printf("%s\n",str);

    char str2[11];
    strcpy(str2,"HelloWorld");
    printf("%s\n",str2);

    return 0;
}