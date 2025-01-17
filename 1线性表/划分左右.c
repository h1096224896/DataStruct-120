#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 函数定义: 调整数组，使左边是小于等于基准的数，右边是大于等于基准的数
void fun(int* arr, int base, int len) {
    int low = 0;
    int high = len - 1;
    while (low < high) {
        while (arr[high] >= base && low < high)  // 从右向左找到第一个小于基准的数
            high--;
        while (arr[low] <= base && low < high)  // 从左向右找到第一个大于基准的数
            low++;
        if (low < high) {  // 交换两个数
            int temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
        }
    }
}

int main() {
    int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = arc4random() % 100;
    }
    for (int i = 0; i < 10; i++) {
        printf("%-3d", *(arr + i));
    }
    int base;
    printf("请输入比较基准:");
    scanf("%d", &base);
    fun(arr, base, 10);
    for (int i = 0; i < 10; i++) {
        printf("%-3d", *(arr + i));
    }
    return 0;
}