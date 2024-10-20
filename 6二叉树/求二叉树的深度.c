#include "二叉树.c"

int maxDeep(BiTree T) {
    if (T == NULL) {
        return 0;
    }
    int leftDeep = maxDeep(T->lchild);
    int rightDeep = maxDeep(T->rchild);
    return (leftDeep > rightDeep ? leftDeep : rightDeep) + 1;
}

int main(int argc, char const* argv[]) {
    BiTree T;
    Init_Tree(&T);
    Create_Tree(&T);
    PreOrder(T);
    printf("%d", maxDeep(T));
    return 0;
}
