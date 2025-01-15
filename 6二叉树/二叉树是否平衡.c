#include "二叉树.c"


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

// 判断二叉树是否为平衡二叉树(只是让树平衡,没有大小之间的关系)
// 判断左右子树的深度差是否小于等于1
int isBalanced(BiTree T) {
    if (T == NULL) // 空树是平衡二叉树
        return 1;
    int leftDepth = TreeDepth(T->lchild);  // 左子树的深度
    int rightDepth = TreeDepth(T->rchild); // 右子树的深度
    if (abs(leftDepth - rightDepth) > 1)
        return 0;
    return isBalanced(T->lchild) && isBalanced(T->rchild);  // 递归判断左右子树
}


int main(int argc, char const* argv[]) {
    BiTree T;
    Init_Tree(&T);
    Create_Tree(&T);
    PreOrder(T);
    printf("%d", isBalanced(T));
    return 0;
}