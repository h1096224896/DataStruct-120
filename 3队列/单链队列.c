#include <stdio.h>
#include <stdlib.h>

typedef int QElemType;
typedef struct QNode {
    QElemType data;
    struct QNode* next;
} QNode, * QueuePtr;

typedef struct {
    QueuePtr front; // 队头指针
    QueuePtr rear;  // 队尾指针
} LinkQueue;

// 初始化队列
void InitQueue(LinkQueue* Q) {
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
    if (!Q->front) exit(1);
    Q->front->next = NULL;
}

// 在队尾插入新的元素 e
int EnQueue(LinkQueue* Q, int e) {
    QNode* newNode = (QNode*)malloc(sizeof(QNode));
    if (newNode == NULL) return 0;  
    newNode->data = e;
    newNode->next = NULL;  // 构造新节点
    if (Q->front == Q->rear) {  // 队空,直接在头节点后面插入新节点
        Q->front->next = newNode;
    }
    else {
        Q->rear->next = newNode;  
    }
    Q->rear = newNode;  //调整尾指针继续指向最后一个节点
    return 1;
}

// 出队列，删除队头元素，并用 e 返回其值
int DeQueue(LinkQueue* Q, int* e) {
    if (Q->front == Q->rear) return 0;  // 队列为空
    QueuePtr p = Q->front->next;  // p 指向队头元素
    *e = p->data;
    Q->front->next = p->next;
    if (Q->rear == p) Q->rear = Q->front;  // 若原队列中只有一个元素，则删除后变为空队列
    free(p);
    return 1;
}

// 判断队列是否为空
int QueueEmpty(LinkQueue* Q) {
    return Q->front == Q->rear;
}

// 测试函数：打印队列中的所有元素
void PrintQueue(LinkQueue* Q) {
    QueuePtr p = Q->front->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 主函数，测试插入
int main() {
    LinkQueue Q;
    InitQueue(&Q);
    QueueEmpty(&Q) ? printf("队列为空\n") : printf("队列不为空\n");

    EnQueue(&Q, 1);
    QueueEmpty(&Q) ? printf("队列为空\n") : printf("队列不为空\n");
    DeQueue(&Q, 0);
    QueueEmpty(&Q) ? printf("队列为空\n") : printf("队列不为空\n");


    PrintQueue(&Q); // 输出队列内容

    return 0;
}