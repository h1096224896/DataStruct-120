#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 简单选择排序
// 平均:O(n^2) 最好:O(n^2) 最坏:O(n^2)
void selectSort(int* arr, int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] > arr[j]) {  // 打擂台, 但是每次遇到更小的值都要交换
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// 选择排序改进
void selectSort2(int* arr, int len) {
    for (int i = 0; i < len - 1; i++) {
        int min = i;  // 记录最小值的下标   
        for (int j = i + 1; j < len; j++) {  // 找到最小值的下标
            if (arr[min] > arr[j]) {
                min = j;  // 更新最小值的下标
            }
        }
        if (min != i) {  // 如果最小值不是当前值，交换
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}



int main() {
    int arr[] = { 46, 74, 53, 14,26, 38, 86, 65, 27, 34 };
    int len = sizeof(arr) / sizeof(arr[0]);
    selectSort(arr, len);
    for (size_t i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}