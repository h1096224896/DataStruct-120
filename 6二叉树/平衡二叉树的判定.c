#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "二叉树.c"


// 8.求二叉树的深度
// int TreeDepth(BiTree T) {
//     if (T == NULL)
//         return 0;
//     int left = TreeDepth(T->lchild);
//     int right = TreeDepth(T->rchild);
//     if (left > right)
//         return left + 1;
//     else
//         return right + 1;
// }

// 判断二叉树是否为平衡二叉排序树(AVL树)
int isAVL(BiTree T) {
    if (T == NULL)  // 空树是平衡二叉树
        return 1;
    if (T->lchild != NULL && T->lchild->data > T->data)  // 左子树的值大于根节点的值
        return 0;
    if (T->rchild != NULL && T->rchild->data < T->data)  // 右子树的值小于根节点的值
        return 0;
    if (abs(TreeDepth(T->lchild) - TreeDepth(T->rchild)) > 1) {  // 左右子树的深度差大于1
        return 0;
    }
    return isAVL(T->lchild) && isAVL(T->rchild);  // 递归判断左右子树
}


int main() {
    BiTree T;
    Init_Tree(&T);
    Create_Tree(&T);
    if (isAVL(T)) {
        printf("该二叉树是平衡二叉树\n");
    }
    else {
        printf("该二叉树不是平衡二叉树\n");
    }
    return 0;
}