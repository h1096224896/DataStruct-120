#include "二叉树.c"

// 交换左右子树
void swapSubTree(BiTree T) {
    if (T) {
        BiTNode* temp = T->lchild;
        T->lchild = T->rchild;
        T->rchild = temp;
        swapSubTree(T->lchild);
        swapSubTree(T->rchild);
    }
}

int main(int argc, char const *argv[])
{
    BiTree T;
    Init_Tree(&T);
    Create_Tree(&T);
    PreOrder(T); printf("\n");
    swapSubTree(T);
    PreOrder(T);
    Destroy_Tree(&T);
    return 0;
}
