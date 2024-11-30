#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 归并合并两个有序数组,使其递增为新有序数组
// 时间复杂度O(n) 空间复杂度O(n) 其中n为两个数组长度之和
void merge(int arr1[], int len1, int arr2[], int len2, int arr3[]) {
    int i = 0, j = 0, k = 0;
    while (i < len1 && j < len2) {
        if (arr1[i] < arr2[j]) 
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }
    while (i < len1) 
        arr3[k++] = arr1[i++];
    while (j < len2) 
        arr3[k++] = arr2[j++];
}

// 暴力查找三元组最小值
int minTriple(int* arr, int len) {
    int i = 0;
    int min = abs(arr[i] - arr[i + 1]) + abs(arr[i + 1] - arr[i + 2]) + abs(arr[i + 2] - arr[i]);
    for (int i = 1; i < len - 2; i++) {
        int cur = abs(arr[i] - arr[i + 1]) + abs(arr[i + 1] - arr[i + 2]) + abs(arr[i + 2] - arr[i]);
        if (cur < min) {
            min = cur;
        }
    }
    return min;
}

int main() {
    int arr1[] = { -1, 0 , 9 };
    int arr2[] = { -25, -10 , 10,11 };
    int arr3[] = { 2,9,17,30,41 };
    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    int len2 = sizeof(arr2) / sizeof(arr2[0]);
    int len3 = sizeof(arr3) / sizeof(arr3[0]);
    int* tempArr = (int*)malloc((len1 + len2 + len3) * sizeof(int));
    merge(arr1, len1, arr2, len2, tempArr);
    merge(tempArr, len1 + len2, arr3, len3, tempArr);
    for (size_t i = 0; i < len1 + len2 + len3; i++) {
        printf("%d ", tempArr[i]);
    }
    printf("\n");
    printf("minTriple: %d\n", minTriple(tempArr, len1 + len2 + len3));
    free(tempArr);
    return 0;
}