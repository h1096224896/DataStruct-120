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
    LNode* newNode = (LNode*)malloc(sizeof(LNode));
    newNode->data = data;
    newNode->next = NULL;
    p->next = newNode;
}

// 头插法
void insertHeadNode(LinkList L, int e) {
    LNode* newNode = (LNode*)malloc(sizeof(LNode));
    if (newNode == NULL) return;
    newNode->data = e;
    newNode->next = L->next;
    L->next = newNode;
}

void showLinkList(LinkList L) {
    L = L->next;
    while (L != NULL) {
        printf("%-3d", L->data);
        L = L->next;
    }
    printf("\n");
}



// 计算单链表中所有元素的和
void getMaxAndSecond(LinkList L) {
    int sum = 0;
    LNode* p = L->next; // 假设带头节点
    while (p != NULL) {
        sum += p->data;
        p = p->next;
    }
    printf("-------%d\n", sum);
}



int main() {
    LinkList L;
    initList(&L);
    int n = 0;
    while (1) {
        scanf("%d", &n);
        if (n != -1)
            tailInsert(L, n);
        else
            break;
    }
    // tailInsert(L, 1);
    // tailInsert(L, -2);
    // tailInsert(L, 3);
    // tailInsert(L, -3);
    // tailInsert(L, 3);
    showLinkList(L);
    //  your function here
    getMaxAndSecond(L);
    showLinkList(L);
    return 0;
}