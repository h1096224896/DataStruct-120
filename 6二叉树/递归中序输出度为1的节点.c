#include "二叉树.c"


void fun(BiTree T) {
    if (T) {
        fun(T->lchild);
        printf("%-3c", T->data);
        fun(T->rchild);
    }
}

void fun2(BiTree T) {
    if (T) {
        fun2(T->lchild);
        if ((T->lchild == NULL && T->rchild != NULL) || (T->lchild != NULL && T->rchild == NULL)) {
            printf("%-3c", T->data);
        }
        fun2(T->rchild);
    }
}




int main(int argc, char const* argv[]) {
    BiTree T;
    Init_Tree(&T);
    Create_Tree(&T);
    fun2(T); printf("\n");
    return 0;
}