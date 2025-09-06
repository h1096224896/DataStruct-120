#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 交换两个元素的值
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 分区函数
int partition(int arr[], int low, int high) {
    // 随机选择枢轴
    int pivotIndex = low + arc4random() % (high - low + 1);
    int pivot = arr[pivotIndex];  // 选择枢轴
    swap(&arr[pivotIndex], &arr[high]);  // 将枢轴移到末尾
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);  // 将枢轴移到正确位置
    return i + 1;  // 返回枢轴的位置
}

// 快速排序函数
// 平均:O(nlogn) 最好:O(nlogn) 最坏:O(n^2)
void quick_sort(int arr[], int low, int high, int k) {  // low:起始位置 high:结束位置
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1, k);
        quick_sort(arr, pi + 1, high, k);
    }
}

int main() {
    int arr[] = { 23, 12, 45, 2,2, 67, 34, 89, 12, 34 };
    int len = sizeof(arr) / sizeof(arr[0]);
    quick_sort(arr, 0, len, 3);
    for (size_t i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}