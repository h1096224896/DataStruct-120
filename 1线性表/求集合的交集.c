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

// 设有两个集合L1和L2分别存储在两个单链表中，设计求A和B的交集C的程序，集合C也存 储在一个单链表中
LinkList findCommonElements(LinkList L1, LinkList L2) {
    LinkList L3;
    initList(&L3);
    LNode* p = L1->next;
    while (p != NULL) {  // 选择比较算法
        LNode* q = L2->next;
        while (q != NULL) {
            if (p->data == q->data) {
                tailInsert(L3, q->data);  // 尾插法
            }
            q = q->next;
        }
        p = p->next;
    }
    return L3;
}

int main() {
    LinkList L1;
    initList(&L1);
    LinkList L2;
    initList(&L2);
    int arr1[] = { 1,3,5,7,9 };
    int arr2[] = { 3,9 };
    for (int i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++) {
        tailInsert(L1, arr1[i]);
    }
    for (int i = 0; i < sizeof(arr2) / sizeof(arr2[0]); i++) {
        tailInsert(L2, arr2[i]);
    }
    LinkList L3 = findCommonElements(L1, L2);
    showLinkList(L3);
    
    return 0;
}