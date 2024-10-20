#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct LNode {
    int data;
    struct LNode* next;
} LNode, * LinkList;

typedef struct DNode {
    int data;
    struct DNode* prior, * next;
} DNode, * DLinkList;

// 初始化一个循环单链表
int InitLinkList(LinkList* L) {
    *L = (LNode*)malloc(sizeof(LNode));
    if (*L == NULL) {
        return -1;
    }
    (*L)->next = *L;  // 循环单链表的头结点指向自己
    return 0;
}

// 初始化一个循环双链表
int InitDLinkList(DLinkList* L) {
    *L = (DNode*)malloc(sizeof(DNode));
    if (*L == NULL) {
        return -1;
    }
    (*L)->prior = *L;
    (*L)->next = *L;
    return 0;
}

// 判断循环单链表是否为空
int Empty(LinkList L) {
    if (L->next == L) {  // 循环单链表的头结点指向自己
        return 1;
    }
    return 0;
}

// 判断循环双链表是否为空
int EmptyD(DLinkList L) {
    if (L->next == L) {  // 循环双链表的头结点的后继结点指向自己
        return 1;
    }
    return 0;
}

// 删除p结点的后继结点q
int DeleteNextNode(LNode* p, LNode* q) {
    if (p == NULL || q == NULL) {
        return -1;
    }
    if (q == p) {  // 如果q指向头结点
        return -1;
    }
    LNode* temp = p->next;  // temp指向p的后继结点
    if (temp == NULL) {
        return -1;
    }
    p->next = temp->next;  // 将temp的后继结点赋值给p的后继结点
    free(temp);
    return 0;
}



int main()
{
    
    return 0;
}