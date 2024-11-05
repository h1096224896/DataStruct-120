#include "3.单链表.c"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 将带头结点的单链表就地逆置
int reverseList(LinkList L) {
    LNode* p = L->next;  // p指向第一个结点
    LNode* q;            // q指向p的前驱结点
    L->next = NULL;      // 置空头结点
    while (p != NULL) {  // p不为空
        q = p;
        p = p->next;

        q->next = L->next;  // 头插法
        L->next = q;
    }
    return 1;
}

int main(int argc, char const* argv[]) {
    srand(time(NULL));
    LinkList L;
    initList(&L);
    for (int i = 0; i < 10; i++) {
        insertTailNode(L, arc4random() % (10));
    }
    showLinkList(L);
    reverseList(L);
    showLinkList(L);
    return 0;
}