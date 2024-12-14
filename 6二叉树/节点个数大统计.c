#include "二叉树.c"


// 已知一个二叉树T采用二叉链表方式存储，设计一个算法，统计出二叉树T中结点的个数、叶子结点个数、 单枝结点的个数和双枝结点的个数，并将计算的结果存放在数组中。
// 统计二叉树的结点类型数量
void countNodes(BiTree root, int* counts) {
    if (root == NULL)
        return;
    counts[0]++;  // 只要是根结点就加一
    if (root->lchild == NULL && root->rchild == NULL) {
        // 叶子结点
        counts[1]++;
    } else if (root->lchild == NULL || root->rchild == NULL) {
        // 单枝结点
        counts[2]++;
    } else
        // 双枝结点
        counts[3]++;
    // 递归统计左右子树
    countNodes(root->lchild, counts);
    countNodes(root->rchild, counts);
}


void fun(BiTree T, int* arr) {
    if (T == NULL)
        return;
    arr[0]++;
    if (T->lchild == NULL && T->rchild == NULL)
        arr[1]++;
    else if (T->lchild == NULL || T->rchild == NULL)
        arr[2]++;
    else
        arr[3]++;
    fun(T->lchild, arr);
    fun(T->rchild, arr);
}

int main(int argc, char const* argv[]) {
    BiTree T;
    Init_Tree(&T);
    Create_Tree(&T);
    PreOrder(T); printf("\n");
    InOrder(T); printf("\n");
    PostOrder(T); printf("\n");
    int arr[4] = { 0 };
    fun(T, arr);
    printf("Node: %d\n", arr[0]);
    printf("Leaf: %d\n", arr[1]);
    printf("One: %d\n", arr[2]);
    printf("Two: %d\n", arr[3]);
    return 0;
}