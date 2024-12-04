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


// 已知带头结点的单链表H和数组Arr中的元素都是按升序排列，数组Arr中元素个数为n,设计一个算法 将数组Arr中的元素插入到单链表H中，插入元素后的链表仍按升序排列
void insertArrToLinkList(LinkList L, ElemType* Arr, int n) {
    for (int i = 0; i < n; i++) {
        LNode* p = L;  // p指向头结点
        LNode* newNode;  // 新结点
        newNode = (LNode*)malloc(sizeof(LNode));  // 生成新结点
        newNode->data = Arr[i];  // 新结点赋值
        while (p->next != NULL && p->next->data < newNode->data) {  // 找到第一个比q大的结点
            p = p->next; // p指向下一个结点
        }
        newNode->next = p->next; // 新结点的next指向p的next
        p->next = newNode; // p的next指向新结点
    }
}


int main() {
    LinkList L;
    initList(&L);
    tailInsert(L, 1);
    tailInsert(L, 3);
    tailInsert(L, 5);
    tailInsert(L, 7);
    tailInsert(L, 9);
    showLinkList(L);
    //  your function here
    ElemType Arr[] = {3,6,8,2,9};
    insertArrToLinkList(L, Arr, sizeof(Arr) / sizeof(ElemType));
    showLinkList(L);
    return 0;
}

