#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void countSort(int* arr, int len) {
    int* arr2 = (int*)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        int cnt = 0;
        for (int j = 0; j < len; j++) {  // 计算比当前元素小的元素个数
            if (arr[i] > arr[j])
                cnt++;
        }
        arr2[cnt] = arr[i];
    }
    for (int i = 0; i < len; i++) {
        arr[i] = arr2[i];
    }
}

int main() {
    int arr[] = { 1,3,5,3,9 };
    int len = sizeof(arr) / sizeof(int);
    countSort(arr, len);
    for (size_t i = 0; i < len; i++) {
        printf("%-3d", arr[i]);
    }
    return 0;
}