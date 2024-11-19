#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 可是使用双指针,利用快排思想,从两边对比元素的正负并进行交换,左右依次进行.
void fun(int* arr, int n) {
    int left = 0;
    int right = n - 1;
    int temp = arr[0];  // 提前保存第一个元素,方便在数组内直接交换
    while (left < right) {
        while (arr[right] > 0) {  // 由题意,数组不含元素0
            right--;
        }
        arr[left++] = arr[right];
        while (arr[left] < 0) {  // 由题意,数组不含元素0
            left++;
        }
        arr[right--] = arr[left];
    }
    arr[left] = temp;  // 把最开始的
}

int main() {
    int arr[] = { 1, -3,-5, 5, 7,-9,-11,-12};
    int len = sizeof(arr) / sizeof(arr[0]);
    fun(arr, len);
    for (size_t i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}