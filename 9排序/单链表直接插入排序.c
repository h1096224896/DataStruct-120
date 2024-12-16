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


// 单链表实现直接插入排序
void fun(LinkList L) {
    if (L == NULL)
        return;
    LNode* p = L->next;
    LNode* q = p->next;
    LNode* pre = L;
    
    while (q != NULL) {
        if (p->data > q->data) {
            p->next = q->next;  // 断开p和q
            while (pre->next->data < q->data) {  // 找到q的插入位置
                pre = pre->next;  // pre指向q的前驱
            }
            q->next = pre->next;  // 插入q
            pre->next = q;  // 插入q
            pre = L;  // pre重新指向头结点
            q = p->next;  // q重新指向p的下一个
        }
        else {
            p = p->next;  // p和q同时后移
            q = q->next;  // p和q同时后移
        }
    }
}

int main() {
    LinkList L;
    initList(&L);
    tailInsert(L, 5);
    tailInsert(L, 4);
    tailInsert(L, 1);
    tailInsert(L, 3);
    tailInsert(L, 7);
    tailInsert(L, 8);
    tailInsert(L, 7);
    tailInsert(L, 2);
    showLinkList(L);
    fun(L);
    showLinkList(L);
    return 0;
}