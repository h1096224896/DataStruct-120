#include "二叉树.c"


void fun(BiTree T) {
    if (T) {
        fun(T->lchild);
        if ((T->lchild == NULL) != (T->rchild == NULL))  // 只有一个孩子
            printf("%d ", T->data);
        fun(T->rchild);
    }
}

int main() {
    BiTree T = NULL;
    int a[] = { 20,15,10,25 };
    int len = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < len; i++)
        InsertNode(&T, a[i]);
    fun(T);
    return 0;
}