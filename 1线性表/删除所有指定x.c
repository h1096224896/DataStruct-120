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

int fun(LinkList L, int e) {
    if (L == NULL)
        return 0;
    LNode* p = L->next;
    LNode* pre = L;
    int cnt = 0;
    while (p != NULL) {
        if (p->data == e) {
            pre->next = p->next;
            free(p);
            p = pre->next;
            cnt++;
            // LNode* tmp = p;
            // pre->next = p->next;
            // p = p->next;
            // free(tmp);
            // cnt++;
        }
        else {
            pre = p;
            p = p->next;
        }
    }
    return cnt;
}


int main() {
    LinkList L;
    initList(&L);
    tailInsert(L, 1);
    tailInsert(L, -2);
    tailInsert(L, 3);
    tailInsert(L, -3);
    tailInsert(L, 3);
    tailInsert(L, 4);
    showLinkList(L);
    //  your function here
    printf("%d\n", fun(L, 4));
    showLinkList(L);
    return 0;
}