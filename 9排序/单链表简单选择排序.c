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


void LinkListSort(LinkList L) {
    if (L == NULL) return;
    LNode* p = L->next;
    while (p->next != NULL) {
        LNode* q = p->next;
        while (q != NULL) {
            if (p->data > q->data) {
                int temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
            q = q->next;
        }
        p = p->next;
    }
}

void fun(LinkList L) {
    if (L == NULL)
        return;
    LNode* p = L->next;
    while (p->next != NULL) {
        LNode* q = p->next;
        while (q != NULL) {
            if (p->data > q->data) {
                int temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
            q = q->next;
        }
        p = p->next;
    }
}


int main() {
    LinkList L;
    initList(&L);
    tailInsert(L, 5);
    tailInsert(L, 4);
    tailInsert(L, 1);
    tailInsert(L, 3);
    tailInsert(L, 7);
    tailInsert(L, 8);
    tailInsert(L, 7);
    tailInsert(L, 2);
    showLinkList(L);
    fun(L);
    showLinkList(L);
    return 0;
}