#include "二叉树.c"


// 借鉴先序遍历,在每次遍历时对节点进行判断,符合条件计数器加1
// 静态变量 cnt防止每次调用的时候被重置为0
int fun(BiTree T) {
    if (T == NULL)
        return 0;
    static int cnt = 0;
    if (T) {
        if (T->data >= 'A' && T->data <= 'Z')
            cnt++;
        fun(T->lchild);
        fun(T->rchild);
    }
    return cnt;
}

// 递归实现
int fun2(BiTree T) {
    if (T == NULL)
        return 0; // 空树返回0
    int count = 0;
    if (T->data >= 'A' && T->data <= 'Z') // 如果是大写字母
        count = 1;
    return count + fun2(T->lchild) + fun2(T->rchild); // 当前节点的值 + 左子树结果 + 右子树结果
}

int main(int argc, char const* argv[]) {
    BiTree T;
    Init_Tree(&T);
    Create_Tree(&T);
    PreOrder(T); printf("\n");
    printf("%d", fun2(T)), printf("\n");
    return 0;
}