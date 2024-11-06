#include "3.单链表.c"

// 设计算法将递增有序顺序表 A 、B  中的元素合并成一个递増有序顺序表 C 。不借助其他存储空间，要求算法的时间复杂度为 O(n)。
void mergeLinkList(LinkList A, LinkList B) {
    LNode* p = A->next;
    LNode* q = B->next;

    while (p != NULL && q != NULL) {
        if (p->data < q->data) {
            A->next = p;
            p = p->next;
        }
        else {
            A->next = q;
            q = q->next;
        }
        A = A->next;
    }
    while (p != NULL) {
        A->next = p;
        p = p->next;
        A = A->next;
    }
    while (q != NULL) {
        A->next = q;
        q = q->next;
        A = A->next;
    }
}



int main(int argc, char const* argv[]) {
    LinkList L1;
    initList(&L1);
    insertTailNode(L1, 1);
    insertTailNode(L1, 3);
    insertTailNode(L1, 5);
    insertTailNode(L1, 7);
    insertTailNode(L1, 9);
    showLinkList(L1);
    LinkList L2;
    initList(&L2);
    insertTailNode(L2, 2);
    insertTailNode(L2, 4);
    insertTailNode(L2, 6);
    showLinkList(L2);

    mergeLinkList(L1, L2);
    showLinkList(L1);
    return 0;
}