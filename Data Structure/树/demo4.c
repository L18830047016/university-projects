#include <stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef char TreeType;

typedef struct TreeNode{
   TreeType data;
   struct TreeNode *lchild;
   struct TreeNode* rchild;
    
}TreeNode;

typedef TreeNode* ElemType;

typedef struct{
    ElemType *data;
    int front;
    int rear;
}Queue;

typedef TreeNode* BiTree;

char str[]="ABDH#K###E##CFI###G#J##";
int idx=0;

void createTree(BiTree* T){
    TreeType ch;
    ch=str[idx++];
    if(ch=='#'){
        *T=NULL;
    }else{
        *T=(BiTree)malloc(sizeof(TreeNode));
        (*T)->data=ch;
        createTree(&(*T)->lchild);
        createTree(&(*T)->rchild);
    }
}

//初始化
Queue* initQueue(){
    Queue* q=(Queue*)malloc(sizeof(Queue));
    q->data=(ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
    q->front=0;
    q->rear=0;
    return q;
}

//判断队列是否为空
int isEmpty(Queue* Q){
    if(Q->front==Q->rear){
        printf("队空\n");
        return 1;
    }
    else{
        return 0;
    }
}

//入队
int equeue(Queue* q,ElemType e){
    if((q->rear+1)%MAXSIZE==q->front){
        printf("队满\n");
        return 0;
    }
    q->data[q->rear]=e;
    q->rear=(q->rear+1)%MAXSIZE;
    return 1;
}

//出队
int dequeue(Queue *Q,ElemType* e){
    if (Q->front == Q->rear)
	{
		printf("空的\n");
		return 0;
	}
    *e=Q->data[Q->front];
    Q->front=(Q->front+1)%MAXSIZE;
    return 1;
}

//获取队头元素
int getHead(Queue* Q,ElemType* e){
    if(Q->front==Q->rear){
        printf("队空\n");
        return 0;
    }
    *e=Q->data[Q->front];
    return 1;
}

//获取队列元素个数
int queueSize(Queue* Q){
    if(!isEmpty(Q)){
        return Q->rear-Q->front;
    }
    return 0;
}

int maxDepth(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int depth=0;
    Queue* q=initQueue();
    equeue(q,root);

    while(!isEmpty(q)){

        //单层全部出队，把他们的孩子全部入队
        int count=queueSize(q);
        while(count>0){
            TreeNode* curr;
            dequeue(q,&curr);
            if(curr->lchild!=NULL){
                equeue(q,curr->lchild);
            }
            if(curr->rchild!=NULL){
                equeue(q,curr->rchild);
            }
            count--;
        }

        depth++;
    }
    return depth;
}
int main(int argc, char const *argv[]) {

    BiTree T;
	createTree(&T);
	printf("%d\n", maxDepth(T));

    return 0;
}