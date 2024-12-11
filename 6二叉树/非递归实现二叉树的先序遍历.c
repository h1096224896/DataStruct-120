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
    BiTree Stack[100];  // 利用一个数组来模拟栈
    int top = -1;  // 栈顶指针
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

// 非递归实现二叉树的中序遍历
// 思路：
//     1.定义一个栈Stack，一个指针p指向根结点
//     2.当p不为空或者栈不为空时，执行以下操作：
//         a.如果p不为空，根结点入栈，p指向左孩子
//         b.否则如果p为空，栈顶元素出栈，访问栈顶元素，p指向右孩子
void InOrderNonRecursion(BiTree T) {
    BiTree Stack[100];
    int top = -1;
    BiTree p = T;
    printf("中序遍历(非递归):");
    while (p || top != -1) {
        if (p != NULL) {  
            Stack[++top] = p;  
            p = p->lchild;
        }
        else {
            p = Stack[top--];  // 回溯
            printf("%c ", p->data);  // 访问根结点
            p = p->rchild;  // 遍历右子树
        }
    }
}

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
    printf("后序遍历(非递归):");
    while (p || top != -1) {
        if (p != NULL) {
            Stack[++top] = p;
            p = p->lchild;
        }
        else {
            p = Stack[top];
            if (p->rchild != NULL && p->rchild != r) {  // 右子树不为空且未被访问
                p = p->rchild;
                Stack[++top] = p;
                p = p->lchild;
            }
            else {
                p = Stack[top--];
                printf("%c ", p->data);
                r = p;  // 记录上一个访问的结点
                p = NULL;  // 置空
            }
        }
    }
}

int main(int argc, char const* argv[]) {
    BiTree T;
    Init_Tree(&T);
    Create_Tree(&T);
    PreOrder(T); printf("\n");
    PreOrderNonRecursion(T); printf("\n");
    InOrder(T); printf("\n");
    InOrderNonRecursion(T); printf("\n");
    PostOrder(T); printf("\n");
    PostOrderNonRecursion(T); printf("\n");

    return 0;
}
