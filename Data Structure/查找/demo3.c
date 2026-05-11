#include <stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct TreeNode{
    ElemType data;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
}TreeNode;

typedef TreeNode* BiTree;

int treeArr[]={70,55,49,30,-1,39,-1,-1,53,-1,-1,-1,80,75,-1,-1,98,95,-1,-1,-1};
int idx=0;

// 递归先序方式构建二叉树（含空节点）
void createTree(BiTree *T)
{
	ElemType num;
	num = treeArr[idx++];  // 取当前索引位置的值

	if (num == -1)
	{
		// -1 代表空指针
		*T = NULL;
	}
	else
	{
		// 创建新节点并递归构建左右子树
		*T = (BiTree)malloc(sizeof(TreeNode));
		(*T)->data = num;
		createTree(&(*T)->lchild);  // 构建左子树
		createTree(&(*T)->rchild);  // 构建右子树
	}
}

//前序遍历打印二叉树节点值（调试用）
void preOrder(BiTree T){
    if(T==NULL) {
        return;
    }
	printf("%d ", T->data);     // 访问当前节点
	preOrder(T->lchild);        // 遍历左子树
	preOrder(T->rchild);        // 遍历右子树

}

int search_bst(BiTree T,int value,BiTree parent,BiTree *pos){
    if(T==NULL){
        *pos=parent;// 递归到空节点，查找失败，将父节点返回（后面内容可用于插入）
        return 0;
    }

    if(T->data==value){
        *pos=T;
        return 1;
    }
    if(T->data>value){
        return search_bst(T->lchild,value,T,pos);
    }
    else
	{
		return search_bst(T->rchild, value, T, pos); // 要查找的值比当前节点大，往右子树找
	}
}

int main(int argc, char const *argv[]) {

    BiTree T;
    createTree(&T);//创建二叉排序树

    BiTree searchT;
    search_bst(T,53,NULL,&searchT);

    preOrder(T);
    printf("\n");

	printf("%d\n", searchT->data);  // 输出查找到的节点值

    return 0;
}