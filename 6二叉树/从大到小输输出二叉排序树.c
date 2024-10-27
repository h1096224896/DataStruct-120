#include "二叉树.c"

// 从大到小输出二叉排序树(先访问右子树 再访问根节点 再访问左子树)
void InOrderTraverse(BiTree T, int num) {
    if (T) {
        InOrderTraverse(T->rchild, num);  // 先访问右子树
        if (T->data >= num )  
            printf("%d ", T->data);  // 访问根节点
        InOrderTraverse(T->lchild, num);  // 再访问左子树
    }
}

int main() {
    BiTree T = NULL;
    int a[] = { 62, 88, 58, 47, 35, 73, 51, 99, 37, 93 };
    for (int i = 0; i < 10; i++) {
        InsertNode(&T, a[i]);
    }
    InOrderTraverse(T, 50);
    return 0;
}