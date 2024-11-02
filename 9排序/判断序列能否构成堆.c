#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 判断序列能否构成小顶堆
int isHeap(int* arr, int len) {
    for (size_t i = 0; i < len / 2; i++) {
        if (arr[i] > arr[2 * i + 1] || arr[i] > arr[2 * i + 2])
            return 0;
    }
    return 1;
}

int main() {
    // 随机生成一个数组
    int arr[5];
    int len = sizeof(arr) / sizeof(arr[0]);
    for (size_t i = 0; i < len; i++) {
        arr[i] = arc4random() % 100;
    }
    for (size_t i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    
    if (isHeap(arr, len))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}