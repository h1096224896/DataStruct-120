#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct DuLNode {
    ElemType data;
    struct DuLNode* prior;
    struct DuLNode* next;
} DuLNode, * DuLinkList;

// 初始化双向链表
void InitDuLinkList(DuLinkList* L) {
    *L = (DuLNode*)malloc(sizeof(DuLNode));
    (*L)->prior = NULL;
    (*L)->next = NULL;
}

// 尾插法创建双向链表
void CreateDuLinkListR(DuLinkList L, int n) {
    DuLNode* p;
    DuLNode* r = L;  // r始终指向尾结点
    for (int i = 0; i < n; i++) {
        p = (DuLNode*)malloc(sizeof(DuLNode));
        p->data = 'A' + i;
        p->prior = r;
        r->next = p;
        r = p;
    }
    r->next = NULL;
}

// 打印双向链表
void PrintDuLinkList(DuLinkList L) {
    DuLNode* p = L->next;
    while (p != NULL) {
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 删除双向链表中的第k个元素
void DeleteKthNode(DuLinkList L, int k) {
    // 检查链表是否为空或k值是否有效
    if (L == NULL || L->next == NULL || k < 1) {
        printf("链表为空或k值无效\n");
        return;
    }
    // 当前节点指针，初始指向头结点
    DuLNode* p = L->next;
    int count = 1;  // 记录当前节点的位置，初始为第1个节点
    // 找到第k个节点
    while (p != NULL && count < k) {
        p = p->next;
        count++;
    }
    // 如果没有找到第k个节点（k大于链表的长度）
    if (p == NULL) {
        printf("链表中没有第%d个节点\n", k);
        return;
    }
    // 删除第k个节点
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
}

int main() {
    // 创建一个带头结点的双向链表L，并添加一些元素...
    DuLinkList L;
    InitDuLinkList(&L);
    CreateDuLinkListR(L, 5);
    CreateDuLinkListR(L, 6);
    CreateDuLinkListR(L, 7);
    CreateDuLinkListR(L, 8);
    CreateDuLinkListR(L, 9);
    PrintDuLinkList(L);
    DeleteKthNode(L, 3);
    PrintDuLinkList(L);
    return 0;
}