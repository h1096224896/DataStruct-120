#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode* next;
}LNode, LinkList;

// 初始化一个带头结点的单链表
int initList(LinkList** head) {
    *head = (LNode*)malloc(sizeof(LNode));
    if (*head == NULL) {
        return 0;
    }
    (*head)->data = 0;
    (*head)->next = NULL;
    return 1;
}

// 尾插法
void insertTailNode(LinkList* L, int e) {
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

// 遍历单链表
void showLinkList(LinkList* L) {
    L = L->next;
    while (L != NULL) {
        printf("%-3d", L->data);
        L = L->next;
    }
    printf("\n");
}

void bubble(int* arr, int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 单链表实现冒泡排序
void bubbleSortLinklist(LinkList* L) {
    if (L == NULL || L->next == NULL) return;  // 链表为空或者只有一个元素
    LNode* end = NULL;  // end指针表示已排序部分的起始位置
    while (L->next != end) {  // 外层循环控制循环趟数
        LNode* p = L->next;
        int flag = 0;
        while (p->next != end) {  // 内层循环控制每趟的比较次数
            if (p->data > p->next->data) {
                int temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;
                flag = 1;
            }
            p = p->next;
        }
        if (flag == 0)
            return;  // 如果没有发生交换，说明已经有序
        end = p;  // 更新已排序部分的起始位置
    }
}

int main() {
    LinkList* L;
    initList(&L);
    insertTailNode(L, 5);
    insertTailNode(L, 4);
    insertTailNode(L, 1);
    insertTailNode(L, 3);
    insertTailNode(L, 7);
    insertTailNode(L, 8);
    insertTailNode(L, 7);
    showLinkList(L);
    bubbleSortLinklist(L);
    showLinkList(L);
    return 0;
}