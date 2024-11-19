#include "3.单链表.c"

// 删除所有数据元素值为x的结点
void DeleteAllX(LinkList L, int x) {
    LNode* p = L->next, * pre = L;  // p指向第一个结点, pre指向头结点
    while (p != NULL) {  // p不为空
        if (p->data == x) {  // 如果p结点的值为x
            pre->next = p->next;  // 删除p结点
            free(p);
            p = pre->next;  // p指向下一个结点
        }
        else { // 如果p结点的值不为x
            pre = p;    // pre指向p
            p = p->next;    // p指向下一个结点
        }
    }
}

int main() {
    LinkList L;
    initList(&L);
    insertHeadNode(L, 1);
    insertHeadNode(L, 2);
    insertHeadNode(L, 3);
    insertHeadNode(L, 4);
    insertHeadNode(L, 3);
    insertHeadNode(L, 5);
    printf("Before delete:\n");
    showLinkList(L);
    DeleteAllX(L, 3);
    printf("After delete:\n");
    showLinkList(L);
    return 0;
}