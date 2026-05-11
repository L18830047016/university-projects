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

//头插法
int inserthead(Node* head, ElemType e){
    Node *p=(Node*)malloc(sizeof(Node));
    p->data=e;
    p->next=head->next;
    head->next=p;
    return 0;
}

//遍历
void listNode(Node *head){
    Node *p=head->next;
    while(p!=NULL){
        printf("%d      ",p->data);
        p=p->next;
    }
    printf("\n");
}
//获取尾部节点
Node* gettail(Node* head){
    Node *p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    return p;
}

//尾插法
Node* inserttail(Node* tail,ElemType e){
    Node* p=(Node*)malloc(sizeof(Node));
    p->data=e;
    tail->next=p;
    p->next=NULL;
    return p;
}

//指定位置插入
int insertNode(Node* head,int pos,ElemType e){
    Node *p=head;
    int i=0;

/*
 while(i<pos-1){
        p=p->next;
        i++;
        if(p==NULL){
            return 0;
        }
    }
*/   
    for(;pos>1;pos--){
        p=p->next;
         if(p==NULL){
            return 0;
        }
    }
   Node *q = (Node*)malloc(sizeof(Node));
	q->data = e;
	q->next = p->next;
	p->next = q;
	return 1;

}
int main(int argc, char const *argv[]) {

    Node *list = initList();
	Node *tail = gettail(list);
	tail  = inserttail(tail, 10);
	tail  = inserttail(tail, 20);
	tail  = inserttail(tail, 30);
	listNode(list);
	insertNode(list, 2, 15);
	listNode(list);

    return 0;
}