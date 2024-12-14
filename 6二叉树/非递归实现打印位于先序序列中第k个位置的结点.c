#include "二叉树.c"

void PreOrderNonRecursion(BiTree T, int k) {
    BiTree Stack[100];
    int top = -1;
    BiTree p = T;
    int cnt = 0;  // 计数器
    printf("先序遍历(非递归)：");
    while (p || top != -1) {   // p不为空或者栈不为空
        if (p != NULL) {  // 节点不为空
            cnt++;
            if (cnt == k) {
                printf("%c ", p->data);
                return;
            }
            Stack[++top] = p;
            p = p->lchild;
        }
        else {
            p = Stack[top--];  // 栈顶元素出栈, 回溯到栈顶元素的父节点
            p = p->rchild;    // 指向右孩子
        }
    }
}


int main(int argc, char const* argv[]) {
    BiTree T;
    Init_Tree(&T);
    Create_Tree(&T);
    return 0;
}
