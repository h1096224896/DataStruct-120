#include "二叉树.c"

int maxDeep(BiTree T) {
    if (T == NULL)
        return 0;
    else {
        int leftDeep = maxDeep(T->lchild);  // 左子树的深度
        int rightDeep = maxDeep(T->rchild);  // 右子树的深度
        if (leftDeep >= rightDeep)  // 返回左子树和右子树中较大的深度
            return leftDeep + 1; 
        else
            return rightDeep + 1;
    }
}

int main(int argc, char const* argv[]) {
    BiTree T;
    Init_Tree(&T);
    Create_Tree(&T);
    PreOrder(T);
    printf("%d", maxDeep(T));
    return 0;
}
