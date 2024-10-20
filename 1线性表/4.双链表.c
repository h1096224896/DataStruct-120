#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct DNode {
    int data;
    struct DNode* prior, * next;
} DNode, * DLinkList;

// 初始化双链表
int InitDLinkList(DLinkList* L) {
    *L = (DNode*)malloc(sizeof(DNode));
    if (*L == NULL) {
        return -1;
    }
    (*L)->prior = NULL;
    (*L)->next = NULL;
    return 0;
}

// 判断双链表是否为空
int Empty(DLinkList L) {
    if (L->next == NULL) {
        return 1;
    }
    return 0;
}

// 在p结点之后插入s结点
int InsertNextDNode(DNode* p, DNode* s) {
    if (p == NULL || s == NULL) {
        return -1;
    }
    s->next = p->next;  // 将p结点的后继结点赋值给s结点的后继结点
    if (p->next != NULL) {  // 如果p结点有后继结点
        p->next->prior = s;  // 将p结点的后继结点的前驱结点指向s
    }
    s->prior = p;
    p->next = s;
    return 0;
}

// 删除p结点的后继结点
int DeleteNextDNode(DNode* p) {
    if (p == NULL) {
        return -1;
    }
    DNode* q = p->next;  // q指向p的后继结点
    if (q == NULL) {
        return 0;
    }
    p->next = q->next;  // 将q的后继结点赋值给p的后继结点
    if (q->next != NULL) {  // 如果q有后继结点
        q->next->prior = p;  // 将q的后继结点的前驱结点指向p
    }
    free(q);
    return 0;
}

// 销毁双链表
int DestroyList(DLinkList* L) {
    if (*L == NULL) {
        return -1;
    }
    DNode* p = (*L)->next;
    DNode* q;
    while (p != NULL) {
        q = p->next;
        free(p);
        p = q;
    }
    free(*L);
    *L = NULL;
    return 0;
}

// 后向遍历双链表
int Backward_traverse(DLinkList L) {
    if (L == NULL) {
        return -1;
    }
    DNode* p = L;
    while (p->next != NULL) {
        p = p->next;
    }
    while (p != L) {
        printf("%d ", p->data);
        p = p->prior;
    }
    printf("\n");
    return 0;
}

// 前向遍历双链表
int Forward_traverse(DLinkList L) {
    if (L == NULL) {
        return -1;
    }
    DNode* p = L->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    return 0;
}

int main() {

    return 0;
}