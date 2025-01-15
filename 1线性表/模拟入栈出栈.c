#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode* next;
}LNode, * LinkList;

// 初始化一个带头结点的链表
void initList(LinkList* L) {
    *L = (LNode*)malloc(sizeof(LNode));
    (*L)->next = NULL;
}

// 尾插法
void tailInsert(LinkList L, ElemType data) {
    LNode* p = L;
    while (p->next != NULL) {
        p = p->next;
    }
    LNode* node = (LNode*)malloc(sizeof(LNode));
    node->data = data;
    node->next = NULL;
    p->next = node;
}

void showLinkList(LinkList L) {
    L = L->next;
    while (L != NULL) {
        printf("%-3d", L->data);
        L = L->next;
    }
    printf("\n");
}

// 入栈相当于尾插
void Push(LinkList S, int x) {
    LNode* p = S;
    while (p->next != NULL)
        p = p->next;
    LNode* newNode = (LNode*)malloc(sizeof(LNode));
    newNode->data = x;
    newNode->next = p->next;
    p->next = newNode;
}

// 出栈相当于删除最后一个元素
void Pop(LinkList S, int* x) {
    LNode* p = S->next;
    LNode* pre = S;
    if (p == NULL) {
        printf("栈已经为空。\n");
        return;
    }
    while (p->next != NULL) {
        pre = p;
        p = p->next;
    }
    *x = p->data;
    pre->next = NULL;
    free(p);
}

int main() {
    LinkList L;
    initList(&L);
    tailInsert(L, 1);
    tailInsert(L, -2);
    tailInsert(L, 3);
    tailInsert(L, -3);
    tailInsert(L, 3);
    showLinkList(L);
    //  your function here

    showLinkList(L);
    return 0;
}

