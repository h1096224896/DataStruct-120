#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 1.定义二叉树结构
typedef struct BiTNode {
    char data;               //数据
    struct BiTNode* lchild;  //左孩子
    struct BiTNode* rchild;  //右孩子
}BiTNode, * BiTree;

// 2.初始化二叉树
void Init_Tree(BiTree* T) {
    *T = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->data = '#';
    (*T)->lchild = NULL;
    (*T)->rchild = NULL;
}

// 3.销毁二叉树
void Destroy_Tree(BiTree* T) {
    if (*T) {
        Destroy_Tree(&(*T)->lchild);
        Destroy_Tree(&(*T)->rchild);
        free(*T);
    }
}

// 4.创建二叉树(先序)
void Create_Tree(BiTree* T) {
    char c;
    scanf("%c", &c);
    getchar();  // 吸收回车
    if (c == '#') {
        *T = NULL;
    }
    else {
        *T = (BiTNode*)malloc(sizeof(BiTNode));
        (*T)->data = c;
        Create_Tree(&(*T)->lchild);
        Create_Tree(&(*T)->rchild);
    }
}

// 5.先序遍历
void PreOrder(BiTree T) {
    // static int firstCall = 1;
    // if (firstCall) {
    //     printf("先序遍历:");
    //     firstCall = 0;
    // }
    if (T) {
        printf("%c ", T->data);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

// 6.中序遍历
void InOrder(BiTree T) {
    if (T) {
        InOrder(T->lchild);
        printf("%c ", T->data);
        InOrder(T->rchild);
    }
}

// 7.后序遍历
void PostOrder(BiTree T) {
    if (T) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        printf("%c ", T->data);
    }
}


// 8.求二叉树的深度
int TreeDepth(BiTree T) {
    if (T == NULL) {
        return 0;
    }
    int left = TreeDepth(T->lchild);
    int right = TreeDepth(T->rchild);
    return left > right ? left + 1 : right + 1;
}


// 9.插入节点
void InsertNode(BiTree* T, char x) {
    if (*T == NULL) {
        *T = (BiTNode*)malloc(sizeof(BiTNode));
        (*T)->data = x;
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;
    }
    else {
        if (x < (*T)->data) {
            InsertNode(&(*T)->lchild, x);
        }
        else if (x > (*T)->data) {
            InsertNode(&(*T)->rchild, x);
        }
    }
}