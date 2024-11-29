#include <stdio.h>
#include <string.h>
#include <stdlib.h>


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

void merge_sort(int* arr, int len) {
    if (len <= 1) {
        return;
    }
    int mid = len / 2;
    merge_sort(arr, mid);
    merge_sort(arr + mid, len - mid);
    int* temp = (int*)malloc(len * sizeof(int));
    merge(arr, mid, arr + mid, len - mid, temp);
    memcpy(arr, temp, len * sizeof(int));
    free(temp);
}
int main() {
    int arr[] = { 23, 12, 45, 2,2, 67, 34, 89, 12, 34 };
    int len = sizeof(arr) / sizeof(arr[0]);
    merge_sort(arr, len);
    for (size_t i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}