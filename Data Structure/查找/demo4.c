#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct TreeNode{
    ElemType data;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
}TreeNode;

typedef TreeNode* BiTree;

void preOrder(BiTree T)
{
	if (T == NULL)
	{
		return;
	}
	preOrder(T->lchild);          // 遍历左子树
	printf("%d ", T->data);    
	preOrder(T->rchild);          // 遍历右子树
}

int search_bst(BiTree T,ElemType value,BiTree parent,BiTree* pos){
    if(T==NULL){
        *pos=parent;
        return 0;
    }
    if(T->data==value){
        *pos=T;
        return 1;
    }else if(T->data>value){
        search_bst(T->lchild,value,T,pos);
    }else{
        search_bst(T->rchild,value,T,pos);
    }

}

int insert_bst(BiTree* T,int value){
    BiTree pos;
    BiTree curr=NULL;

    int status=search_bst(*T,value,NULL,&pos);

    if(status==0){

        curr=(BiTree)malloc(sizeof(TreeNode));
        curr->data=value;
        curr->lchild=NULL;
        curr->rchild=NULL;

        if(*T==NULL){
            *T=curr;
        }else if(value<pos->data){
            pos->lchild=curr;
        }else{
            pos->rchild=curr;
        }
        return 1;
    }
    else{
        return 0;
    }  
}


int main(int argc, char const *argv[]) {

    int i = 0;
	BiTree T = NULL;

	// 准备插入的初始序列
	int treeArr[] = {70, 55, 49, 30, 39, 53, 80, 75, 98, 95};

	// 批量插入
	for (int i = 0; i < 10; i++)
	{
		insert_bst(&T, treeArr[i]);
	}

	preOrder(T); // 查看当前树结构
	printf("\n");

	insert_bst(&T, 99); // 插入一个新值 99

	preOrder(T); // 再次查看树结构
	printf("\n");

    return 0;
}