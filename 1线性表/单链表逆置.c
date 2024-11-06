#include "3.单链表.c"


void Reverse(LinkList L) {
    if (L == NULL) return;
    LNode* stack[100];
    int top = -1; // 栈顶指针

    // 将链表节点依次压入栈中
    LNode* p = L->next;
    while (p != NULL) {
        stack[++top] = p; // 压栈
        p = p->next;
    }
    while (top >= 0) {
        L->next = stack[top--];
        L = L->next;
    }
    L->next = NULL;  // 将最后一个结点的 next 设置为 NULL
}

int main(int argc, char const* argv[]) {
    LinkList L;
    initList(&L);
    insertTailNode(L, 3);
    insertTailNode(L, 4);
    insertTailNode(L, 5);
    insertTailNode(L, 1);
    insertTailNode(L, 7);
    showLinkList(L);
    Reverse(L);
    showLinkList(L);
    return 0;
}