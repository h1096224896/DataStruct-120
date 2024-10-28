#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

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

// 折半插入排序
void insertHalfsortort(int* arr, int len) {
    for (int i = 1; i < len; i++) {
        int temp = arr[i];   // 保存当前值
        int left = 0, right = i - 1;  // 开头和当前值前一个
        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] > temp) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        for (int j = i - 1; j >= left; j--) {
            arr[j + 1] = arr[j];
        }
        arr[left] = temp;
    }
}

int main() {
    printf("%d\n", Fibonacci(0));
    return 0;
}