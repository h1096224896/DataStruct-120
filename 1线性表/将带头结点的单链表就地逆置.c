#include "3.单链表.c"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 将带头结点的单链表就地逆置
// 就地逆置: 用头插法从新建立一个链表
int reverseList(LinkList L) {
    LNode* p = L->next;  // p指向第一个结点
    LNode* pre;            // q指向p的前驱结点
    L->next = NULL;      // 置空头结点
    while (p != NULL) {  // p不为空
        pre = p;
        p = p->next;

        pre->next = L->next;  // 头插法
        L->next = pre;
    }
    return 1;
}

int main(int argc, char const* argv[]) {
    srand(time(NULL));
    LinkList L;
    initList(&L);
    for (int i = 0; i < 10; i++) {
        insertTailNode(L, arc4random() % (100));
    }
    showLinkList(L);
    reverseList(L);
    showLinkList(L);
    return 0;
}