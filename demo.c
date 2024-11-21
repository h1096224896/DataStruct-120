#include <stdio.h>
#include <stdlib.h>

typedef struct QNode {
    int data;
    struct QNode* lchild, * rchild;
} BiTree;

// 辅助函数：计算二叉树深度并同时判断是否为平衡二叉树
int isAVLHelper(BiTree* T, int* depth) {
    if (T == NULL) {
        *depth = 0; // 空树深度为0
        return 1;   // 空树是平衡二叉树
    }
    int leftDepth = 0, rightDepth = 0;
    // 判断左子树是否是AVL树
    if (!isAVLHelper(T->lchild, &leftDepth))
        return 0;
    // 判断右子树是否是AVL树
    if (!isAVLHelper(T->rchild, &rightDepth))
        return 0;
    // 检查是否满足平衡条件
    if (abs(leftDepth - rightDepth) > 1)
        return 0;
    // 更新当前树的深度
    *depth = (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    // 检查二叉排序树的条件
    if ((T->lchild && T->lchild->data > T->data) ||
        (T->rchild && T->rchild->data < T->data))
        return 0;
    return 1; // 满足AVL条件
}

// 主函数
int isAVL(BiTree* T) {
    int depth = 0;
    return isAVLHelper(T, &depth);
}