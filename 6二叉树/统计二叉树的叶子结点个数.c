#include "二叉树.c"

// 统计二叉树中度为且指定值的结点
int countLeafNodesOfValue(BiTree T, char e) {
    if (T == NULL) return 0;
    if (T->lchild == NULL && T->rchild == NULL && T->data == e)
        return 1;
    else
        return countLeafNodesOfValue(T->lchild, e) + countLeafNodesOfValue(T->rchild, e);
}

// 统计叶子结点的个数
int countLeafNodes(BiTree T) {
    if (T == NULL) return 0;
    if (T->lchild == NULL && T->rchild == NULL) return 1;
    return countLeafNodes(T->lchild) + countLeafNodes(T->rchild);
}

int main(int argc, char const* argv[]) {
    BiTree T;
    Init_Tree(&T);
    Create_Tree(&T);
    PreOrder(T); printf("\n");
    printf("%d", countLeafNodes(T)), printf("\n");
    return 0;
}
