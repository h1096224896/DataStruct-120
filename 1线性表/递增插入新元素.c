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

void fun(LinkList L, int x) {
    LNode* p = L;
    while (p->next != NULL && p->next->data < x) {
        p = p->next;
    }
    LNode* newNode = (LNode*)malloc(sizeof(LNode));
    newNode->data = x;
    newNode->next = p->next;
    p->next = newNode;
}


int main() {
    LinkList L;
    initList(&L);
    tailInsert(L, 1);
    tailInsert(L, 3);
    tailInsert(L, 5);
    tailInsert(L, 7);
    tailInsert(L, 9);
    showLinkList(L);
    //  your function here

    showLinkList(L);
    return 0;
}