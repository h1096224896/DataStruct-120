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

// 使用快慢指针查找倒数第k个元素
// 1. 快指针先走k步
// 2. 快慢指针同时走，当快指针走到链表尾部时，慢指针指向的就是倒数第k个元素
int searchElemOfIndex(LinkList L, ElemType k) {
    if (L == NULL) return 0;  // 空链表
    LNode* slow = L;
    LNode* fast = L;
    for (int i = 0; i < k; i++) {  // 快指针先走k步
        fast = fast->next;
        if (fast == NULL) {
            printf("k值超出链表长度\n");
            return 0;
        }
    }
    while (fast != NULL) {  // 快慢指针同时走
        fast = fast->next;
        slow = slow->next;
    }
    printf("%d\n", slow->data);
    return 1;
}

int main() {
    LinkList L;
    initList(&L);
    tailInsert(L, 1);
    tailInsert(L, 2);
    tailInsert(L, 3);
    tailInsert(L, 4);
    tailInsert(L, 5);
    searchElemOfIndex(L, 4);
    return 0;
}