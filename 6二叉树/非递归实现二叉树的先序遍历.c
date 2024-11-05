#include "二叉树.c"

/*
    非递归实现二叉树的先序遍历
    思路：
        1.定义一个栈Stack，一个指针p指向根结点
        2.当p不为空或者栈不为空时，执行以下操作：
            a.如果p不为空，访问根结点，根结点入栈，p指向左孩子
            b.否则如果p为空，栈顶元素出栈，p指向右孩子
*/
void PreOrderNonRecursion(BiTree T) {
    BiTree Stack[100];
    int top = -1;
    BiTree p = T;
    printf("先序遍历(非递归)：");
    while (p || top != -1) {   // p不为空或者栈不为空
        if (p) {
            printf("%c ", p->data);
            Stack[++top] = p;
            p = p->lchild;
        }
        else {
            p = Stack[top--];
            p = p->rchild;
        }
    }
}


