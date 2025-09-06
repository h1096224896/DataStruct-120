#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct BiTNode {
    int data;
    struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

void Create_Tree(BiTree* T) {
    int x;
    scanf("%d", &x);
    if (x == 0) {
        *T = NULL;
    }
    else {
        *T = (BiTree)malloc(sizeof(BiTNode));
        (*T)->data = x;
        Create_Tree(&(*T)->lchild);
        Create_Tree(&(*T)->rchild);
    }
}


// 二叉排序树的判定
int JudgeBST(BiTree T) {
    if (T == NULL) return 1;  // 空树是二叉排序树
    if (T->lchild != NULL && T->lchild->data > T->data) return 0;  // 左子树不为空且左子树的值小于根结点的值
    if (T->rchild != NULL && T->rchild->data < T->data) return 0;  // 右子树不为空且右子树的值大于根结点的值
    if (!JudgeBST(T->lchild) || !JudgeBST(T->rchild)) return 0;    // 递归判断左右子树
    return 1;
}

int main() {
    BiTree T = NULL;
    Create_Tree(&T);
    if (JudgeBST(T)) {
        printf("是二叉排序树\n");
    } else {
        printf("不是二叉排序树\n");
    }
    return 0;
}