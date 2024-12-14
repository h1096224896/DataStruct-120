#include "二叉树.c"


int maxDeep(BiTree T) {
    if (T == NULL)
        return 0;
    int leftDeep = maxDeep(T->lchild);  // 左子树的深度
    int rightDeep = maxDeep(T->rchild);  // 右子树的深度
    if (leftDeep >= rightDeep)  // 返回左子树和右子树中较大的深度
        return leftDeep + 1;
    else
        return rightDeep + 1;
}


int fun(BiTree T) {
    if (T == NULL)
        return 0;
    int leftDeep = fun(T->lchild);
    int rightDeep = fun(T->rchild);
    if (leftDeep >= rightDeep)
        return 1 + leftDeep;
    else
        return 1 + rightDeep;
}


int main(int argc, char const* argv[]) {
    BiTree T;
    Init_Tree(&T);
    Create_Tree(&T);
    PreOrder(T);
    printf("%d", fun(T));
    return 0;
}
