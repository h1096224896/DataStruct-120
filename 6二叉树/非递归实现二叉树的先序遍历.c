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
    BiTNode* p = T;
    printf("先序遍历(非递归):");
    while (p != NULL || top != -1) {   // p不为空或者栈不为空
        if (p != NULL) {
            printf("%c ", p->data);
            Stack[++top] = p;  // 入栈
            p = p->lchild;  // 遍历左子树
        }
        else {
            p = Stack[top--]; // 出栈
            p = p->rchild;  // 回溯
        }
    }
}


void fun(BiTree T) {
    BiTNode* stack[100];  // 利用一个数组来模拟栈
    int top = -1;
    BiTNode* p = T;
    printf("先序遍历(非递归)：");
    while (p != NULL || top != -1) {
        if (p != NULL) {   // 如果当前元素不为空,打印并入栈,遍历左子树
            printf("%c ", p->data);
            stack[++top] = p;
            p = p->lchild;
        }
        else {  // 若果当前节点为空,回溯,遍历右子树
            p = stack[top--];
            p = p->rchild;
        }
    }
}

int main(int argc, char const* argv[]) {
    BiTree T;
    Init_Tree(&T);
    Create_Tree(&T);
    fun(T);
    return 0;
}
