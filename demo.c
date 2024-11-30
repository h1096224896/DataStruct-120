#include <stdio.h>
#include <stdlib.h>

// 定义队列元素类型
typedef int QElemType;

// 定义队列节点结构
typedef struct QNode {
    QElemType data;       // 数据域
    struct QNode* next;   // 指针域，指向下一个节点
} QNode, * QueuePtr;

// 定义链式队列结构
typedef struct {
    QueuePtr front;  // 队头指针
    QueuePtr rear;   // 队尾指针
} LinkQueue;

// 初始化队列
void InitQueue(LinkQueue* Q) {
    Q->front = NULL;
    Q->rear = NULL;
}

// 队尾插入新元素
int EnQueue(LinkQueue* Q, QElemType e) {
    // 创建新节点
    QueuePtr newNode = (QueuePtr)malloc(sizeof(QNode));
    if (!newNode) { // 检查内存分配是否成功
        return 0; // 分配失败，返回失败标志
    }
    newNode->data = e;   // 将数据赋值给新节点
    newNode->next = NULL; // 新节点的next置为NULL

    // 检查队列是否为空
    if (Q->rear == NULL) {
        // 队列为空，新节点既是队头又是队尾
        Q->front = newNode;
        Q->rear = newNode;
    }
    else {
        // 队列非空，将新节点链接到当前队尾，并更新队尾指针
        Q->rear->next = newNode;
        Q->rear = newNode;
    }
    return 1; // 插入成功
}

// 打印队列中所有元素（调试用）
void PrintQueue(LinkQueue Q) {
    QueuePtr current = Q.front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// 主函数测试
int main() {
    LinkQueue Q;
    InitQueue(&Q); // 初始化队列

    EnQueue(&Q, 10); // 插入元素10
    EnQueue(&Q, 20); // 插入元素20
    EnQueue(&Q, 30); // 插入元素30

    PrintQueue(Q); // 打印队列：10 20 30

    return 0;
}