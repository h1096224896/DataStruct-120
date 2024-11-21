#include <stdio.h>
#include <stdlib.h>

// 定义单链表的节点结构
typedef struct QNode {
    int data;
    struct QNode* next;
} QNode;

// 对单链表进行简单选择排序
void selectionSort(QNode* head) {
    QNode* pre = head;
    while (pre != NULL) {
        QNode* min = pre;
        QNode* p = pre->next;
        while (p != NULL) {
            if (p->data < min->data) {
                min = p;
            }
            p = p->next;
        }
        // 交换数据域的值
        if (min != pre) {
            int temp = pre->data;
            pre->data = min->data;
            min->data = temp;
        }
        pre = pre->next;
    }
}

// 创建新节点并插入到链表头部(头插法)
void push(QNode** head_ref, int new_data) {
    QNode* new_node = (QNode*)malloc(sizeof(QNode));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}

// 打印链表
void printList(QNode *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// 主函数
int main() {
    QNode* head = NULL;

    // 添加数据到链表
    push(&head, 5);
    push(&head, 1);
    push(&head, 4);
    push(&head, 2);
    push(&head, 3);

    printf("排序前的链表: \n");
    printList(head);

    selectionSort(head);

    printf("排序后的链表: \n");
    printList(head);

    return 0;
}