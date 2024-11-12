#include "二叉树.c"


int countNode(BiTree T) {
    if (T == NULL)   // 递归结束条件
        return 0;
    else
        return countNode(T->lchild) + countNode(T->rchild) + 1;  // 递归调用
}

int main(int argc, char const* argv[]) {
    BiTree T;
    Init_Tree(&T);
    Create_Tree(&T);
    PreOrder(T); printf("\n");
    printf("%d", countNode(T)), printf("\n");
    return 0;
}