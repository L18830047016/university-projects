#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct node{
	ElemType data;
	struct node *next;
}Node;

//初化链表
Node* initList()
{
	Node *head = (Node*)malloc(sizeof(Node));
	head->data = 0;
	head->next = NULL;
	return head;
}

//头插法
int insertHead(Node* L, ElemType e)
{
	Node *p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->next = L->next;
	L->next = p;
	return 1;
}

//遍历
void listNode(Node* L)
{
	Node *p = L->next;
	while(p != NULL)
	{
		printf("%d   ", p->data);
		p = p->next;
	}
	printf("\n");
}

//获取尾部节点
Node* gettail(Node* L){
    Node* p=L;
    while(p->next!=NULL){
        p=p->next;
    }
    return p;
}

//尾插法(返回新尾巴)
Node* insertTail(Node *tail,ElemType e){
    Node *p = (Node*)malloc(sizeof(Node));
	p->data = e;
	tail->next = p;
	p->next = NULL;
	return p;
}
int main(int argc, char const *argv[]) {

    Node *list = initList();
	Node *tail = gettail(list);
	tail  = insertTail(tail, 10);
	tail  = insertTail(tail, 20);
	tail  = insertTail(tail, 30);
	listNode(list);
 
	return 0;


    return 0;
}