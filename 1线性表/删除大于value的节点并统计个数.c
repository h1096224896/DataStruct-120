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

// 在一个带头结点的递增单链表中删除所有大于value的节点，并返回删除的节点个数
int fun(LinkList L, int value) {
    int cnt = 0;  // 计数器
    LNode* p = L;
    while (p->next != NULL && p->next->data <= value)  // 找到第一个大于或者等于value的节点, 该节点的前驱节点为p
        p = p->next;
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

// 在一个无序带头结点的单链表中删除所有大于value的节点，并返回删除的节点个数
int fun2(LinkList L, int value) {
    int cnt = 0;  // 计数器
    LNode* p = L;
    while (p->next != NULL) {    // 找到第一个大于或者等于value的节点, 该节点的前驱节点为p
        if (p->next->data > value) {
            LNode* temp = p->next;
            p->next = p->next->next;
            free(temp);
            cnt++;
        }
        else
            p = p->next;
    }
    return cnt;
}


int main() {
    LinkList L;
    initList(&L);
    tailInsert(L, 7);
    tailInsert(L, 3);
    tailInsert(L, 19);
    tailInsert(L, 7);
    tailInsert(L, 20);
    tailInsert(L, 11);
    tailInsert(L, 13);
    showLinkList(L);
    //  your function here
    int cnt = fun2(L, 4);
    printf("%d\n", cnt);
    showLinkList(L);
    return 0;
}

