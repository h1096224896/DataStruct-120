#include <stdio.h>
#include <stdlib.h>


#define USER_CAPACITY 5
#define MAX_SIZE (USER_CAPACITY + 1)
// 循环队列结构体定义
typedef struct {
    int data[MAX_SIZE];  // 用于存储队列元素的数组
    int front;            // 队列头指针
    int rear;            // 队列尾指针
} CircularQueue;

// 初始化队列
void initQueue(CircularQueue* Q) {
    Q->front = 0;
    Q->rear = 0;
}

// 按逆序将数组元素插入到队列
void reverseInsertArray(CircularQueue* Q, int* arr, int n) {
    for (int i = n - 1; i >= 0; i--) { // 从数组末尾开始遍历
        if ((Q->rear + 1) % MAX_SIZE == Q->front) {  // 队列已满
            printf("队列已满，无法插入！\n");
            return;
        }
        Q->rear = (Q->rear + 1) % MAX_SIZE;  // 队尾指针后移
        Q->data[Q->rear] = arr[i];  // 将数组元素插入队尾
    }
    printf("数组元素逆序插入成功！\n");
}

// 打印队列内容
void printQueue(CircularQueue* Q) {
    if (Q->front == Q->rear) {
        printf("队列为空！\n");
        return;
    }
    printf("队列内容：");
    int i = Q->front + 1;
    while (i != (Q->rear + 1) % MAX_SIZE) {
        printf("%d ", Q->data[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

// 主函数
int main() {
    CircularQueue Q;
    int capacity = 10; // 队列容量
    initQueue(&Q);

    int arr[] = { 1, 2, 3, 4, 5,6,7 }; // 待插入的数组
    int n = sizeof(arr) / sizeof(arr[0]);

    reverseInsertArray(&Q, arr, n);
    printQueue(&Q);

    return 0;
}