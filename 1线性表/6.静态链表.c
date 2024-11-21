#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 静态链表
#define MAXSIZE 100
struct QNode {  // 
    int data;  // 数据域
    int next;  // 指针域
};

// 初始化静态链表
int InitStaticLinkList(struct QNode* space) {
    for (int i = 0; i < MAXSIZE - 1; i++) {
        space[i].next = i + 1;  // 将所有结点链接在一起
    }
    space[MAXSIZE - 1].next = 0;  // 最后一个结点的指针域为0
    return 0;
}

// 插入位置为i的结点
int InsertStaticLinkList(struct QNode* space, int i, int e) {
    int j = MAXSIZE - 1;  // j指向最后一个结点
    if (i < 1 || i > MAXSIZE) {
        return -1;
    }
    int k = MAXSIZE - 1;  // k指向头结点
    for (int l = 1; l < i; l++) {  // 寻找第i个结点的前驱结点
        k = space[k].next;
    }
    j = space[j].next;
    space[j].data = e;  // 将数据e赋值给新结点
    space[j].next = space[k].next;  // 将第i个结点的后继结点赋值给新结点的后继结点
    space[k].next = j;  // 将新结点的下标赋值给第i个结点的后继结点
    return 0;
}

int main() {
    struct QNode StaticLinkList[MAXSIZE];  // 静态链表
    return 0;
}