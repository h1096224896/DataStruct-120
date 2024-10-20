#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// 简单选择排序
void select_sort(int arr[], int len) {
    int i, j, temp;
    for (i = 0; i < len - 1; i++) {
        int min = i;
        for (j = i + 1; j < len; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min != i) {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

// 冒泡排序
void bubble_sort(int arr[], int len) {
    int i, j, temp;
    for (i = 0; i < len - 1; i++) {
        for (j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 快速排序
int patition(int arr[], int left, int right) {
    int pivot = arr[left];
    while (left < right) {
        while (left < right && arr[right] >= pivot) {  // 右半部分
            right--;
        }
        arr[left] = arr[right];

        while (left < right && arr[left] <= pivot) {
            left++;
        }
        arr[right] = arr[left];
    }
    arr[left] = pivot;
    return left;
}
void quick_sort(int arr[], int left, int right) {
    if (left < right) {
        int pivot_index = patition(arr, left, right);
        quick_sort(arr, left, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, right);
    }
}

// 插入排序
void insert_sort(int arr[], int len) {
    int i, j, temp;
    for (i = 1; i < len; i++) {
        if (arr[i - 1] > arr[i]) {
            temp = arr[i];
            for (j = i - 1; j >= 0 && arr[j] > temp; j--) {
                arr[j + 1] = arr[j];
            }
            arr[j + 1] = temp;
        }
    }
}
// 折半插入排序

// 希尔排序
void shell_sort(int arr[], int len) {
    int i, j, temp, d;
    for (d = len / 2; d > 0; d = d / 2) {
        for (i = d;i < len; i++) {
            temp = arr[i];
            for (j = i - d; j >= 0 && arr[j] > temp; j = j - d) {
                arr[j + d] = arr[j];
            }
            arr[j + d] = temp;
        }
    }
}

// void shell_sort_d(int arr[], int len, int d) {
//     int i, j, temp;
//     for (; d > 0; d = d / 2) {
//         for (i = d; i < len; i++) {
//             temp = arr[i];
//             for (j = i - d; j >= 0 && arr[j] > temp; j = j - d) {
//                 arr[j + d] = arr[j];
//             }
//             arr[j + d] = temp;
//         }
//     }
// }


int main() {
#define LEN 10
    int arr[LEN];
    srand(time(NULL));
    for (int i = 0; i < LEN; i++) {
        arr[i] = arc4random() % 100; // 默认范围是 0 到 UINT32_MAX
    }
    for (size_t i = 0; i < LEN; i++) {  // show
        printf("%-3d", arr[i]);
    }
    printf("\n");
    select_sort(arr, LEN);  // sort
    for (size_t i = 0; i < LEN; i++) {
        printf("%-3d", arr[i]);
    }
    printf("\n");
    return 0;
}