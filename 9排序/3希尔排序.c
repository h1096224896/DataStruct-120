#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// 希尔排序
// 平均:O(n^1.3) 最好:O(n) 最坏:O(n^2)
void shellSort(int* arr, int len) {
    for (int gap = len / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < len; i++) {
            int temp = arr[i];  // 保存当前值
            int j = i - gap;  // 保存当前值的前一个位置
            while (j >= 0 && arr[j] > temp) {  // 从后往前找插入位置
                arr[j + gap] = arr[j];
                j -= gap;
            }
            arr[j + gap] = temp;
        }
    }
}



int main() {
    int arr[] = { 23, 12, 45, 2,2, 67, 34, 89, 12, 34 };
    int len = sizeof(arr) / sizeof(arr[0]);
    shellSort(arr, len);
    for (size_t i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}