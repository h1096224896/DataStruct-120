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
    while (p->next != NULL && p->next->data < x) {  // 找到第一个比x大的节点
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
    fun(L, 7);
    fun(L, 1);
    fun(L, 9);
    fun(L, 3);
    fun(L, 5);

    showLinkList(L);
    //  your function here

    showLinkList(L);
    return 0;
}