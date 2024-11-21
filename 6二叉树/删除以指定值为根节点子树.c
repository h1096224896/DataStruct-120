#include "二叉树.c"

// 以二叉链表为存储结构，在二叉树中删除以值x为根结点的子树。
void delete(BiTree T, char x) {
    if (T == NULL)
        return;  // 递归结束条件
    if (T->lchild != NULL && T->lchild->data == x)   // 删除左子树
        T->lchild = NULL;
    if (T->rchild != NULL && T->rchild->data == x)  // 删除右子树
        T->rchild = NULL;
    delete(T->lchild, x);  // 递归删除左子树
    delete(T->rchild, x);  // 递归删除右子树
}

int main(int argc, char const* argv[]) {
    BiTree T;
    Init_Tree(&T);
    Create_Tree(&T);
    PreOrder(T); printf("\n");
    delete(T, 'b');
    PreOrder(T); printf("\n");
    return 0;
}