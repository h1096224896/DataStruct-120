#include "二叉树.c"

// 非递归实现二叉树的后序遍历
// 思路：
//     1.定义一个栈Stack，一个指针p指向根结点，一个指针r指向上一个访问的结点
//     2.当p不为空或者栈不为空时，执行以下操作：
//         a.如果p不为空，访问根结点，根结点入栈，p指向左孩子
//         b.否则如果p为空，栈顶元素出栈，p指向右孩子
//         c.如果p的右孩子不为空且不等于r，p指向右孩子，右孩子入栈，p指向左孩子
//         d.否则，访问根结点，根结点出栈，r指向根结点，p置空
void PostOrderNonRecursion(BiTree T) {
    BiTree Stack[100];
    int top = -1;
    BiTree p = T;
    BiTree r = NULL;
    while (p || top != -1) {
        if (p) {
            Stack[++top] = p;
            p = p->lchild;
        }
        else {
            p = Stack[top];
            if (p->rchild && p->rchild != r) {
                p = p->rchild;
                Stack[++top] = p;
                p = p->lchild;
            }
            else {
                p = Stack[top--];
                printf("%c ", p->data);
                r = p;
                p = NULL;
            }
        }
    }
}

