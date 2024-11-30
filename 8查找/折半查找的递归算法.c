#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 递归折半查找
int binSearch(int arr[], int low, int high, int num) {
    if (low > high) // 递归结束条件
        return 0;
    int mid = (low + high) / 2;
    if (arr[mid] == num)   // 找到元素
        return 1;
    else if (arr[mid] < num) 
        return binSearch(arr, mid + 1, high, num);  // 递归查找右半部分
    else 
        return binSearch(arr, low, mid - 1, num);  // 递归查找左半部分
}

int main() {
    int arr[] = { 10,20,30 };
    int len = sizeof(arr) / sizeof(arr[0]);
    if (binSearch(arr, 0, len - 1, 30)) {
        printf("找到元素。\n");
    }
    else {
        printf("找不到该元素。\n");
    }
    return 0;
}