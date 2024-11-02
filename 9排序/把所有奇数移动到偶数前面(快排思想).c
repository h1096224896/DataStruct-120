#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 已知线性表按顺序存储, 且每个元素都是不相同的整数, 请编写一个函数, 将所有奇数移动到所有偶数的前面
// 例如: 1 2 3 4 5 6 7 8 9 -> 1 9 3 7 5 | 6 4 2 8
void MoveOddToEven(int* arr, int len) {
    int left = 0;  // 从左右两边开始遍历
    int right = len - 1;  // 从左右两边开始遍历
    int temp;
    while (left < right) {
        while (left < right && arr[left] % 2 != 0) {  // 只要是奇数就继续往后走
            left++;
        }
        while (left < right && arr[right] % 2 == 0) {  // 只要是偶数就继续往前走
            right--;
        }
        if (left < right) {
            temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
    }
}

int main() {
    int arr[] = { 23, 12, 45, 2,2, 67, 34, 89, 12, 34 };
    int len = sizeof(arr) / sizeof(arr[0]);
    MoveOddToEven(arr, len);
    for (size_t i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}