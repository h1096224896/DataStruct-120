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

int fun(LinkList L, int value) {
    LNode* p = L;
    while (p->next != NULL && p->next->data < value)  // 找到第一个大于value的节点
        p = p->next;
    int cnt = 0;  // 计数器
    LNode* pre = p;
    p = p->next;
    while (p != NULL) {
        LNode* temp = p;
        pre->next = p->next;
        p = p->next;
        free(temp);
        cnt++;
    }
    return cnt;
}

int main() {
    LinkList L;
    initList(&L);
    tailInsert(L, 1);
    tailInsert(L, 3);
    tailInsert(L, 5);
    tailInsert(L, 7);
    tailInsert(L, 9);
    tailInsert(L, 11);
    tailInsert(L, 13);
    showLinkList(L);
    //  your function here
    int cnt = fun(L, 12);
    printf("%d", cnt);
    // showLinkList(L);
    return 0;
}

