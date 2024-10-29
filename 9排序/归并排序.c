#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 归并排序
// 平均:O(nlogn) 最好:O(nlogn) 最坏:O(nlogn)
void merge(int* arr, int left, int mid, int right, int* temp) {
    int i = left;  // 左序列指针
    int j = mid + 1;  // 右序列指针
    int t = 0;  // 临时数组指针
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[t++] = arr[i++];
        }
        else {
            temp[t++] = arr[j++];
        }
    }
    while (i <= mid) {  // 将左边剩余元素填充进temp中
        temp[t++] = arr[i++];
    }
    while (j <= right) {  // 将右序列剩余元素填充进temp中
        temp[t++] = arr[j++];
    }
    t = 0;
    // 将temp中的元素全部拷贝到原数组中
    while (left <= right) {
        arr[left++] = temp[t++];
    }
}

// 递归实现归并排序
void mergeSort(int* arr, int left, int right, int* temp) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid, temp);  // 左边归并排序，使得左子序列有序
        mergeSort(arr, mid + 1, right, temp);  // 右边归并排序，使得右子序列有序
        merge(arr, left, mid, right, temp);  // 将两个有序子数组合并操作
    }
}

int main() {
    int arr[] = { 23, 12, 45, 2,2, 67, 34, 89, 12, 34 };
    int len = sizeof(arr) / sizeof(arr[0]);
    int* temp = (int*)malloc(len * sizeof(int));  // 在排序前，先建好一个长度等于原数组长度的临时数组，避免递归中频繁开辟空间
    mergeSort(arr, 0, len - 1, temp);
    for (size_t i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}