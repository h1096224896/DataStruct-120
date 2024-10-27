#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "二叉树.c"

// 判断二叉树是否为平衡二叉树
int isBalanced(BiTree T) {
    if (T == NULL) {  // 空树是平衡二叉树
        return 1;
    }
    int left = TreeDepth(T->lchild);  // 左子树的深度
    int right = TreeDepth(T->rchild); // 右子树的深度
    if (abs(left - right) <= 1) {
        return isBalanced(T->lchild) && isBalanced(T->rchild);  // 递归判断左右子树
    }
    return 0;
}

// 判断二叉树是否为平衡二叉排序树
int isBalancedBST(BiTree T) {
    if (T == NULL) {  // 空树是平衡二叉排序树
        return 1;
    }
    if (T->lchild != NULL && T->lchild->data > T->data) {
        return 0;  // 左子树的值大于根节点的值
    }
    if (T->rchild != NULL && T->rchild->data < T->data) {
        return 0;  // 右子树的值小于根节点的值
    }
    if (!isBalancedBST(T->lchild) || !isBalancedBST(T->rchild)) {  // 递归判断左右子树
        return 0;
    }
    return 1;
}


int main() {
    BiTree T;
    Init_Tree(&T);
    Create_Tree(&T);
    if (isBalanced(T)) {
        printf("该二叉树是平衡二叉树\n");
    }
    else {
        printf("该二叉树不是平衡二叉树\n");
    }
    return 0;
}