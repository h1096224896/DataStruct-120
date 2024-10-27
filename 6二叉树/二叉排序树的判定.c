#include "二叉树.c"

// 二叉排序树的判定
int JudgeBST(BiTree T) {
    if (T == NULL)
        return 1;
    if (T->lchild != NULL && T->lchild->data > T->data)
        return 0;  // 左子树的值大于根节点的值
    if (T->rchild != NULL && T->rchild->data < T->data)
        return 0;  // 右子树的值小于根节点的值
    if (!JudgeBST(T->lchild) || !JudgeBST(T->rchild))  // 递归判断左右子树
        return 0;
    return 1;
}


int main()
{
    BiTree T = NULL;
    Init_Tree(&T);
    Create_Tree(&T);
    // 先序遍历
    PreOrder(T);
    printf("\n");
    printf("%d\n", JudgeBST(T));
    return 0;
}