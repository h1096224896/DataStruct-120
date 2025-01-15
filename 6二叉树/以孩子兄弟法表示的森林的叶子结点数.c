#include "二叉树.c"

// 以孩子兄弟法表示的森林的叶子结点数
// 相当于统计二叉树中,只有右孩子或者叶子结点的结点的个数
// 思路:
//    1.递归结束条件:如果树为空,返回0
//    2.如果只有右孩子,返回1+递归右孩子
//    3.如果是叶子结点,返回1
//    4.递归左右孩子
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