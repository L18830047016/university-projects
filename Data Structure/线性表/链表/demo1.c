#include <stdio.h>
#include<stdlib.h>
typedef int ElemType;

typedef struct node
{
    ElemType data;
    struct node *next;
}Node;

//初始化链表
Node *InitList(){
    Node *head=(Node*)malloc(sizeof(Node));
    head->data=0;
    head->next=NULL;
    return head;
}
int main(int argc, char const *argv[]) {

    Node *list =InitList();

    return 0;
}