#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// 一趟快排
void findIndex(int* arr, int len) {
    int pivot = arr[len - 1];
    int left = 0, right = len - 1;
    while (left < right) {
        while (left != right && arr[left] < pivot) {
            left++;
        }
        // if (left != right)
        //     arr[right--] = arr[left];
        while (left != right && arr[right] >= pivot) {
            right--;
        }
        // if (left != right)
        //     arr[left++] = arr[right];
    }
    // arr[left] = pivot;
    arr[len - 1] = arr[left];  // 找到了 pivot 的位置
    arr[left] = pivot;         // 直接与最后一个交换
}

int main() {
    int arr[] = { 2,5,6,8,4 };
    int len = sizeof(arr) / sizeof(arr[0]);
    findIndex(arr, len);
    for (size_t i = 0; i < len; i++) {
        printf("%-3d", arr[i]);
    }

    return 0;
}