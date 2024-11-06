#include "3.单链表.c"

// 假设顺序表 L 中的元素递增排列，设计算法在顺序表中插入元素 x,要求插入后仍保持其 递增有序性。
// 1.先造一个结点
// 2.找到第一个大于x的结点
// 
void insertNew(LinkList L, int x) {
    LNode* p = L;
    LNode* newElem = (LNode*)malloc(sizeof(LNode));
    newElem->data = x;
    if (L == NULL || L->data > x) {  // 处理列表为空或应该在开头插入新元素的情况
        newElem->next = L->next;
        L->next = newElem;
        return;
    }
    while (p->next != NULL && p->next->data < x) {  // 找到第一个大于x的结点
        p = p->next;
    }
    newElem->next = p->next;
    p->next = newElem;
}

int main(int argc, char const* argv[]) {
    LinkList L;
    initList(&L);
    insertTailNode(L, 1);
    insertTailNode(L, 3);
    insertTailNode(L, 5);
    insertTailNode(L, 7);
    insertTailNode(L, 9);
    showLinkList(L);
    insertNew(L, 0);
    showLinkList(L);
    return 0;
}