#include "二叉树.c"



void printLeaf(BiTree T) {
    if (T == NULL)
        return;
    if (T->lchild == NULL && T->rchild == NULL) {
        printf("%c", T->data);
    }
    printLeaf(T->lchild);
    printLeaf(T->rchild);
}

int main(int argc, char const* argv[]) {
    BiTree T;
    Init_Tree(&T);
    Create_Tree(&T);
    PreOrder(T); printf("\n");
    printLeaf(T);
    return 0;
}