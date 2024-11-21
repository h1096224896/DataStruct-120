#include <stdio.h>
#include <stdlib.h>

// 定义链表节点
typedef struct QNode {
    int data;              // 数据域
    struct QNode* next;     // 指针域
} QNode;

// 定义队列
typedef struct Queue {
    QNode* front;            // 指向队头节点的指针
    QNode* rear;            // 指向队尾节点的指针
} Queue;

// 初始化队列
Queue* initQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// 初始化一个只带尾指针的队列
void initQueue2(Queue** q) {
    *q = (Queue*)malloc(sizeof(Queue));
    (*q)->rear = NULL;
}

// EnQueue
void enQueue(Queue* q, int value) {
    QNode* newNode = (QNode*)malloc(sizeof(QNode));
    newNode->data = value;
    if (q->rear == NULL) { // 队列为空
        newNode->next = newNode; // 只有一个元素,自己的next指向自己
        q->rear = newNode;  // 更新队尾
    }
    else { // 队列不为空
        newNode->next = q->rear->next; // 插入到队尾的下一个位置
        q->rear->next = newNode;
        q->rear = newNode; // 更新队尾
    }
}

// DeQueue
int deQueue(Queue* q) {
    if (q->rear == NULL) { // 队列为空
        printf("Queue is empty!\n");
        return -1; // 表示出队失败
    }
    QNode* front = q->rear->next; // 补充队头节点
    int value = front->data;     // 保存队头数据
    if (front == q->rear)  // 队列中只有一个节点
        q->rear = NULL; // 出队后队列为空
    else  // 队列中有多个节点
        q->rear->next = front->next; // 修改队尾的next指针
    free(front); // 释放队头节点
    return value;
}

int main() {
    Queue* q;
    initQueue2(&q);
    // 入队
    enQueue(q, 10);
    enQueue(q, 20);
    enQueue(q, 30);
    // 出队
    printf("Dequeue: %d\n", deQueue(q)); // 10
    printf("Dequeue: %d\n", deQueue(q)); // 20
    // 再入队
    enQueue(q, 40);
    enQueue(q, 50);
    // 继续出队
    printf("Dequeue: %d\n", deQueue(q)); // 30
    printf("Dequeue: %d\n", deQueue(q)); // 40
    printf("Dequeue: %d\n", deQueue(q)); // 50
    printf("Dequeue: %d\n", deQueue(q)); // Queue is empty!
    return 0;
}

