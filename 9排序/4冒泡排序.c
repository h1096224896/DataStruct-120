#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// 冒泡排序
// 平均:O(n^2) 最好:O(n) 最坏:O(n^2) 稳定
void bubbleSort(int* arr, int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 改进冒泡排序
// 平均:O(n^2) 最好:O(n) 最坏:O(n^2) 稳定
void bubbleSort2(int* arr, int len) {
    for (int i = 0; i < len - 1; i++) {
        int flag = 0;  // 未交换
        for (int j = 0; j < len - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)  // 若未交换,则有序,直接退出
            break;
    }

}

int main() {
    int arr[] = { 23, 12, 45, 2,2, 67, 34, 89, 12, 34 };
    int len = sizeof(arr) / sizeof(arr[0]);
    bubbleSort2(arr, len);
    for (size_t i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}