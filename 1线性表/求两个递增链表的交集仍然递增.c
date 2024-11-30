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

LinkList intersection(LinkList A, LinkList B) {
    LinkList C;
    initList(&C);
    LNode* p = A->next;
    LNode* q = B->next;
    LNode* r = C;
    while (p != NULL && q != NULL) {
        if (p->data == q->data) {
            r->next = p;
            r = r->next;
            p = p->next;
            q = q->next;
        }
        else if (p->data < q->data) {
            p = p->next;
        }
        else
            q = q->next;
    }
    r->next = NULL;  // 尾节点指向NULL
    return C;
}


int main() {
    LinkList A, B;
    initList(&A);
    initList(&B);
    tailInsert(A, 1);
    tailInsert(A, 2);
    tailInsert(A, 3);
    tailInsert(A, 4);
    tailInsert(A, 5);
    tailInsert(B, 3);
    tailInsert(B, 4);
    tailInsert(B, 5);
    tailInsert(B, 6);
    tailInsert(B, 7);
    showLinkList(A);
    showLinkList(B);
    LinkList C = intersection(A, B);
    showLinkList(C);
    return 0;
}