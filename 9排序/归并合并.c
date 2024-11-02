#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 归并合并两个有序数组,使其递增为新有序数组
void merge(int arr1[], int len1, int arr2[], int len2, int arr3[]) {
    int i = 0, j = 0, k = 0;
    while (i < len1 && j < len2) {
        if (arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++];
        }
        else {
            arr3[k++] = arr2[j++];
        }
    }
    while (i < len1) {
        arr3[k++] = arr1[i++];
    }
    while (j < len2) {
        arr3[k++] = arr2[j++];
    }
}

// 在一个数组中数据存储在下标 1~m+n里 ,前 m 个有序,后 n 个有序,编写算法使其整体有序
void merge2(int* arr, int m, int n, int len) {
    int* tempArr = (int*)malloc((m + n + 1) * sizeof(int));
    int i = 1, j = m + 1, k = 1;
    while (i <= m && j <= m + n) {
        if (arr[i] < arr[j]) {
            tempArr[k++] = arr[i++];
        }
        else {
            tempArr[k++] = arr[j++];
        }
    }
    while (i <= m) {
        tempArr[k++] = arr[i++];
    }
    while (j <= m + n) {
        tempArr[k++] = arr[j++];
    }
    for (i = 1; i <= m + n; i++) {
        arr[i] = tempArr[i];
    }
    free(tempArr);
}

// (插入排序)不使用额外空间,在一个数组中数据存储在下标 1~m+n里 ,前 m 个有序,后 n 个有序,编写算法使其整体有序
void merge3(int* arr, int m, int n, int len) {
    int i = 1, j = m + 1;
    while (i <= m && j <= m + n) {
        if (arr[i] < arr[j]) {
            i++;
        }
        else {
            int temp = arr[j];
            for (int k = j - 1; k >= i; k--) {
                arr[k + 1] = arr[k];
            }
            arr[i] = temp;
            i++;
            j++;
        }
    }
}

int main() {
    int arr[11] = { 0,1,3,5,7,9,2,4,6,8,10 };
    int len = sizeof(arr) / sizeof(arr[0]);

    merge2(arr, 5, 5, len);
    for (int i = 0; i < len; i++) {
        printf("%-3d", arr[i]);
    }
    return 0;
}