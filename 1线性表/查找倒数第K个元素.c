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

int searchElemOfIndex(LinkList L, ElemType k) {
    if (L == NULL) return 0;
    LNode* slow = L;
    LNode* fast = L;
    for (int i = 0; i < k; i++) {
        fast = fast->next;
        if (fast == NULL) {
            printf("k值超出链表长度\n");
            return 0;
        }
    }
    while (fast != NULL) {
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
    searchElemOfIndex(L, 1);
    return 0;
}