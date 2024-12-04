#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// 插入排序
// 平均:O(n^2) 最好(正序):O(n) 最坏(逆序):O(n^2)
void insert_sort(int* arr, int len) {
    for (int i = 1; i < len; i++) {
        int temp = arr[i];   // 保存当前值,防止向后移动时被覆盖
        while (i > 0 && arr[i - 1] > temp) {  // 从后往前查找插入位置
            arr[i] = arr[i - 1];  // 前一个往后移
            i--;
        }
        arr[i] = temp;
    }
}
void fun(int* arr, int len) {
    for (size_t i = 1; i < len; i++) {
        int temp = arr[i];
        while (i > 0 && arr[i - 1] > temp) {
            arr[i] = arr[i - 1];
            i--;
        }
        arr[i] = temp;
    }
}



int main() {
    int arr[] = { 23, 12, 45, 2,2, 67, 34, 89, 12, 34 };
    int len = sizeof(arr) / sizeof(arr[0]);
    fun(arr, len);
    for (size_t i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}