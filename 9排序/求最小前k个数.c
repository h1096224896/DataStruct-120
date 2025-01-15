#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 交换函数
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 分区函数
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // 选取最后一个元素作为基准
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// 快速选择算法
void quickSelect(int arr[], int low, int high, int k) {
    if (low < high) {
        int pi = partition(arr, low, high);
        if (pi == k)
            return;
        else if (pi > k) {
            quickSelect(arr, low, pi - 1, k);
        }
        else {
            quickSelect(arr, pi + 1, high, k);
        }
    }
}

// 主函数
int main() {
    int arr[] = { 1, 3, 5, 7, 2, 4, 6, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    quickSelect(arr, 0, n - 1, k);
    for (int i = 0; i < k; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}