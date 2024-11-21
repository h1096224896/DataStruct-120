#include "二叉树.c"

// 判断二叉树是否为平衡二叉树(只是让树平衡,没有大小之间的关系)
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