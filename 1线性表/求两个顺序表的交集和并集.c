#include <stdio.h>

#define MAX_SIZE 100  // 假设集合的最大容量
typedef struct {
    int data[MAX_SIZE];  // 存储元素
    int length;          // 当前集合的长度
} SqList;



// 实现集合的并操作
void unionSet(SqList* A, SqList B) {
    for (int i = 0; i < B.length; i++) {  // 遍历B中的元素
        for (int j = 0; j < A->length; j++) {
            if (B.data[i] == A->data[j]) {  // 如果B中的元素在A中已经存在, 则跳过
                break;
            }
        }
        // 说明B中的元素在A中不存在, 则将其添加到A中
        A->data[A->length++] = B.data[i];
    }
}

// 实现集合的交操作
void intersection(SqList* A, SqList B) {
    int k = 0;  // 用于记录交集的长度
    for (int i = 0; i < A->length; i++) {
        int found = 0;  // 用于标记A中的元素是否在B中存在
        for (int j = 0; j < B.length; j++) {
            if (A->data[i] == B.data[j]) {  // 如果A中的元素在B中存在
                found = 1;
                break;
            }
        }
        if (found) {
            A->data[k++] = A->data[i];  // 保留该元素
        }
    }
    A->length = k;  // 更新A的长度
}

int main() {
    SqList A = { {1, 2, 3, 4,5}, 5 };
    SqList B = { {4, 5, 6, 7, 8}, 5 };
    intersection(&A, B);
    for (int i = 0; i < A.length; i++) {
        printf("%d ", A.data[i]);
    }
    return 0;
}