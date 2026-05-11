#include <stdio.h>

#define MAXSIZE 100
typedef int ElemType;

//顺序表定义
typedef struct 
{
    ElemType data[MAXSIZE];
    int length;
}SeqList;

//顺序表初始化
void initlist(SeqList *L){
    L->length=0;
    printf("初始化成功\n");
}

//顺序表尾插
void appendElem(SeqList *L,ElemType e){
    if(L->length>=MAXSIZE){
        printf("顺序表已满\n");
        return;
    }
    L->data[L->length]=e;
    L->length++;
}

//遍历
void listElem(SeqList *l){
    for(int i=0;i<l->length;i++){
        printf("%d     ",l->data[i]);
        if(i%5==4){
            printf("\n");
        }
    }
}

//插入数据
int insertElem(SeqList *l,int pos,ElemType e){
    if(l->length>=MAXSIZE){
         printf("顺序表已满\n");
        return 0;
    }
    if(pos<1||pos>l->length){
        printf("插入位置错误\n");
        return 0;
    }
    if(pos<=l->length){
        for(int i=l->length-1;i>=pos-1;i--){
            l->data[i+1]=l->data[i];
        }
        l->data[pos-1]=e;
        l->length++;
    }
    return 1;
}
int main(int argc, char const *argv[]) {

    //声明一个线性表并初始化
	SeqList list;
	initlist(&list);
	printf("初始化成功，目前长度占用%d\n",list.length);
	printf("目前占用内存%zu字节\n", sizeof(list.data));
	appendElem(&list, 88);
	appendElem(&list, 67);
	appendElem(&list, 40);
	appendElem(&list, 8);
	appendElem(&list, 23);
	listElem(&list);
	insertElem(&list, 2, 18);
	listElem(&list);
    return 0;
}