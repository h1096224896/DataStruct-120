#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 插入排序
void insert_sort(int* arr, int len) {
    for (int i = 1; i < len; i++) {
        int temp = arr[i];   // 保存当前值
        while (i > 0 && arr[i - 1] > temp) {  // 从后往前查找插入位置
            arr[i] = arr[i - 1];
            i--;
        }
        arr[i] = temp;
    }
}


int main() {
    int arr[] = { 23, 12, 45, 2, 67, 34, 89, 12, 34 };
    int len = sizeof(arr) / sizeof(arr[0]);
    insert_sort(arr, len);
    for (size_t i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}