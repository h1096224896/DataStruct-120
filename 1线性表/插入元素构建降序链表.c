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


void insertDescending(LinkList L, int data) {
    LNode* p = L;
    while (p->next != NULL && p->next->data > data) {
        p = p->next;
    }
    LNode* newNode = (LNode*)malloc(sizeof(LNode));
    newNode->data = data;
    newNode->next = p->next;
    p->next = newNode;
}




int main() {
    LinkList L;
    initList(&L);
    insertDescending(L, 10);
    insertDescending(L, 1);
    insertDescending(L, -2);
    insertDescending(L, 3);
    insertDescending(L, -3);
    insertDescending(L, 3);
    insertDescending(L, 0);
    insertDescending(L, 2);
    insertDescending(L, 20);
    insertDescending(L, 2);
    showLinkList(L);
    return 0;
}