#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct LNode {
    int data;
    struct LNode* next;
}*LinkList, LNode;  // 前面是指针型

// 初始化一个带头结点的单链表
int initList(LinkList* head) {
    *head = (LinkList)malloc(sizeof(LNode));  // 将malloc的结果强制转换为LinkList
    if (*head == NULL) {  // 检查分配是否成功
        return 0;
    }
    (*head)->data = 0;
    (*head)->next = NULL;
    return 1;
}

// 头插法
void insertHeadNode(LinkList L, int e) {
    LNode* s = (LNode*)malloc(sizeof(LNode));
    if (s == NULL) return;
    s->data = e;
    s->next = L->next;
    L->next = s;
}

// 线性表中各结点的检索概率不等，则可用如下策略提高顺序检索的效率:
// 若找到指定的结点，将该结点和其前驱结点(若存在)交换位置
int SearchArr(int arr[], int length, int num) {
    int temp, cnt = 0;
    for (int i = 0; i < length; i++) {
        if (arr[i] == num) {
            temp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = temp;
            cnt++;
        }
    }
    return cnt; //查找到该元素的次数
}

// 若找到指定的结点，将该结点和其前驱结点(若存在)交换位置
int SearchLinkList(LinkList L, int num) {
    LNode* pre = L; // 前驱结点
    LNode* p = L->next; // 当前结点
    LNode* prepre = NULL; // 前驱结点的前驱结点
    int cnt = 0; // 查找到该元素的次数
    while (p != NULL) {
        if (p->data == num) {
            if (pre == L) {
                return 1;
            }
            pre->next = p->next;
            p->next = pre;
            prepre->next = p;
            cnt++;
        }
        prepre = pre;
        pre = p;
        p = p->next;
    }
    return cnt;
}

int main() {
    LinkList L;
    initList(&L);
    insertHeadNode(L, 2);
    insertHeadNode(L, 5);
    insertHeadNode(L, 5);
    insertHeadNode(L, 3);
    // 打印链表
    LNode* p = L->next;
    while (p != NULL) {
        printf("%-3d", p->data);
        p = p->next;
    }
    printf("\n");
    printf("SearchLinkList: %d\n", SearchLinkList(L, 5));
    // 打印链表
    p = L->next;
    while (p != NULL) {
        printf("%-3d", p->data);
        p = p->next;
    }
    printf("\n");
    return 0;
}