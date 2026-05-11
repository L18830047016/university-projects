#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef char ElemType;

typedef struct TreeNode{
    ElemType data;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
}TreeNode;

typedef TreeNode* BiTree;

typedef struct{
    BiTree* data;
    int top;
}Stack;

char str[]="ABDH#K###E##CFI###G#J##";
int idx=0;

//初始化栈
Stack* initStack(){
    Stack* s=(Stack*)malloc(sizeof(Stack));
    s->data=(BiTree*)malloc(sizeof(BiTree)*MAXSIZE);
    s->top=-1;
    return s;
}

//判断栈是否为空
int isEmpty(Stack* s){
    if(s->top==-1){
        printf("栈空\n");
        return 1;
    }
    else{
        return 0;
    }
}

//压栈
int push(Stack* s,BiTree e){
    if(s->top==MAXSIZE-1){
        printf("栈满\n");
        return 0;
    }
    s->top++;
    s->data[s->top]=e;
    return 1;
}

//出栈
int pop(Stack* s,BiTree* e){
    if(s->top==-1){
        printf("栈空\n");
        return 0;
    }
    *e=s->data[s->top--];
    return 1;
}

//获取栈顶元素
int getTop(Stack* s,BiTree* e){
     if(s->top==-1){
        printf("栈空\n");
        return 0;
    }
    *e=s->data[s->top];
    return 1;
}

//造树
void createTree(BiTree* T){
    ElemType ch;
    ch=str[idx++];
    if(ch=='#'){
        *T=NULL;
    }
    else{
        *T=(BiTree)malloc(sizeof(TreeNode));
        (*T)->data=ch;
        createTree(&(*T)->lchild);
        createTree(&(*T)->rchild);
    }
}

//前序遍历
void preOrder(BiTree T)
{
	if (T == NULL)
	{
		return;
	}

	printf("%c ", T->data);
	preOrder(T->lchild);
	preOrder(T->rchild);
}

//中序遍历
void inOrder(BiTree T)
{
	if (T == NULL)
	{
		return;
	}

	inOrder(T->lchild);
	printf("%c ", T->data);
	inOrder(T->rchild);
}

//后序遍历
void postOrder(BiTree T)
{
	if (T == NULL)
	{
		return;
	}

	postOrder(T->lchild);
	postOrder(T->rchild);
	printf("%c ", T->data);
}

//栈，前序遍历
void iterPreOrder(Stack* s,BiTree T){
    while(T!=NULL||isEmpty(s)==0){
        while(T!=NULL){
            printf("%c",T->data);
            push(s,T);
            T=T->lchild;
        }
        pop(s,&T);
        T=T->rchild;
    }
}

//栈，中序遍历
void iterInOrder(Stack* s,BiTree T){
    while(T!=NULL||isEmpty(s)==0){
        while(T!=NULL){
            push(s,T);
            T=T->lchild;
        }
        pop(s,&T);
        printf("%c",T->data);
        T=T->rchild;
    }
}
void iterpostOrder(Stack* s, BiTree T) {
    BiTree lastVisited = NULL;  // 上一个被访问的节点
    while (T != NULL || isEmpty(s) == 0) {
        // 步骤1: 将左子树全部压栈
        while (T != NULL) {
            push(s, T);
            T = T->lchild;
        }
        // 步骤2: 查看栈顶节点
        getTop(s, &T);
        // 步骤3: 判断是否可以访问当前节点
        // 条件：没有右子树 或者 右子树已经被访问过
        if (T->rchild == NULL || T->rchild == lastVisited) {
            pop(s, &T);              // 弹出
            printf("%c", T->data);   // 访问（后序位置）
            lastVisited = T;         // 记录已访问节点
            T = NULL;                // 重要：防止重复处理
        } else {
            // 步骤4: 有右子树且未被访问，转向右子树
            T = T->rchild;
        }
    }
}
int main(int argc, char const *argv[]) {

    BiTree T;
	createTree(&T);
	Stack *s = initStack();

	iterPreOrder(s, T);
	printf("\n");
	
	iterInOrder(s, T);
    printf("\n");

    iterpostOrder(s,T);

    return 0;
}