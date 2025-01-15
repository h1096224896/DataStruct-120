#include <stdio.h>

#define MAX_SIZE 100  // 假设集合的最大容量
typedef struct {
    int data[MAX_SIZE];  // 存储元素
    int length;          // 当前集合的长度
} SqList;



// 实现集合的并操作
// 思路: 用B中的每一个元素与A中的元素进行比较，如果B中的元素在A中不存在，则将其添加到A的末尾
void unionSet(SqList* A, SqList B) {
    for (int i = 0; i < B.length; i++) {  // 遍历B中的元素
        int found = 0;  // 标记B中的元素是否在A中存在
        for (int j = 0; j < A->length; j++) {  // 遍历A中的元素
            if (B.data[i] == A->data[j]) {  // 如果B中的元素在A中已经存在, 则跳
                found = 1;
                break;
            }
        }
        if (found == 0) {  // 说明B中的元素在A中不存在, 则将其添加到A数组后
            A->data[A->length++] = B.data[i];
        }
    }
}

// 实现集合的交操作
// 思路: 用B中的每一个元素与A中的元素进行比较，如果B中的元素在A中存在，则将其保留在A的前面, 最后更新A的长度
void intersection(SqList* A, SqList B) {
    int k = 0;  // 用于记录交集的长度
    for (int i = 0; i < B.length; i++) {  // 遍历B中的元素
        for (int j = 0; j < A->length; j++) {  // 遍历A中的元素
            if (B.data[i] == A->data[j]) {  // 如果B中的元素在A中存在
                A->data[k++] = A->data[j];  // 保留该元素
                break;
            }
        }
    }
    A->length = k;  // 更新A的长度
}

int main() {
    SqList A = { {1, 2, 3, 4,5}, 5 };
    SqList B = { {2, 4, 6}, 3 };
    intersection(&A, B);
    for (int i = 0; i < A.length; i++) {
        printf("%d ", A.data[i]);
    }
    return 0;
}