#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// 调整堆
void adjustHeap(int* arr, int i, int len) {
    int temp = arr[i];  // 先取出当前元素i
    for (int k = i * 2 + 1; k < len; k = k * 2 + 1) {  // 从i结点的左子结点开始，也就是2i+1处开始
        if (k + 1 < len && arr[k] < arr[k + 1]) {  // 如果左子结点小于右子结点，k指向右子结点
            k++;
        }
        if (arr[k] > temp) {  // 如果子节点大于父节点，将子节点值赋给父节点（不用进行交换）
            arr[i] = arr[k];
            i = k;
        }
        else {
            break;
        }
    }
    arr[i] = temp;  // 将temp值放到最终的位置
}

// 堆排序
// 平均:O(nlogn) 最好:O(nlogn) 最坏:O(nlogn)
void heapSort(int* arr, int len) {
    // 1. 构建大顶堆
    for (int i = len / 2 - 1; i >= 0; i--) {
        adjustHeap(arr, i, len);
    }
    // 2. 调整堆结构+交换堆顶元素与末尾元素
    for (int i = len - 1; i > 0; i--) {
        swap(arr, 0, i);  // 将堆顶元素与末尾元素进行交换
        adjustHeap(arr, 0, i);  // 重新对堆进行调整
    }
}

int main() {
    int arr[] = { 23, 12, 45, 2,2, 67, 34, 89, 12, 34 };
    int len = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, len);
    for (size_t i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}