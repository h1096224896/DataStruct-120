#include "二叉树.c"


// 统计二叉树的非叶子节点个数
int countNotLeafNodes(BiTree T) {
    if (T == NULL)
        return 0;
    if (T->lchild == NULL && T->rchild == NULL)  // 是叶子结点
        return 0;                          // 非叶子结点个数不加1
    // 如果当前节点是非叶子节点，返回 1 加上左右子树中非叶子节点的个数。
    return 1 + countNotLeafNodes(T->lchild) + countNotLeafNodes(T->rchild);
}

// 统计叶子结点的个数
int countLeafNodes(BiTree T) {
    if (T == NULL)
        return 0;
    if (T->lchild == NULL && T->rchild == NULL)  // 是叶子结点
        return 1;                               // 叶子结点个数加1
    // 如果当前节点不是叶子节点，返回左右子树中叶子节点的个数之和。
    return countLeafNodes(T->lchild) + countLeafNodes(T->rchild);
}

int main(int argc, char const* argv[]) {
    BiTree T;
    Init_Tree(&T);
    Create_Tree(&T);
    PreOrder(T); printf("\n");
    printf("%d", countLeafNodes(T)), printf("\n");
    printf("%d", countNotLeafNodes(T)), printf("\n");
    return 0;
}