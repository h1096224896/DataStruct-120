#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode* next;
} LNode, * LinkList;

// 创建一个新的节点
LNode* createNode(ElemType value) {
    LNode* newNode = (LNode*)malloc(sizeof(LNode));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// 删除绝对值相等的多余元素
int deleteDuplicateAbs(LinkList* L) {
    if (L == NULL) return 0;
    int appear[1000] = { 0 };  // 未出现计为 0,出现计为 1,假设链表内元素绝对值范围在 0-999;
    LNode* pre = L;
    LNode* p = L->next;
}

// 打印链表
void printList(LinkList head) {
    LNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// 示例代码
int main() {
    // 创建链表: 1 -> -2 -> 2 -> -3 -> 3 -> -1 -> 1 -> NULL
    LinkList head = createNode(1);
    head->next = createNode(-2);
    head->next->next = createNode(2);
    head->next->next->next = createNode(-3);
    head->next->next->next->next = createNode(3);
    head->next->next->next->next->next = createNode(-1);
    head->next->next->next->next->next->next = createNode(1);

    printf("原链表:\n");
    printList(head);

    deleteDuplicateAbs(&head);

    printf("删除绝对值相等的多余元素后的链表:\n");
    printList(head);

    return 0;
}