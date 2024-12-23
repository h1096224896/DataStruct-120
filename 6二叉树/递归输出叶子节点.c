#include "二叉树.c"


// 利用二叉树的遍历算法，输出叶子节点
void fun(BiTree T) {
    if (T) {
        if (T->lchild == NULL && T->rchild == NULL)
            printf("%d ", T->data);
        fun(T->lchild);
        fun(T->rchild);
    }
}

int main() {
    BiTree T = NULL;
    Create_Tree(&T);
    fun(T);
    return 0;
}