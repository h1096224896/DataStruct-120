#include "二叉树.c"

// 交换所有左右子树
void Swap(BiTree T) {
    if (T) {
        BiTNode* temp = T->lchild;
        T->lchild = T->rchild;
        T->rchild = temp;
        Swap(T->lchild);
        Swap(T->rchild);
    }
}


// int main(int argc, char const *argv[])
// {
//     BiTree T;
//     Init_Tree(&T);
//     Create_Tree(&T);
//     PreOrder(T); printf("\n");
//     Swap(T);
//     PreOrder(T);
//     Destroy_Tree(&T);
//     return 0;
// }
