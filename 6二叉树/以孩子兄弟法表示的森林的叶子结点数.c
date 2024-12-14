#include "二叉树.c"


//相当于统计二叉树中,只有右孩子或者叶子结点的结点的个数
int getForestLeaf(BiTree T) {
    if (T == NULL)   // 递归结束条件
        return 0;
    if (T->lchild == NULL)  // 只有右孩子
        return 1 + getForestLeaf(T->rchild);  // 递归
    if (T->lchild == NULL && T->rchild == NULL)  // 叶子结点
        return 1;
    return getForestLeaf(T->lchild) + getForestLeaf(T->rchild);
}

int main() {
    BiTree T;
    Init_Tree(&T);
    Create_Tree(&T);
    PreOrder(T);
    printf("%d", getForestLeaf(T));
    return 0;
}