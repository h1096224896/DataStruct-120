#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 双向冒泡排序
// 从左到右找到最大值，从右到左找到最小值
// 交替进行
void DoubleBubbleSort(int *arr, int len)
{
    int left = 0;  // 左边界
    int right = len - 1;  // 右边界
    int i; 
    int temp;
    while (left < right)
    {
        for (i = left; i < right; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
        right--;
        for (i = right; i > left; i--)
        {
            if (arr[i] < arr[i - 1])
            {
                temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
            }
        }
        left++;
    }
}

int main() {
    int arr[] = { 23, 12, 45, 2,2, 67, 34, 89, 12, 34 };
    int len = sizeof(arr) / sizeof(arr[0]);
    DoubleBubbleSort(arr, len);
    for (size_t i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}