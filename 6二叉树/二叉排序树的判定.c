#include "二叉树.c"

// 10.判断是否是二叉排序树
int JudgeBST(BiTree T) {
    if (T == NULL)  // 当判断到空节点时，返回1
        return 1;
    if (T->lchild != NULL && T->lchild->data > T->data)  
        return 0;  // 左子树的值大于根节点的值,不是二叉排序树
    if (T->rchild != NULL && T->rchild->data < T->data)
        return 0;  // 右子树的值小于根节点的值,不是二叉排序树
    return JudgeBST(T->lchild) && JudgeBST(T->rchild);  // 递归判断左右子树
}

int main() {
    BiTree T = NULL;
    Init_Tree(&T);
    Create_Tree(&T);
    // 先序遍历
    PreOrder(T);
    printf("\n");
    printf("%d\n", JudgeBST(T));
    return 0;
}