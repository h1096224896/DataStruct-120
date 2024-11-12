#include "二叉树.c"

int countLeaf(BiTree T, int e) {
    if (T == NULL) return 0;
    if (T->lchild == NULL && T->rchild == NULL && T->data == e) return 1;
    else
        return countLeaf(T->lchild, e) + countLeaf(T->rchild, e);
}

int main(int argc, char const* argv[]) {
    BiTree T;
    Init_Tree(&T);
    Create_Tree(&T);
    PreOrder(T); printf("\n");
    printf("%d", countLeaf(T, 'b'));
    return 0;
}