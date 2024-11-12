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

// 已知单链表中各结点的元素值为整型且递增有序，设计一个函数删除链表中所有大于mink 且小于 maxk 的元素，并释放被删结点的存储空间。链表头指针和 mink、maxk 值作为参数传入
void delete(LinkList L, int min, int max) {
    LNode* p = L->next;
    LNode* pre = L;
    while (p != NULL) {
        if (p->data > min && p->data < max) {
            LNode* temp = p;
            p = p->next;
            pre->next = p;
            free(temp);
        }
        else {
            pre = p;
            p = p->next;
        }
    }
}

int main() {
    LinkList L;
    initList(&L);
    tailInsert(L, 1);
    tailInsert(L, 2);
    tailInsert(L, 3);
    tailInsert(L, 4);
    tailInsert(L, 5);
    tailInsert(L, 6);
    tailInsert(L, 7);
    showLinkList(L);
    delete(L, 2, 5);
    showLinkList(L);
    return 0;
}