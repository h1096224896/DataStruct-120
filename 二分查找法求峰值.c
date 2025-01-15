#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 二分查找法求峰值
int findPeakElement(int* nums, int numsSize) {
    int left = 0, right = numsSize - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[mid + 1])
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

int main()
{
    int arr[] = { 1, 2, 1, 3, 5, 6, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", findPeakElement(arr, n));
    return 0;
}