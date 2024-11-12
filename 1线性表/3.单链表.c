#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct LNode {
    int data;
    struct LNode* next;
}*LinkList, LNode;  // 前面是指针型


// 删除所有值为 X 的结点
void deleteAllX(LinkList L, int x) {
    LNode* pre = L;  // pre指向当前结点的前驱结点
    LNode* p = L->next;  // p指向当前结点
    while (p != NULL) {
        if (p->data == x) {
            pre->next = p->next;
            free(p);
            p = pre->next;
        }
        else {
            pre = p;
            p = p->next;
        }
    }
}


// 初始化一个带头结点的单链表
int initList(LinkList* head) {
    *head = (LNode*)malloc(sizeof(LNode));
    if (*head == NULL) {
        return 0;
    }
    (*head)->data = 0;
    (*head)->next = NULL;
    return 1;
}

// 指定位置插入
int listInsert(LinkList L, int i, int e) {
    if (i < 1) return 0;
    LNode* p;  // 指针p指向当前扫描到的结点
    int j = 0; // 当前是第几个结点
    p = L;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL) {
        return 0;
    }
    LNode* s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return 1;
}

// 按位删除
int listDelete(LinkList L, int i, int* e) {
    if (i < 1)
        return 0;
    LNode* p = L;
    int j = 0;
    // 遍历到第 (i-1) 个节点
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL || p->next == NULL)
        return 0; // 如果位置超出范围，则返回失败
    LNode* q = p->next;
    *e = q->data; // 存储要删除的节点的数据
    p->data = q->data;
    p->next = q->next;
    free(q);
    return 1;
}

// 删除指定P结点
int deleteNode(LNode* p) {
    if (p == NULL)
        return 0;
    LNode* q = p->next;
    p->data = q->data;
    p->next = q->next;
    free(q);
    return 1;
}

// 按位查找
LNode* getElem(LinkList L, int i) {
    if (i < 1) exit(1);
    LNode* p = L;
    int j = 0;
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

// 按值查找
LNode* LocateElem(LinkList L, int e) {
    if (L == NULL) exit(1);
    LNode* p = L->next;
    while (p->data != e && p != NULL) {
        p = p->next;
    }
    return p;
}

// 求单链表的长度
int getListLength(LinkList L) {
    int length = 0;
    LNode* p = L;
    while (L != NULL) {
        p = p->next;
        length++;
    }
    return length;
}

// 在p结点之后插入元素e
int insertNextNode(LNode* p, int e) {
    if (p == NULL) return 0;
    LNode* s = (LNode*)malloc(sizeof(LNode));
    if (s == NULL) return 0;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return 1;
}

// 尾插法
void insertTailNode(LinkList L, int e) {
    if (L == NULL) return;
    LNode* p = L;
    while (p->next != NULL) {
        p = p->next;
    }
    LNode* s = (LNode*)malloc(sizeof(LNode));
    if (s == NULL) return;
    s->data = e;
    s->next = NULL;
    p->next = s;
}

// 头插法
void insertHeadNode(LinkList L, int e) {
    LNode* newNode = (LNode*)malloc(sizeof(LNode));
    if (newNode == NULL) return;
    newNode->data = e;
    newNode->next = L->next;
    L->next = newNode;
}

// 函数释放为链表分配的内存
void freeList(LinkList L) {
    LNode* current = L;
    LNode* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

// 遍历单链表
void showLinkList(LinkList L) {
    L = L->next;
    while (L != NULL) {
        printf("%-3d", L->data);
        L = L->next;
    }
    printf("\n");
}

// 删除所有值为x的结点,并释放空间,(假设值为x的结点不唯一)
int deleteXofValuse(LinkList L, int x) {
    LNode* p = L->next;
    LNode* pre = L;
    LNode* q;
    while (p != NULL) {
        if (p->data == x) {
            q = p;
            p = p->next;
            pre->next = p;
            free(q);
        }
        else {
            pre = p;
            p = p->next;
        }
    }
    return 1;
}

// 在带头结点的单链表L中删除一个指定值为x的结点,并释放空间,假设值为x的结点不唯一
int deleteX(LinkList L, int x) {
    LNode* p = L->next;  // p指向第一个结点
    LNode* pre = L;      // pre指向头结点
    LNode* q;            // q指向p的前驱结点
    while (p != NULL) {  // p不为空
        if (p->data == x) { // 如果p结点的值为x
            q = p;      // q指向p
            p = p->next;    // p指向下一个结点
            pre->next = p;  // 删除q结点
            free(q);    // 释放q结点
        }
        else {
            pre = p;
            p = p->next;
        }
    }
    return 1;
}



int main(int argc, char const* argv[]) {
    LinkList L;
    initList(&L);
    insertTailNode(L, 1);
    insertTailNode(L, 1);
    insertTailNode(L, 1);
    insertTailNode(L, 2);
    insertTailNode(L, 3);
    insertTailNode(L, 4);
    insertTailNode(L, 5);
    insertTailNode(L, 3);
    insertTailNode(L, 4);
    insertTailNode(L, 5);
    showLinkList(L);
    deleteAllX(L, 1);
    showLinkList(L);
    return 0;
}



