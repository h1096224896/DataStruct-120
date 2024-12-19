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


// 删除单链表中数据域绝对值相等的多余元素 Hash
// 1. 用一个数组记录每个元素是否出现过
// 2. 遍历链表，若未出现过，则标记为出现过
// 3. 若出现过，则删除该元素
// 时间复杂度O(n)
void deleteRedundancy(LinkList L) {
    if (L == NULL) return;
    int appear[1000] = { 0 };  // 用于记录每个元素是否出现过, 0表示未出现过, 1表示出现过
    LNode* pre = L;
    LNode* p = L->next;
    while (p != NULL) {
        if (appear[abs(p->data)] == 0) {  // 未出现过
            appear[abs(p->data)] = 1;
            pre = p;
        }
        else {
            pre->next = p->next;
            free(p);
        }
        p = pre->next;
    }
}
// 删除单链表中数据域绝对值相等的多余元素 双重循环
// 1. 用双重循环遍历链表
// 2. 外层循环遍历每个节点，内层循环检查该节点之后的节点是否有绝对值相等的元素
// 3. 若有，则删除该元素
// 时间复杂度O(n^2)
void deleteRedundancy2(LinkList L) {
    if (L == NULL) return;
    LNode* p = L->next;
    while (p != NULL) {
        LNode* pre = p;
        LNode* q = p->next;
        while (q != NULL) {
            if (abs(q->data) == abs(p->data)) {
                pre->next = q->next;
                free(q);
                q = pre->next;
            } else {
                pre = q;
                q = q->next;
            }
        }
        p = p->next;
    }
}

int main() {
    LinkList L;
    initList(&L);
    tailInsert(L, 1);
    tailInsert(L, -2);
    tailInsert(L, 0);
    tailInsert(L, 3);
    tailInsert(L, 2);
    tailInsert(L, 0);
    tailInsert(L, 1);
    showLinkList(L);
    deleteRedundancy(L);
    showLinkList(L);
    return 0;
}