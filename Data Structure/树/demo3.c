#include <stdio.h>
#include <stdlib.h>
typedef char ElemType;

//定义线索二叉树的节点结构
typedef struct ThreadNode{
    ElemType data;//节点存储的数据
    struct ThreadNode* lchild; // 左指针：指向左孩子或前驱
    struct ThreadNode* rchild;// 右指针：指向右孩子或后继
    int ltag;// 左标志：0 表示左孩子，1 表示前驱线索
    int rtag;// 右标志：0 表示右孩子，1 表示后继线索
}ThreadNode;

typedef ThreadNode* ThreadTree;
char str[]="ABDH##I##EJ###CF##G##";
int idx=0;
ThreadTree prev;//全局变量：用于记录前一个访问的节点

//创建普通二叉树（根据字符串str）
void createTree(ThreadTree* T){
    ElemType ch=str[idx++];
    if(ch=='#'){
        *T=NULL;//空节点
    }else{
        *T=(ThreadTree)malloc(sizeof(ThreadNode));
        (*T)->data=ch;
        createTree(&(*T)->lchild);
        (*T)->ltag=(*T)->lchild?0:1;
        createTree(&(*T)->rchild);
        (*T)->rtag=(*T)->rchild?0:1;
    }
}

//中序线索化函数：建立前驱/后继关系
void threading(ThreadTree T){
    if(T!=NULL){
        threading(T->lchild);//递归线索化左子树
        //如果当前节点的左指针是空，简历前驱线索
        if(T->ltag==1)
            T->lchild=prev;

        //如果前一个节点的右指针是空，建立其后继线索指向当前节点
        if(prev&&prev->rtag==1)
            prev->rchild=T;

        prev=T;//更新prev为当前节点
        threading(T->rchild);//递归线索化右子树
    }
}

//创建头节点，调用线索化过程，建立线索化二叉树
void inOrderThreading(ThreadTree* T,ThreadTree* head){
    *head=(ThreadTree)malloc(sizeof(ThreadNode));//创建头节点
    (*head)->data='0';
    (*head)->ltag=0;
    (*head)->rtag=1;
    (*head)->rchild=*head;//初始时回指自己

    if(*T==NULL){
        (*head)->lchild=*head;
    }else{
        (*head)->lchild=*T;//头节点左指针指向根节点
        prev=*head; //初始化前驱指针
        threading(*T);//中序线索化整个树

        //补全最后一个节点的后继线索
        prev->rchild=*head;
        //prev->rtag=1;
       // (*head)->rchild=prev;//头节点的rchild指向最后一个节点
    }
}

//中序遍历线索化后的二叉树（非递归）
void inOrder(ThreadTree T){
    ThreadTree curr=T->lchild;//从头节点的左子树开始（跟节点）
    while(curr!=T){
        //沿着左孩子一直走到底
        while(curr->ltag==0)
        curr=curr->lchild;
        //访问当前节点
        printf("%c",curr->data);

        //顺着线索一直向右访问所有后继
        while(curr->rtag==1&&curr->rchild!=T){
            curr=curr->rchild;
            printf("%c",curr->data);
        }

        //进入当前节点右子树
        curr=curr->rchild;
    }
}
int main(int argc, char const *argv[]) {

     ThreadTree T, head;
    createTree(&T);               // 创建原始二叉树
    inOrderThreading(&T, &head); // 执行线索化处理
    printf("中序遍历结果：");
    inOrder(head);                // 遍历线索二叉树

    return 0;
}