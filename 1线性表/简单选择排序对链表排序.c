#include "3.单链表.c"

// 设计简单选择排序算法。采用单链表存储结构实现所有结点中数据域值从大到小进行排序。
void selectionSort(LinkList L) {
    LNode* p = L->next;
    while (p != NULL) {
        LNode* maxNode = p;  // 记录最大值结点
        LNode* q = p->next;  // 从p的下一个结点开始遍历
        while (q != NULL) {  // 遍历链表
            if (q->data > maxNode->data)     // 如果q结点的值大于maxNode结点的值
                maxNode = q;    // 记录q结点
            q = q->next;    // q指向下一个结点
        }
        if (maxNode != p) { // 如果maxNode不是p结点
            int temp = p->data;
            p->data = maxNode->data;
            maxNode->data = temp;
        }
        p = p->next;  // p指向下一个结点
    }
}

int main(int argc, char const* argv[]) {
    srand(time(NULL));
    LinkList L;
    initList(&L);
    for (int i = 0; i < 10; i++) {
        insertTailNode(L, arc4random() % (10));
    }
    showLinkList(L);
    selectionSort(L);
    showLinkList(L);
    return 0;
}
