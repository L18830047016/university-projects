#include <stdio.h>
#include<stdlib.h>
typedef int ElemType;

typedef struct node{
    ElemType data;
    struct node* next;
}Node;

//初始化链表
Node* initList(){
    Node* head=(Node*)malloc(sizeof(Node));
    head->data=0;
    head->next=NULL;
    return head;
}

//初始化节点（带节点数据域参数）
Node* initListWithElem(ElemType e){
    Node *node=(Node*)malloc(sizeof(Node));
    node->data=e;
    node->next=NULL;
    return node;
}

//头插法,第一个参数传头节点
int insertHead(Node *L,ElemType e){
    Node *p=(Node*)malloc(sizeof(Node));
    p->data=e;
    p->next=L->next;
    L->next=p;
    return 1;
}

int main(int argc, char const *argv[]) {

    Node* list =initList();
    insertHead(list,10);
    insertHead(list,200);

    return 0;
}