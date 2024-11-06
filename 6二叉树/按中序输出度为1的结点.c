#include "二叉树.c"

void InOrderTraverse(BiTree T) {
    if (T == NULL)
        return;
    InOrderTraverse(T->lchild); // 左
    if (T->lchild == NULL && T->rchild != NULL || T->rchild == NULL && T->lchild != NULL)
        printf("%c ", T->data);  // 根
    InOrderTraverse(T->rchild);  // 右
}

int main(int argc, char const* argv[]) {
    BiTree T;
    Init_Tree(&T);
    Create_Tree(&T);
    InOrderTraverse(T);
    return 0;
}