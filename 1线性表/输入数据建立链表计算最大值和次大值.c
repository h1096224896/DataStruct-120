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



// 输出最大值和次大值
void getMaxAndSecond(LinkList L) {
    int max = L->next->data;  //  
    int second = L->next->data; // 将最大值和次大值先设置为第一个元素
    LNode* p = L->next;
    while (p != NULL) {  // 选择比较找最大值
        if (p->data > max)
            max = p->data;  // 更新最大值
        p = p->next;
    }
    LNode* q = L->next;   // 重新遍历
    while (q != NULL) {   // 选择比较找次大值
        if (q->data > second && q->data < max)
            second = q->data;
        q = q->next;
    }
    printf("max:%d, second:%d", max, second);
}


int main() {
    LinkList L;
    initList(&L);
    for (int i = 1; i <= 10; i++) {
        printf("请输入第%d个数:", i);
        int n;
        scanf("%d", &n);
        tailInsert(L, n);
    }
    showLinkList(L);
    //  your function here
    getMaxAndSecond(L);
    return 0;
}